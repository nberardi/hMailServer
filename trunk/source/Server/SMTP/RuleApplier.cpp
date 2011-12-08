// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "./RuleApplier.h"

#include "RuleResult.h"

#include "../Common/BO/Rule.h"
#include "../Common/BO/Rules.h"
#include "../Common/BO/RuleCriterias.h"
#include "../Common/BO/RuleActions.h"
#include "../Common/BO/RuleAction.h"
#include "../Common/BO/MessageData.h"
#include "../Common/BO/Message.h"
#include "../Common/BO/Account.h"
#include "../Common/BO/MessageRecipients.h"
#include "../Common/Cache/CacheContainer.h"
#include "../Common/Util/Time.h"
#include "../Common/Util/Utilities.h"
#include "../Common/Util/RegularExpression.h"

#include "../Common/Persistence/PersistentMessage.h"

#include "RecipientParser.h"

#include "SMTPConfiguration.h"

// Scripting includes
#include "../Common/Application/ScriptingHost/ScriptServer.h"
#include "../Common/Application/ScriptingHost/ScriptObjectContainer.h"
#include "../Common/Application/ScriptingHost/Result.h"

#include "../Common/BO/MessageRecipient.h"


#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   RuleApplier::RuleApplier(void)
   {
   }

   RuleApplier::~RuleApplier(void)
   {
   }

   void
   RuleApplier::ApplyRules(boost::shared_ptr<Rules> pRules, boost::shared_ptr<const Account> account, boost::shared_ptr<Message> pMessage, RuleResult &ruleResult)
   {
      LOG_DEBUG(_T("Applying rules"));

      if (pRules->GetCount() == 0)
      {
         return;
      }

      boost::shared_ptr<MessageData> pMessageData = boost::shared_ptr<MessageData>(new MessageData());
      pMessageData->LoadFromMessage(account, pMessage);
      
      m_iRuleAccountID = pRules->GetAccountID();

      for (int i = 0; i < pRules->GetCount(); i++)
      {
         boost::shared_ptr<Rule> pRule = pRules->GetItem(i);

         if (pRule && pRule->GetActive())
         {
            bool bContinueRuleProcessing = true;
            if (_ApplyRule(pRule, account, pMessageData, bContinueRuleProcessing, ruleResult))
            {
               // The rule matched. We should return here.
               return;
            }

            if (!bContinueRuleProcessing)
            {
               break;
            }
         }
      }
   }

   bool
   RuleApplier::_ApplyRule(boost::shared_ptr<Rule> pRule, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData, bool &bContinueRuleProcessing, RuleResult &ruleResult)
   {
      LOG_DEBUG(_T("Applying rule"));

      bool bAllRequired = pRule->GetUseAND();
      bool bDoActions = false;

      boost::shared_ptr<RuleCriterias> pCriterias = pRule->GetCriterias();
      for (int i = 0; i < pCriterias->GetCount(); i++)
      {
         boost::shared_ptr<RuleCriteria> pCriteria = pCriterias->GetItem(i);

         if (!pCriteria)
            continue;

         bool bMatch = _MessageMatchesCriteria(pCriteria, pMsgData);
         
         if (bAllRequired)
         {
            if (!bMatch)
            {
               return false;
            }

            bDoActions = true;
         }
         else
         {
            if (bMatch)
            {
               bDoActions = true;
               break;
            }
         }
      }

      if (bDoActions)
      {
         _ApplyActions(pRule, account, pMsgData, bContinueRuleProcessing, ruleResult);
      }

      return false;
   }

   void
   RuleApplier::_ApplyActions(boost::shared_ptr<Rule> pRule, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData, bool &bContinueRuleProcessing, RuleResult &ruleResult)
   {  
      boost::shared_ptr<RuleActions> pActions = pRule->GetActions();

      for (int i = 0; i < pActions->GetCount(); i++)
      {
         boost::shared_ptr<RuleAction> pAction = pActions->GetItem(i);

         if (pAction)
         {
            _ApplyAction(pRule, pAction, account, pMsgData, bContinueRuleProcessing, ruleResult);
         }
      }
   }

   void
   RuleApplier::_ApplyAction(boost::shared_ptr<Rule> pRule, boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData, bool &bContinueRuleProcessing, RuleResult &ruleResult)
   {  
      Logger::Instance()->LogDebug(_T("Performing rule action"));
      switch (pAction->GetType())
      {
      case RuleAction::Delete:  
         {
            ruleResult.SetDeleteEmail(true);

            String sDeleteRuleName;
            sDeleteRuleName.Format(_T("Rule name: %s, ID: %d"), pRule->GetName(), pRule->GetID());

            ruleResult.SetDeleteRuleName(sDeleteRuleName);
            break;
         }
      case RuleAction::MoveToIMAPFolder:
         {
            ruleResult.SetMoveToFolder(pAction->GetIMAPFolder());
            break;
         }
      case RuleAction::Forward:  
         {
            _ApplyActionForward(pAction, account, pMsgData);
            break;
         }
      case RuleAction::Reply:
         {
            _ApplyActionReply(pAction, pMsgData);
            break;
         }
      case RuleAction::ScriptFunction:
         {
            _ApplyActionScriptFunction(pAction, account, pMsgData);
            break;
         }
      case RuleAction::SetHeaderValue:
         {
            _ApplyActionSetHeader(pAction, account, pMsgData);
            break;
         }
      case RuleAction::StopRuleProcessing:
         {
            bContinueRuleProcessing = false;
            break;
         }
      case RuleAction::SendUsingRoute:
         {
            ruleResult.SetSendUsingRoute(pAction->GetRouteID());
            break;
         }
      case RuleAction::CreateCopy:  
         {
            _ApplyActionCopy(pRule, account, pMsgData);
            break;
         }
      case RuleAction::BindToAddress:
         {
            ruleResult.SetBindToAddress(pAction->GetValue());
            break;
         }
      }
   }

   void 
   RuleApplier::_ApplyActionForward(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const
   {
      if (RuleLoopCountReached(pMsgData))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5064, "RuleApplier::_ApplyActionForward", "Could not forward message. Maximum rule loop count reached.");
         return;
      }

      if (pAction->GetTo().IsEmpty())
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4225, "RuleApplier::_ApplyActionForward", "Could not forward message; empty recipient address.");
         return;
      }

      boost::shared_ptr<Message> pMsg = PersistentMessage::CopyToQueue(account, pMsgData->GetMessage());

      if (!pMsg)
         return;

      pMsg->SetState(Message::Delivering);

      boost::shared_ptr<Account> emptyAccount;

      // Increase the number of rule-deliveries made.
      String newFileName = PersistentMessage::GetFileName(emptyAccount, pMsg);

      boost::shared_ptr<MessageData> pNewMsgData = boost::shared_ptr<MessageData>(new MessageData());
      pNewMsgData->LoadFromMessage(emptyAccount, pMsg);
      pNewMsgData->IncreaseRuleLoopCount();
      pNewMsgData->Write(newFileName);
      
      // We need to update the SMTP envelope from address, if this
      // message is forwarded by a user-level account.
      boost::shared_ptr<CONST Account> pAccount = CacheContainer::Instance()->GetAccount(m_iRuleAccountID);
      if (pAccount)
         pMsg->SetFromAddress(pAccount->GetAddress());
      
      // Add new recipients
      bool recipientOK = false;
      RecipientParser recipientParser;
      recipientParser.CreateMessageRecipientList(pAction->GetTo(), pMsg->GetRecipients(), recipientOK);

      // Check that there are recipients of the letter. If not, we should skip delivery.
      if (pMsg->GetRecipients()->GetCount() == 0)
      {
         // Delete the file since the message cannot be delivered.
         FileUtilities::DeleteFile(newFileName);

         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4235, "RuleApplier::_ApplyActionForward", "Could not forward message; no recipients.");
         return;
      }

      PersistentMessage::SaveObject(pMsg);
   }

   void 
   RuleApplier::_ApplyActionCopy(boost::shared_ptr<Rule> rule, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const
   {
      if (RuleLoopCountReached(pMsgData))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5201, "RuleApplier::_ApplyActionCopy", "Could not copy message. Maximum rule loop count reached.");
         return;
      }

      boost::shared_ptr<Message> pMsg = PersistentMessage::CopyToQueue(account, pMsgData->GetMessage());
      
      if (!pMsg)
         return;

      // We've created a copy of the message, but we need to copy the recipients as well.
      // The recipients are either the full list of SMTP envelope recipients, or, if it's
      // an account level rule it's just the address of the account. To determine this, we
      // check whether the message has been connected to any account yet.
      if (pMsgData->GetMessage()->GetAccountID() > 0)
      {
         // What account is it in?
         boost::shared_ptr<const Account> recipientAccount = CacheContainer::Instance()->GetAccount(pMsgData->GetMessage()->GetAccountID());

         if (recipientAccount)
         {
            bool recipientOK = false;

            RecipientParser recipientParser;
            recipientParser.CreateMessageRecipientList(recipientAccount->GetAddress(), pMsg->GetRecipients(), recipientOK);
         }
      }
      else
      {
         // Copy the old reciopients.
         std::vector<boost::shared_ptr<MessageRecipient> >  &oldRecipients = pMsgData->GetMessage()->GetRecipients()->GetVector();

         boost_foreach(boost::shared_ptr<MessageRecipient> recipient, oldRecipients)
         {
            boost::shared_ptr<MessageRecipient> newRecipient = boost::shared_ptr<MessageRecipient >(new MessageRecipient());
            newRecipient->CopyFrom(recipient);

            pMsg->GetRecipients()->Add(newRecipient);
         }
      }

      pMsg->SetState(Message::Delivering);

      // Increase the number of rule-deliveries made.
      String newMessageFileName = PersistentMessage::GetFileName(pMsg);

      boost::shared_ptr<MessageData> pNewMsgData = boost::shared_ptr<MessageData>(new MessageData());
      pNewMsgData->LoadFromMessage(newMessageFileName, pMsg);
      pNewMsgData->IncreaseRuleLoopCount();
      pNewMsgData->SetFieldValue("X-CopyRule", rule->GetName());
      pNewMsgData->Write(newMessageFileName);

      // Check that there are recipients of the letter. If not, we should skip delivery.
      if (pMsg->GetRecipients()->GetCount() == 0)
      {
         // Delete the file since the message cannot be delivered.
         FileUtilities::DeleteFile(newMessageFileName);

         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5201, "RuleApplier::_ApplyActionCopy", "Could not copy message; no recipients.");
         return;
      }

      PersistentMessage::SaveObject(pMsg);
   }

   void 
   RuleApplier::_ApplyActionScriptFunction(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const
   {
      // Run a custom function
      String sFunctionName = pAction->GetScriptFunction();

      boost::shared_ptr<ScriptObjectContainer> pContainer = boost::shared_ptr<ScriptObjectContainer>(new ScriptObjectContainer);
      boost::shared_ptr<Result> pResult = boost::shared_ptr<Result>(new Result);
      pContainer->AddObject("HMAILSERVER_MESSAGE", pMsgData->GetMessage(), ScriptObject::OTMessage);
      pContainer->AddObject("Result", pResult, ScriptObject::OTResult);
      
      String sEventCaller = sFunctionName + "(HMAILSERVER_MESSAGE)";
      ScriptServer::Instance()->FireEvent(ScriptServer::EventCustom, sEventCaller, pContainer);

      // The script may have modified the message. We need to reload it. We could
      // do a CRC check or something similar to determine whether it has changed,
      // but performance-wise we can probably just as well reload it.
      pMsgData->LoadFromMessage(account, pMsgData->GetMessage());
   }

   void 
   RuleApplier::_ApplyActionSetHeader(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const
   {
      // Run a custom function
      String sHeader = pAction->GetHeaderName();
      String sValue = pAction->GetValue();

      pMsgData->SetFieldValue(sHeader, sValue);

      String fileName = PersistentMessage::GetFileName(account, pMsgData->GetMessage());

      pMsgData->Write(fileName);
   }

   void 
   RuleApplier::_ApplyActionReply(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<MessageData> pMsgData) const
   {
      if (RuleLoopCountReached(pMsgData))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5065, "RuleApplier::_ApplyActionReply", "Could not reply message. Maximum rule loop count reached.");
         return;
      }

      String sReplyRecipientAddress  = pMsgData->GetMessage()->GetFromAddress();

      if (sReplyRecipientAddress.IsEmpty())
      {
         // We need a recipient address to be able to
         // send the message..
         return;
      }

      boost::shared_ptr<Account> emptyAccount;

      // Send a copy of this email.
      boost::shared_ptr<Message> pMsg = boost::shared_ptr<Message>(new Message());
      pMsg->SetState(Message::Delivering);
      
      String newMessageFileName = PersistentMessage::GetFileName(pMsg);

      boost::shared_ptr<MessageData> pNewMsgData = boost::shared_ptr<MessageData>(new MessageData());
      pNewMsgData->LoadFromMessage(newMessageFileName, pMsg);
      pNewMsgData->SetReturnPath("");
      pNewMsgData->GenerateMessageID();
      pNewMsgData->SetTo(sReplyRecipientAddress);
      pNewMsgData->SetFrom(pAction->GetFromName() + " <" + pAction->GetFromAddress() + ">");
      pNewMsgData->SetSubject(pAction->GetSubject());
      pNewMsgData->SetBody(pAction->GetBody());
      pNewMsgData->SetSentTime(Time::GetCurrentMimeDate());
      pNewMsgData->IncreaseRuleLoopCount();
      pNewMsgData->Write(newMessageFileName);

      // Add recipients.
      bool recipientOK = false;
      RecipientParser recipientParser;
      recipientParser.CreateMessageRecipientList(sReplyRecipientAddress, pMsg->GetRecipients(), recipientOK);

      PersistentMessage::SaveObject(pMsg);

   }

   bool
   RuleApplier::_MessageMatchesCriteria(boost::shared_ptr<RuleCriteria> pCriteria, boost::shared_ptr<MessageData> pMsgData) const
   {
      String sFieldValue;
      if (pCriteria->GetUsePredefined())
      {
         switch (pCriteria->GetPredefinedField())
         {
         case RuleCriteria::FTFrom:
            sFieldValue = pMsgData->GetFrom();
            break;
         case RuleCriteria::FTTo:
            sFieldValue = pMsgData->GetTo();
            break;
         case RuleCriteria::FTCC:
            sFieldValue = pMsgData->GetCC();
            break;
         case RuleCriteria::FTSubject:
            sFieldValue = pMsgData->GetSubject();
            break;
         case RuleCriteria::FTBody:
            sFieldValue = pMsgData->GetBody() + pMsgData->GetHTMLBody();
            break;
         case RuleCriteria::FTMessageSize:
            sFieldValue.Format(_T("%d"), pMsgData->GetSize());
            break;
         case RuleCriteria::FTDeliveryAttempts:
            sFieldValue.Format(_T("%u"), pMsgData->GetMessage()->GetNoOfRetries() + 1);
            break;
         case RuleCriteria::FTRecipientList:
            {
               boost::shared_ptr<Message> pMessage = pMsgData->GetMessage();
               std::vector<boost::shared_ptr<MessageRecipient> > vecRecipients = pMessage->GetRecipients()->GetVector();
               std::vector<boost::shared_ptr<MessageRecipient> >::iterator iterRecipient = vecRecipients.begin();

               while (iterRecipient != vecRecipients.end())
               {
                  if (!sFieldValue.IsEmpty())
                     sFieldValue += ";";

                  sFieldValue += (*iterRecipient)->GetAddress();
                  iterRecipient++;
               }

               break;
            }
         }
      }
      else
      {
         sFieldValue = pMsgData->GetFieldValue(pCriteria->GetHeaderField());
      }

      String matchValue = pCriteria->GetMatchValue();


      return TestMatch(matchValue, pCriteria->GetMatchType(), sFieldValue);
   }

   bool 
   RuleApplier::TestMatch(String matchValue, RuleCriteria::MatchType matchType, String testValue)
   {
      switch (matchType)
      {
      case RuleCriteria::Equals:
         {
            if (matchValue.CompareNoCase(testValue) == 0)
               return true;
            else
               return false;
         }
      case RuleCriteria::NotEquals:
         {
            if (matchValue.CompareNoCase(testValue) != 0)
               return true;
            else
               return false;
         }
      case RuleCriteria::Contains:
         {
            if (testValue.FindNoCase(matchValue) >= 0)
               return true;
            else
               return false;
         }
      case RuleCriteria::NotContains:
         {
            if (testValue.FindNoCase(matchValue) == -1)
               return true;
            else
               return false;
         }

      case RuleCriteria::LessThan:
         {
            testValue.Replace(_T(","), _T("."));
            matchValue.Replace(_T(","), _T("."));

            double iFieldValue =  _tstof(testValue);
            double iMatchValue = _tstof(matchValue);

            if (iMatchValue > iFieldValue)
               return true;
            else
               return false;
         }
      case RuleCriteria::GreaterThan:
         {
            testValue.Replace(_T(","), _T("."));
            matchValue.Replace(_T(","), _T("."));

            double iFieldValue = _tstof(testValue);
            double iMatchValue = _tstof(matchValue);

            if (iMatchValue < iFieldValue)
               return true;
            else
               return false;
         }
      case RuleCriteria::MatchesRegEx:
         {
            if (RegularExpression::TestExactMatch(matchValue, testValue))
               return true;
            else
               return false;
         }
      case RuleCriteria::Wildcard:
         {
            if (StringParser::WildcardMatchNoCase(matchValue, testValue))
               return true;
            else
               return false;

         }
      default:
         {
            assert(0); // unknown match type?
            return false;
         }


      }

      return false;
   }

   bool
   RuleApplier::RuleLoopCountReached(boost::shared_ptr<MessageData> pMsgData)
   {
      int iCurrProcessCount = pMsgData->GetRuleLoopCount();
      int iMaxAllowed = Configuration::Instance()->GetSMTPConfiguration()->GetRuleLoopLimit();

      if (iCurrProcessCount < iMaxAllowed)
         return false;

      return true;
   }

}

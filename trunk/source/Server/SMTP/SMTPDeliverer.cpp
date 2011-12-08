// Copyright (c) 2006 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "SMTPDeliverer.h"

#include "../common/Application/ObjectCache.h"

#include "../common/AntiVirus/AntiVIrusCOnfiguration.h"
#include "../common/AntiVirus/VirusScanner.h"

#include "../common/BO/MessageRecipient.h"
#include "../common/BO/MessageRecipients.h"
#include "../common/BO/MessageData.h"
#include "../common/Cache/CacheContainer.h"
#include "../common/Cache/InboxIDCache.h"
#include "../common/Util/Time.h"
#include "../common/Util/ServerStatus.h"
#include "../common/Util/MailerDaemonAddressDeterminer.h"
#include "../common/TCPIP/TCPConnection.h"

#include "../common/Util/Utilities.h"
#include "../common/Util/Event.h"
#include "../common/Util/MessageAttachmentStripper.h"
#include "../common/Util/MessageUtilities.h"

#include "../common/EventHandlers/Events.h"

#include "../common/Persistence/PersistentMessage.h"
#include "../common/Persistence/PersistentIMAPFolder.h"
#include "../common/Persistence/PersistentAccount.h"
#include "../common/Persistence/PersistentMessageRecipient.h"
#include "../common/Persistence/PersistentServerMessage.h"

#include "../common/BO/IMAPFolder.h"
#include "../common/BO/Domain.h"
#include "../common/BO/Account.h"
#include "../common/BO/ServerMessages.h"

#include "LocalDelivery.h"
#include "ExternalDelivery.h"
#include "SMTPConfiguration.h"
#include "SMTPVirusNotifier.h"
#include "RuleApplier.h"
#include "RuleResult.h"
#include "RecipientParser.h"
#include "MirrorMessage.h"

#include "../Common/Util/AWstats.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   SMTPDeliverer::SMTPDeliverer()
   {
      
   }

   SMTPDeliverer::~SMTPDeliverer()
   {
   }

   void
   SMTPDeliverer::DeliverMessage(boost::shared_ptr<Message> pMessage)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Submits the next message in the database. 
   //---------------------------------------------------------------------------()
   {
      LOG_DEBUG("Delivering message...");

      if (!pMessage)
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4217, "SMTPDeliverer::DeliverMessage()", "The message to deliver was not given.");
         return;
      }

      // Fetch the message ID before we delete the message and it's reset.
      __int64 messageID = pMessage->GetID();

      String sSendersIP;
      RuleResult globalRuleResult;
      if (!_PreprocessMessage(pMessage, sSendersIP, globalRuleResult))
      {
         // Message delivery was aborted during preprocessing.
         return;
      }

      vector<String> saErrorMessages;

      // Perform deliver to local recipients.
      LocalDelivery localDeliverer(sSendersIP, pMessage, globalRuleResult);
      bool messageReused = localDeliverer.Perform(saErrorMessages);

      bool messageRescheduled = false;
      if (pMessage->GetRecipients()->GetCount() > 0)
      {
         // Perform deliveries to external recipients.
         ExternalDelivery externalDeliverer(sSendersIP, pMessage, globalRuleResult);
         messageRescheduled = externalDeliverer.Perform(saErrorMessages);
      }

      // If an error has occurred, now is the time to send an error
      // message back to the author of the email message.
      if (saErrorMessages.size() > 0)
         _SubmitErrorLog(pMessage, saErrorMessages);

      // Unless the message has been re-used, or has been rescheduled for
      // later delivery, we should delete it now.
      bool deleteMessageNow = !messageReused && !messageRescheduled;
      if (deleteMessageNow)
      {
         // Check that we haven't reused this message before we delete it.
         if (pMessage->GetAccountID() > 0)
         {
            String errorMessage;
            errorMessage.Format(_T("Attempting to delete message %I64d even though it's been delivered to user account %I64d ."), messageID, pMessage->GetAccountID());
            ErrorManager::Instance()->ReportError(ErrorManager::High, 5208, "SMTPDeliverer::DeliverMessage", errorMessage);
            return;
         }

         PersistentMessage::DeleteObject(pMessage);   
      }

      String logText;
      logText.Format(_T("SMTPDeliverer - Message %I64d: Message delivery thread completed."), messageID);
      LOG_APPLICATION(logText);

      return;   
   }

   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Performs preprocessing of the message. Checks that the file exists, runs
   // global rules, virus scanning and mirroring.
   //
   // Returns true if delivery should continue. False if it should be aborted.
   //---------------------------------------------------------------------------()
   bool
   SMTPDeliverer::_PreprocessMessage(boost::shared_ptr<Message> pMessage, String &sendersIP, RuleResult &globalRuleResult)
   {
      // Before we do anything else, check that the message file exists. If the file
      // does not exist, there is nothing to deliver. So if the file does not exist,
      // delete pMessage from the database and report in the application log.
      const String messageFileName = PersistentMessage::GetFileName(pMessage);
      if (!FileUtilities::Exists(messageFileName))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5006, "SMTPDeliverer::DeliverMessage()", "Message " + StringParser::IntToString(pMessage->GetID()) + " could not be delivered since the data file does not exist.");
         PersistentMessage::DeleteObject(pMessage);

         return false;
      }

      if (pMessage->GetRecipients()->GetCount() == 0)
      {
         // No remaining recipients.
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5007, "SMTPDeliverer::DeliverMessage()", "Message " + StringParser::IntToString(pMessage->GetID()) + " could not be delivered. No remaining recipients. File: " + messageFileName);

         PersistentMessage::DeleteObject(pMessage);
         return false;
      }

      if (AWStats::GetEnabled())
      {
         sendersIP = MessageUtilities::GetSendersIP(pMessage);
      }

      // Create recipient list.
      String sRecipientList = pMessage->GetRecipients()->GetCommaSeperatedRecipientList();

      String sMessage = Formatter::Format("SMTPDeliverer - Message {0}: Delivering message from {1} to {2}. File: {3}",
                                                pMessage->GetID(), pMessage->GetFromAddress(), sRecipientList, messageFileName);

      LOG_APPLICATION(sMessage);

      // Run the first event in the delivery chain
      if (!Events::FireOnDeliveryStart(pMessage))
      {
         _LogAwstatsMessageRejected(sendersIP, pMessage, "Delivery cancelled by OnDeliveryStart-event");
         return false;
      }

      if (pMessage->GetRecipients()->GetCount() == 0)
      {
         vector<String> saErrorMessages;
         _SubmitErrorLog(pMessage, saErrorMessages);
         PersistentMessage::DeleteObject(pMessage);
         return false;
      }

      // Run virus protection.
      if (!_RunVirusProtection(pMessage))
      {
         _LogAwstatsMessageRejected(sendersIP, pMessage, "Message delivery cancelled during virus scanning");
         return false;
      }

      // Apply rules on this message.
      if (!_RunGlobalRules(pMessage, globalRuleResult))
      {
         _LogAwstatsMessageRejected(sendersIP, pMessage, "Message delivery cancelled during global rules");
         return false;
      }

      // Run the OnDeliverMessage-event
      if (!Events::FireOnDeliverMessage(pMessage))
      {
         _LogAwstatsMessageRejected(sendersIP, pMessage, "Message delivery cancelled during OnDeliverMessage-event");
         return false;
      }

      // Run mirroring
      if (pMessage->GetNoOfRetries() == 0)
      {
         MirrorMessage mirrorer(pMessage);
         mirrorer.Send();
      }

      return true;

   }


   void
   SMTPDeliverer::_SubmitErrorLog(boost::shared_ptr<Message> pOrigMessage, vector<String> &saErrorMessages)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Some of the messages was not sent to the recipient. We have to
   // send a mail back to the sender to tell him this.
   //---------------------------------------------------------------------------()
   {
      LOG_DEBUG("SD::_SubmitErrorLog");      
      if (MailerDaemonAddressDeterminer::IsMailerDaemonAddress(pOrigMessage->GetFromAddress()))
      {
         LOG_DEBUG("SD::~_SubmitErrorLog");      
         return; // Avoid bounce-bounce
      }

      if (pOrigMessage->GetFromAddress().IsEmpty())
      {
         // No sender address specified, hence no place to
         // deliver the error log.
         return;
      }

      const String fileName = PersistentMessage::GetFileName(pOrigMessage);

      boost::shared_ptr<MessageData> pMsgData = boost::shared_ptr<MessageData> (new MessageData());
      pMsgData->LoadFromMessage(fileName, pOrigMessage);

      if (RuleApplier::RuleLoopCountReached(pMsgData))
      {
         String sMessage;
         sMessage.Format(_T("Did not submit bounce message for message %I64d from %s since rule loop count was reached."), pOrigMessage->GetID(), String(pOrigMessage->GetFromAddress()));
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4404, "SMTPDeliverer::_ApplyForwarding", sMessage);

         return;
      }

      int iRuleLoopCount = pMsgData->GetRuleLoopCount();

      String sMailerDaemonAddress = MailerDaemonAddressDeterminer::GetMailerDaemonAddress(pOrigMessage);
      
      String sMessageUndeliverable;
      sMessageUndeliverable.Format(_T("%s"),Configuration::Instance()->GetServerMessages()->GetMessage("MESSAGE_UNDELIVERABLE"));
      String sErrMsg = Configuration::Instance()->GetServerMessages()->GetMessage("SEND_FAILED_NOTIFICATION");

      sErrMsg.Replace(_T("%MACRO_SENT%"), pMsgData->GetSentTime());
      sErrMsg.Replace(_T("%MACRO_SUBJECT%"), pMsgData->GetSubject());

      // Ability to include original headers in undeliverable message
      // http://www.hmailserver.com/forum/viewtopic.php?f=2&t=19635
      sErrMsg.Replace(_T("%MACRO_ORIGINAL_HEADER%"), pMsgData->GetHeader());      

      String sCollectedErrors;
      for (unsigned int i=0;i<saErrorMessages.size();i++)
         sCollectedErrors += saErrorMessages[i];

      sErrMsg.Replace(_T("%MACRO_RECIPIENTS%"), sCollectedErrors);

      // Send a copy of this email.
      boost::shared_ptr<Message> pMsg = boost::shared_ptr<Message>(new Message());
      pMsg->SetState(Message::Delivering);
      pMsg->SetFromAddress("");

      const String newFileName = PersistentMessage::GetFileName(pMsg);

      boost::shared_ptr<MessageData> pNewMsgData = boost::shared_ptr<MessageData>(new MessageData());
      pNewMsgData->LoadFromMessage(newFileName, pMsg);

      // Required headers
      pNewMsgData->SetReturnPath("");
      pNewMsgData->GenerateMessageID();
      pNewMsgData->SetSentTime(Time::GetCurrentMimeDate());

      // Optional headers
      pNewMsgData->SetFrom(sMailerDaemonAddress);
      pNewMsgData->SetTo(pOrigMessage->GetFromAddress());
      pNewMsgData->SetSubject(sMessageUndeliverable + ": " + pMsgData->GetSubject());
      pNewMsgData->SetBody(sErrMsg);
      pNewMsgData->SetRuleLoopCount(iRuleLoopCount + 1);

      // Write message data
      pNewMsgData->Write(PersistentMessage::GetFileName(pMsg));

      // Add recipients
      bool recipientOK = false;
      RecipientParser recipientParser;
      recipientParser.CreateMessageRecipientList(pOrigMessage->GetFromAddress(), pMsg->GetRecipients(), recipientOK);

      if (pMsg->GetRecipients()->GetCount() > 0)
         // Save message
         PersistentMessage::SaveObject(pMsg);

      LOG_DEBUG("SD::~_SubmitErrorLog"); 

   }

   
   bool
   SMTPDeliverer::_HandleInfectedMessage(boost::shared_ptr<Message> pMessage, const String &virusName)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Called if a virus is found in an email message. Checks in the configuration
   // what we should do with infected messages and does just that.
   //---------------------------------------------------------------------------()
   {
      AntiVirusConfiguration &antiVirusConfig = Configuration::Instance()->GetAntiVirusConfiguration();

      if (antiVirusConfig.AVAction() == AntiVirusConfiguration::ActionDelete)
      {
         // The message should be deleted.

         // Should we notify the recipient?
         if (antiVirusConfig.AVNotifyReceiver())
         {
            // Notify every receiver of the email.
            vector<boost::shared_ptr<MessageRecipient> > &vecRecipients = pMessage->GetRecipients()->GetVector();
            vector<boost::shared_ptr<MessageRecipient> >::iterator iterRecipient = vecRecipients.begin();

            while (iterRecipient != vecRecipients.end())
            {
               SMTPVirusNotifier::CreateMessageDeletedNotification(pMessage, (*iterRecipient)->GetAddress());
               
               iterRecipient++;
            }
         }

         if (antiVirusConfig.AVNotifySender())
            SMTPVirusNotifier::CreateMessageDeletedNotification(pMessage, pMessage->GetFromAddress());

         String logMessage = Formatter::Format("SMTPDeliverer - Message {0}: Message deleted (contained virus {1}).", 
            pMessage->GetID(), virusName);

         LOG_APPLICATION(logMessage);

         PersistentMessage::DeleteObject(pMessage);
         
         return false; // do not continue delivery

      }
      else if (antiVirusConfig.AVAction() == AntiVirusConfiguration::ActionStripAttachments)
      {
         boost::shared_ptr<MessageAttachmentStripper> pStripper = boost::shared_ptr<MessageAttachmentStripper>(new MessageAttachmentStripper());

         pStripper->Strip(pMessage);

         String logMessage = Formatter::Format("SMTPDeliverer - Message {0}: Message attachments stripped (contained virus {1}).", 
            pMessage->GetID(), virusName);

         LOG_APPLICATION(logMessage);

         return true; // continue delivery
      }

      // Weird configuration?
      assert(0);
      
      return false;
   }

   bool 
   SMTPDeliverer::_RunVirusProtection(boost::shared_ptr<Message> pMessage)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Runs virus scanning. If a virus is found, it's handled according to the
   // configuration. (Either the attachments are stripped, or the entire message
   // is deleted.
   //---------------------------------------------------------------------------()
   {

      // First check for blocked attachments.
      if (Configuration::Instance()->GetAntiVirusConfiguration().GetEnableAttachmentBlocking())      
      {
         VirusScanner::BlockAttachments(pMessage);
      }

      if (!pMessage->GetFlagVirusScan())
         return true;

      if (!VirusScanner::GetVirusScanningEnabled())
         return true;

      // Virus scanning
      String virusName;
      if (VirusScanner::Scan(pMessage, virusName))
      {
         // Virus found.
         ServerStatus::Instance()->OnVirusRemoved();

         if (!_HandleInfectedMessage(pMessage, virusName))
            return false;
      }      

      return true;

   }

   bool 
   SMTPDeliverer::_RunGlobalRules(boost::shared_ptr<Message> pMessage, RuleResult &ruleResult)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Performs global rules. We will do this on every retry of the message.
   //---------------------------------------------------------------------------()
   {
      boost::shared_ptr<RuleApplier> pRuleApplier = boost::shared_ptr<RuleApplier>(new RuleApplier);
      boost::shared_ptr<Account> emptyAccount;
      pRuleApplier->ApplyRules(ObjectCache::Instance()->GetGlobalRules(), emptyAccount, pMessage, ruleResult);

      if (ruleResult.GetDeleteEmail())
      {
         String sDeleteRuleName = ruleResult.GetDeleteRuleName();

         String sMessage;
         sMessage.Format(_T("SMTPDeliverer - Message %I64d: ")
            _T("Message deleted. Action was taken by a global rule (%s). "),
            pMessage->GetID(), 
            sDeleteRuleName);

         LOG_APPLICATION(sMessage);

         PersistentMessage::DeleteObject(pMessage);
         return false;
      }

      return true;
   }

   void 
   SMTPDeliverer::_LogAwstatsMessageRejected(const String &sSendersIP, boost::shared_ptr<Message> pMessage, const String &sReason)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // If awstats logging is enabled, this function goes through all the recipients
   // of the message, and logs to the awstats log that they have been rejected.
   // This is used if a message is rejected after it has been transferred from the
   // client to the server.
   //---------------------------------------------------------------------------()
   {
      // Check that message exists, and that the awstats log is enabled.
      if (!pMessage || !AWStats::GetEnabled())
         return;

      // Go through the recipients and log one row for each of them.
      String sFromAddress = pMessage->GetFromAddress();     

      const std::vector<boost::shared_ptr<MessageRecipient> > vecRecipients = pMessage->GetRecipients()->GetVector();
      std::vector<boost::shared_ptr<MessageRecipient> >::const_iterator iterRecipient = vecRecipients.begin();
      while (iterRecipient != vecRecipients.end())
      {
         String sRecipientAddress = (*iterRecipient)->GetAddress();

         // Log the error message
         AWStats::LogDeliveryFailure(sSendersIP, pMessage->GetFromAddress(), sRecipientAddress,  550);
         Events::FireOnDeliveryFailed(pMessage, sSendersIP, sRecipientAddress, sReason);

         iterRecipient++;
      }

   }


}



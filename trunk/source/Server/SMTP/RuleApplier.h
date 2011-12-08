// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "../Common/BO/RuleCriteria.h"
#include "RuleResult.h"

namespace HM
{

   class Message;
   class Rules;
   class Rule; 
   class RuleCriteria;
   class MessageData;
   class RuleAction;
   class RuleResult;
   
   class RuleApplier
   {
   public:
      RuleApplier(void);
      ~RuleApplier(void);

      void ApplyRules(boost::shared_ptr<Rules> pRules, boost::shared_ptr<const Account> account, boost::shared_ptr<Message> pMessage, RuleResult &ruleResult);

      static bool TestMatch(String matchValue, RuleCriteria::MatchType matchType, String testValue);

      static bool RuleLoopCountReached(boost::shared_ptr<MessageData> pMsgData);

   private:

      // Apply one rule to the message.
      bool _ApplyRule(boost::shared_ptr<Rule> pRule, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData, bool &bContinueRuleProcessing, RuleResult &ruleResult);

      // Do the actions for the message.
      void _ApplyActions(boost::shared_ptr<Rule> pRule, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData, bool &bContinueRuleProcessing, RuleResult &ruleResult);

      // Do the action
      void _ApplyAction(boost::shared_ptr<Rule> pRule, boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData, bool &bContinueRuleProcessing, RuleResult &ruleResult);

      // Check wether pMessage matches pCriteria.
      bool _MessageMatchesCriteria(boost::shared_ptr<RuleCriteria> pCriteria, boost::shared_ptr<MessageData> pMsgData) const;
      
      // Actions
      void _ApplyActionForward(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const;
      void _ApplyActionCopy(boost::shared_ptr<Rule> rule, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const;
      void _ApplyActionReply(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<MessageData> pMsgData) const;
      void _ApplyActionScriptFunction(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const;
      void _ApplyActionSetHeader(boost::shared_ptr<RuleAction> pAction, boost::shared_ptr<const Account> account, boost::shared_ptr<MessageData> pMsgData) const;

      ;

   private:

      __int64 m_iRuleAccountID;
      
   };
}
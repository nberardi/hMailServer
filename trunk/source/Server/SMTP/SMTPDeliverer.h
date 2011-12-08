// Copyright (c) 2006 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;
   class MessageRecipient;
   class Account;
   class MessageData;
   class RuleResult;
   class ServerInfo;

   class SMTPDeliverer
   {
   public:
	   SMTPDeliverer();
	   virtual ~SMTPDeliverer();

      static void DeliverMessage(boost::shared_ptr<Message> pMessage);

   private:

      static bool _PreprocessMessage(boost::shared_ptr<Message> pMessage, String &sendersIP, RuleResult &ruleResult);

      static bool _RunVirusProtection(boost::shared_ptr<Message> pMessage);
      static bool _RunGlobalRules(boost::shared_ptr<Message> pMessage, RuleResult &ruleResult);

      static void _DeliverToLocalAccounts(const String &sSendersIP, boost::shared_ptr<Message> pMessage, vector<String> &saErrorMessages, const RuleResult &globalRuleResult, bool &messageReused);
      
      
      
      
      static void _SubmitErrorLog(boost::shared_ptr<Message> pOrigMessage, vector<String> &saErrorMessages);

      static bool _HandleInfectedMessage(boost::shared_ptr<Message> pMessage, const String &virusName);
      
      

      static void _LogAwstatsMessageRejected(const String &sSendersIP, boost::shared_ptr<Message> pMessage, const String &sReason);

      // Account-level tasks
      static void _DeliverToLocalAccount(boost::shared_ptr<Account> pAccount, boost::shared_ptr<Message> pMessage, int iNoOfRecipients, const RuleResult &globalRuleResult, vector<String> &saErrorMessages, const String &sSendersIP, const String &sOriginalAddress, bool &messageReused);

      static bool _RunAccountRules(boost::shared_ptr<Account> pAccount, boost::shared_ptr<Message> pMessage, RuleResult &accountRuleResult);
      static boost::shared_ptr<Message> CreateAccountLevelMessage(boost::shared_ptr<Message> pOriginalMessage, boost::shared_ptr<Account> pRecipientAccount, bool reuseMessage, const String &sOriginalAddress);

      
      
      
      

      static bool _LocalDeliveryPreProcess(boost::shared_ptr<Message> originalMessage, boost::shared_ptr<Account> account, boost::shared_ptr<Message> pMessage, const String &sOriginalAddress, vector<String> &saErrorMessages, const RuleResult &globalRuleResult);
   };
}
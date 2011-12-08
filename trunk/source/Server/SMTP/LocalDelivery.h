// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;
   class RuleResult;

   class LocalDelivery
   {
   public:
      LocalDelivery(const String &sSendersIP, boost::shared_ptr<Message> message, const RuleResult &globalRuleResult);
      ~LocalDelivery(void);

      bool Perform(vector<String> &saErrorMessages);

   private:
      
      void _DeliverToLocalAccount(boost::shared_ptr<const Account> account, int iNoOfRecipients, vector<String> &saErrorMessages, const String &sOriginalAddress, bool &messageReused);
      bool _LocalDeliveryPreProcess(boost::shared_ptr<const Account> account, boost::shared_ptr<Message> accountLevelMessage, const String &sOriginalAddress, vector<String> &saErrorMessages);
      bool _AddTraceHeaders(boost::shared_ptr<const Account> account, boost::shared_ptr<Message> pMessage, const String &sOriginalAddress);
      void _SendAutoReplyMessage(boost::shared_ptr<const Account> pAccount, boost::shared_ptr<Message> pMessage);
      bool _RunAccountRules(boost::shared_ptr<const Account> pAccount, boost::shared_ptr<Message> pMessage, RuleResult &accountRuleResult);
      bool _CheckAccountQuotas(boost::shared_ptr<const Account> pAccount, vector<String> &saErrorMessages);

      boost::shared_ptr<Message>  _CreateAccountLevelMessage(boost::shared_ptr<Message> pOriginalMessage, boost::shared_ptr<const Account> pRecipientAccount, bool reuseMessage, const String &sOriginalAddress);

      const String &_sendersIP;
      const boost::shared_ptr<Message> _originalMessage;
      const RuleResult &_globalRuleResult;

   };
}
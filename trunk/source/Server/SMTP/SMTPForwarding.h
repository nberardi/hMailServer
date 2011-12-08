// Copyright (c) 2006 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Account;
   class Message;
   class MessageData;

   class SMTPForwarding
   {
   public:

      bool PerformForwarding(boost::shared_ptr<const Account> pRecipientAccount, boost::shared_ptr<Message> pOriginalMessage);


   };
}
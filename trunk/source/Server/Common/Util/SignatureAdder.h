// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once


namespace HM
{
   class Message;
   class Domain;
   class MessageData;
   
   class SignatureAdder
   {
   public:
	   SignatureAdder();
      virtual ~SignatureAdder();

      bool SetSignature(boost::shared_ptr<Message> pMessage, 
                        boost::shared_ptr<const Domain> pSenderDomain, 
                        boost::shared_ptr<const Account> pSenderAccount,
                        boost::shared_ptr<MessageData> &pMessageData);
      // Sets the signature of the message, based on the signature in the account
      // settings and domain settings.

      
   private:

      bool _GetMessageIsReply(boost::shared_ptr<MessageData> &pMessageData);
      bool _GetMessageIsLocal(boost::shared_ptr<Message> pMessage);
   

   };
}


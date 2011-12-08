// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;
   class Result;
   class FetchAccount;

   class Events
   {
   public:
      Events(void);
      ~Events(void);

      static bool FireOnDeliverMessage(boost::shared_ptr<Message> pMessage);
      static bool FireOnDeliveryStart(boost::shared_ptr<Message> pMessage);
      static void FireOnDeliveryFailed(boost::shared_ptr<Message> pMessage, const String &sSendersIP, const String &sRecipient, const String &sErrorMessage);
         
      static boost::shared_ptr<Result> FireOnExternalAccountDownload(boost::shared_ptr<FetchAccount> fetchAccount, boost::shared_ptr<Message> pMessage, const String &sRemoteUID);
   };

}
// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;

   class MirrorMessage
   {
   public:
      MirrorMessage(boost::shared_ptr<Message> message);
      ~MirrorMessage(void);

      void Send();

   private:

      boost::shared_ptr<Message> _message;

   };
}
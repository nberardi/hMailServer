// Copyright (c) 2005 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "..\Common\Threading\Task.h"

namespace HM
{
   class Message;

   class DeliveryTask : public Task
   {
   public:
      DeliveryTask(boost::shared_ptr<Message> pMessage);
      ~DeliveryTask(void);

      virtual void DoWork();
      virtual void StopWork();
   private:
      
      boost::shared_ptr<Message> m_pMessage;
   };
}
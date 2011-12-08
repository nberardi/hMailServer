// Copyright (c) 2005 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com
// Created 2005-07-21

#pragma once

#include "WorkQueue.h"

namespace HM
{
   class WorkQueue;
   class Task;

   class WorkQueueManager : public Singleton<WorkQueueManager>
   {
   public:
      WorkQueueManager(void);
      ~WorkQueueManager(void);

      int CreateWorkQueue(int iMaxSimultaneous, const String &sQueueName, WorkQueue::QueueType qtType);
      void RemoveQueue(const String &sQueueName);

      void AddTask(int iQueueID, boost::shared_ptr<Task> pTask);

      boost::shared_ptr<WorkQueue> GetQueue(const String &sQueueName);

   private:

      std::map<int, boost::shared_ptr<WorkQueue> >::iterator _GetQueueIterator(const String &sQueueName);

      CriticalSection m_csWorkQueues;
      std::map<int, boost::shared_ptr<WorkQueue> > m_mapWorkQueues;
     
   };
}
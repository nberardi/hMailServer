// Copyright (c) 2008 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com
// Created 2008-08-12

#include "StdAfx.h"
#include "IOOperationQueue.h"
#include "IOOperation.h"

namespace HM
{
   IOOperationQueue::IOOperationQueue()
   {
      
   }

   IOOperationQueue::~IOOperationQueue(void)
   {

   }

   void
   IOOperationQueue::Push(shared_ptr<IOOperation> operation)
   {
      CriticalSectionScope scope(_criticalSection);

      _queueOperations.push_back(operation);
   }

   void
   IOOperationQueue::Pop(IOOperation::OperationType type)
   {
      CriticalSectionScope scope(_criticalSection);

      if (_ongoingOperations.size() == 0)
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Critical, 5131, "IOOperationQueue::Pop()", "Trying to pop operation list.");
         return;
      }

      std::vector<shared_ptr<IOOperation >>::iterator iter = _ongoingOperations.begin();
      std::vector<shared_ptr<IOOperation >>::iterator iterEnd = _ongoingOperations.end();

      for (; iter != iterEnd; iter++)
      {
         shared_ptr<IOOperation> oper = (*iter);

         if (oper->GetType() == type)
         {
            _ongoingOperations.erase(iter);
            return;
         }

      }

      ErrorManager::Instance()->ReportError(ErrorManager::Critical, 5131, "IOOperationQueue::Pop()", "Trying to remove non-existant item from operation list.");
   }

   bool 
   IOOperationQueue::ContainsQueuedSendOperation()
   {
      CriticalSectionScope scope (_criticalSection);

      if (_queueOperations.empty())
         return false;

      boost_foreach(shared_ptr<IOOperation> operation, _queueOperations)
      {
         if (operation->GetType() == IOOperation::BCTSend)
            return true;
      }

      return false;
   }

   shared_ptr<IOOperation>
   IOOperationQueue::Front()
   {
      CriticalSectionScope scope(_criticalSection);

      // Check that we have items to process and that 
      // we are not currently processing some.
      if (_queueOperations.empty())
      {
         shared_ptr<IOOperation> empty;
         return empty;
      }

      shared_ptr<IOOperation> nextOperation = _queueOperations.front();

      if (_ongoingOperations.size() > 0)
      {
         IOOperation::OperationType pendingType = nextOperation->GetType();

         std::vector<shared_ptr<IOOperation >>::iterator iter = _ongoingOperations.begin();
         std::vector<shared_ptr<IOOperation >>::iterator iterEnd = _ongoingOperations.end();

         for (; iter != iterEnd; iter++)
         {
            shared_ptr<IOOperation> ongoingOperation = (*iter);

            IOOperation::OperationType ongoingType = ongoingOperation->GetType();

            if (ongoingType == pendingType)
            {
               /*
                  We already have a pending operation of this type. We don't allow another one.
                  Case in point:
                  1) It does not make sense to have two Receive/Disconnect/Shutdown at the same time.
                  2) Having multiple sends at the same time might cause corruption problems, since the
                     delivery order is not guaranteed.
               */

               shared_ptr<IOOperation> empty;
               return empty;         
            }

            if (ongoingType == IOOperation::BCTSend)
            {
               if (pendingType == IOOperation::BCTDisconnect)
               {
                  /* 
                     If we're currently sending data, we cannot disconnect. 
                     Case in point:
                     A client connects to hMailServer, and there is timeout while waiting  
                     for client commands. At this time, hMailServer will send a timeout-message
                     to the client. 
                     - We must wait for the BCTSend-operation to complete, so that the client is notified. 
                     - We must not wait for the BCTReceive-operation to complete, since we might not receive one.
                  */
                  
                  shared_ptr<IOOperation> empty;
                  return empty;
               }
            }
         }
      }


      _ongoingOperations.push_back(nextOperation);

      _queueOperations.pop_front();

      return nextOperation;
   }

   
}
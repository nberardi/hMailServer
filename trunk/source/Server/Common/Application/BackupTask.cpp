// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include ".\backuptask.h"
#include "BackupExecuter.h"
#include "BackupManager.h"

namespace HM
{
   BackupTask::BackupTask(bool bDoBackup) :
      m_bDoBackup(bDoBackup)
   {
   }

   BackupTask::~BackupTask(void)
   {
   }

   void
   BackupTask::DoWork()
   {
      BackupExecuter oBE;
      if (m_bDoBackup)
      {
         oBE.StartBackup();
      }
      else
      {
         oBE.StartRestore(m_pBackup);
      }

      Application::Instance()->GetBackupManager()->OnThreadStopped();
   }

   void 
   BackupTask::StopWork()
   {
      
      
   }

   void 
   BackupTask::SetBackupToRestore(shared_ptr<Backup> pBackup)
   {
      m_pBackup = pBackup;
   }
}
// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "..\Threading\Task.h"

namespace HM
{
   class BackupTask : public Task
   {
   public:
      BackupTask(bool bDoBackup);
      ~BackupTask(void);

      virtual void DoWork();
      virtual void StopWork();

      void SetBackupToRestore(boost::shared_ptr<Backup> pBackup);

   private:

      bool m_bDoBackup;
      
      boost::shared_ptr<Backup> m_pBackup;
   };
}
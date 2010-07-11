// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "RemoveExpiredRecords.h"

#include "../Persistence/PersistentSecurityRange.h"
#include "../Persistence/PersistentLogonFailure.h"

namespace HM
{
   RemoveExpiredRecords::RemoveExpiredRecords(void)
   {
   }

   RemoveExpiredRecords::~RemoveExpiredRecords(void)
   {
   }
   
   void
   RemoveExpiredRecords::DoWork()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Remove old records from the greylist
   //---------------------------------------------------------------------------()
   {
      PersistentSecurityRange::DeleteExpired();
      
      if (Configuration::Instance()->GetAutoBanLogonEnabled())
      {
         int logonFailureMinutes = Configuration::Instance()->GetMaxLogonAttemptsWithin();
         
         PersistentLogonFailure persistentLogonFailure;
         persistentLogonFailure.ClearOldFailures(logonFailureMinutes);
      }
   }

   void 
   RemoveExpiredRecords::StopWork()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Do nothing.
   //---------------------------------------------------------------------------()
   {

   }
}
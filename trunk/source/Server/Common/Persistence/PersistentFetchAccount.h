// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class FetchAccount;
   class FetchAccountUIDs;

   class PersistentFetchAccount
   {
   public:
      PersistentFetchAccount(void);
      ~PersistentFetchAccount(void);

      static void Lock(__int64 ID);
      static void Unlock(__int64 ID);
      static void UnlockAll();

      static bool ReadObject(boost::shared_ptr<FetchAccount> pFA, const SQLCommand& command);
      static bool ReadObject(boost::shared_ptr<FetchAccount> oFA, boost::shared_ptr<DALRecordset> pRS);
      static bool SaveObject(boost::shared_ptr<FetchAccount> oFA, String &errorMessage);
      static bool SaveObject(boost::shared_ptr<FetchAccount> oFA);
      static bool DeleteObject(boost::shared_ptr<FetchAccount> pFA);
      static void DeleteByAccountID(__int64 ID);

      static void SetRetryNow(__int64 iFAID);
      static void SetNextTryTime(boost::shared_ptr<FetchAccount> pFA);
   };
}
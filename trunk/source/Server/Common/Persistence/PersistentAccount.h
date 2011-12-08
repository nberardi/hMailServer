// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Account;

   class PersistentAccount 
   {
   public:
	   PersistentAccount();
	   virtual ~PersistentAccount();

      static bool DeleteObject(boost::shared_ptr<Account> pAccount);
      static bool SaveObject(boost::shared_ptr<Account> pAccount);
      static bool SaveObject(boost::shared_ptr<Account> pAccount, String &sErrorMessage);
      static bool SaveObject(boost::shared_ptr<Account> pAccount, String &sErrorMessage, bool createInbox);
      static bool DeleteMessages(boost::shared_ptr<Account> pAccount);

      static __int64 GetMessageBoxSize(__int64 iAccountID);
      // Returns the current message box size, 
      // counted in bytes.

      static bool ReadObject(boost::shared_ptr<Account> pAccount,boost::shared_ptr<DALRecordset> pRS);
      static bool ReadObject(boost::shared_ptr<Account> pAccount,const String & sAddress);
      static bool ReadObject(boost::shared_ptr<Account> pAccount,__int64 ObjectID);

      static bool UpdateLastLogonTime(boost::shared_ptr<const Account> pAccount);

      static bool GetIsVacationMessageOn(boost::shared_ptr<const Account> pAccount);
      static bool CreateInbox(const Account &account);

      static bool DisableVacationMessage(boost::shared_ptr<const Account> pAccount);

   private:

      static bool ReadObject(boost::shared_ptr<Account> pAccount,const SQLCommand &command);
      
   };


}
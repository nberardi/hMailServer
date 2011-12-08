// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class IMAPFolder;
   class IMAPFolders;
   class ACLPermission;
   class ACLPermissions;

   class ACLManager
   {
   public:
      ACLManager(void);
      ~ACLManager(void);
      
      boost::shared_ptr<ACLPermission> GetPermissionForFolder(__int64 iAccountID, boost::shared_ptr<IMAPFolder> pFolder);

      bool SetACL(boost::shared_ptr<IMAPFolder> pFolder, const String& sIdentifier, const String &sPermissions);

	private:

      boost::shared_ptr<ACLPermission> _GetPermissionForAccount(boost::shared_ptr<ACLPermissions> pPermissions, __int64 iAccountID);
   };
}
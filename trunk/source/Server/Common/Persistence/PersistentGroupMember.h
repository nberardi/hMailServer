// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class GroupMember;

   class PersistentGroupMember
   {
   public:
      PersistentGroupMember(void);
      ~PersistentGroupMember(void);
      
      static bool DeleteByAccount(__int64 iAccountID);
      static bool DeleteObject(boost::shared_ptr<GroupMember> pObject);
      static bool SaveObject(boost::shared_ptr<GroupMember> pObject);
      static bool SaveObject(boost::shared_ptr<GroupMember> pObject, String &errorMessage);
      static bool ReadObject(boost::shared_ptr<GroupMember> pObject, boost::shared_ptr<DALRecordset> pRS);

   };
}
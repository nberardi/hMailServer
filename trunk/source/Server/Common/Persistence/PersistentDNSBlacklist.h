// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class DNSBlackList;

   class PersistentDNSBlackList
   {
   public:
      PersistentDNSBlackList(void);
      ~PersistentDNSBlackList(void);
      
      static bool DeleteObject(boost::shared_ptr<DNSBlackList> pObject);
      static bool SaveObject(boost::shared_ptr<DNSBlackList> pObject, String &errorMessage);
      static bool SaveObject(boost::shared_ptr<DNSBlackList> pObject);
      static bool ReadObject(boost::shared_ptr<DNSBlackList> pObject, boost::shared_ptr<DALRecordset> pRS);

   };
}
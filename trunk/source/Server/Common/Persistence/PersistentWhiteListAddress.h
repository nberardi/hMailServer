// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class WhiteListAddress;

   class PersistentWhiteListAddress
   {
   public:
      PersistentWhiteListAddress(void);
      ~PersistentWhiteListAddress(void);
      
      static bool DeleteObject(boost::shared_ptr<WhiteListAddress> pObject);
      static bool SaveObject(boost::shared_ptr<WhiteListAddress> pObject, String &errorMessage);
      static bool SaveObject(boost::shared_ptr<WhiteListAddress> pObject);
      static bool ReadObject(boost::shared_ptr<WhiteListAddress> pObject, boost::shared_ptr<DALRecordset> pRS);

      static bool IsSenderWhitelisted(const IPAddress &ipaddress, const String &fromAddress);
   };
}
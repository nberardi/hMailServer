// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class GreyListingWhiteAddress;

   class PersistentGreyListingWhiteAddress
   {
   public:
      PersistentGreyListingWhiteAddress(void);
      ~PersistentGreyListingWhiteAddress(void);
      
      static bool DeleteObject(boost::shared_ptr<GreyListingWhiteAddress> pObject);
      static bool SaveObject(boost::shared_ptr<GreyListingWhiteAddress> pObject, String &errorMessage);
      static bool SaveObject(boost::shared_ptr<GreyListingWhiteAddress> pObject);
      static bool ReadObject(boost::shared_ptr<GreyListingWhiteAddress> pObject, boost::shared_ptr<DALRecordset> pRS);

      static bool IsSenderWhitelisted(const String &address);
   };
}
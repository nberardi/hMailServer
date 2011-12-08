// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "../TCPIP/IPAddress.h"

namespace HM
{
   class SecurityRange;

   class PersistentSecurityRange
   {
   public:
	   PersistentSecurityRange();
	   virtual ~PersistentSecurityRange();

      static bool DeleteObject(boost::shared_ptr<SecurityRange> pSR);
      static bool SaveObject(boost::shared_ptr<SecurityRange> pSR);
      static bool SaveObject(boost::shared_ptr<SecurityRange> pSR, String &result);

      static bool ReadObject(boost::shared_ptr<SecurityRange> pSR, boost::shared_ptr<DALRecordset> pRS);
      static bool ReadObject(boost::shared_ptr<SecurityRange> pSR, const SQLCommand &command);
      static bool ReadObject(boost::shared_ptr<SecurityRange> pSR, __int64 ObjectID);

      static boost::shared_ptr<SecurityRange> ReadMatchingIP(const IPAddress &ipaddress);

      static bool DeleteExpired();

      static bool Exists(const String &name);

   private:

      static bool Validate(boost::shared_ptr<SecurityRange> pSR, String &result);
   };

}

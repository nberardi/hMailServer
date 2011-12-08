// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class RouteAddress;

   class PersistentRouteAddress
   {
   public:
	   PersistentRouteAddress();
	   virtual ~PersistentRouteAddress();

      static bool SaveObject(boost::shared_ptr<RouteAddress> pRA);
      static bool SaveObject(boost::shared_ptr<RouteAddress> pRA, String &errorMessage);
      static bool DeleteObject(boost::shared_ptr<RouteAddress> pRA);
      static bool DeleteByRoute(__int64 RouteID);

      static bool ReadObject(boost::shared_ptr<RouteAddress> pRA, long lID);
      static bool ReadObject(boost::shared_ptr<RouteAddress> pRA, boost::shared_ptr<DALRecordset> pRS);


   };

}

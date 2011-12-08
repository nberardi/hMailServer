// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Route;

   class PersistentRoute
   {
   public:
	   PersistentRoute();
	   virtual ~PersistentRoute();

      static bool DeleteObject(boost::shared_ptr<Route> pRoute);

      static bool SaveObject(boost::shared_ptr<Route> pRoute);
      static bool SaveObject(boost::shared_ptr<Route> pRoute, String &sErrorMessage);
      static bool ReadObject(boost::shared_ptr<Route> pRoute, long lID);
      static bool ReadObject(boost::shared_ptr<Route> pRoute, boost::shared_ptr<DALRecordset> pRS);
   };
   
}


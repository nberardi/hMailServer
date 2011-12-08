// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class SURBLServer;

   class PersistentSURBLServer
   {
   public:
      PersistentSURBLServer(void);
      ~PersistentSURBLServer(void);
      
      static bool DeleteObject(boost::shared_ptr<SURBLServer> pObject);
      static bool SaveObject(boost::shared_ptr<SURBLServer> pObject);
      static bool SaveObject(boost::shared_ptr<SURBLServer> pObject, String &errorMessage);
      static bool ReadObject(boost::shared_ptr<SURBLServer> pObject, boost::shared_ptr<DALRecordset> pRS);

   };
}
// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class IncomingRelay;

   class PersistentIncomingRelay
   {
   public:
	   PersistentIncomingRelay();
	   virtual ~PersistentIncomingRelay();

      static bool DeleteObject(boost::shared_ptr<IncomingRelay> pSR);
      static bool SaveObject(boost::shared_ptr<IncomingRelay> pSR);
      static bool SaveObject(boost::shared_ptr<IncomingRelay> pSR, String &errorMessage);

      static bool ReadObject(boost::shared_ptr<IncomingRelay> pSR, boost::shared_ptr<DALRecordset> pRS);
      static bool ReadObject(boost::shared_ptr<IncomingRelay> pSR, const SQLCommand &command);
      static bool ReadObject(boost::shared_ptr<IncomingRelay> pSR, int ObjectID);
   };

}

// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "IncomingRelays.h"

namespace HM
{
   IncomingRelays::IncomingRelays()
   {

   }

   IncomingRelays::~IncomingRelays()
   {

   }


   bool
   IncomingRelays::Refresh()
   //---------------------------------------------------------------------------
   // DESCRIPTION:
   // Refreshes the collection from the database.
   //---------------------------------------------------------------------------
   {
      String sSQL;
      sSQL.Format(_T("select * from hm_incoming_relays order by relayname asc"));

      return _DBLoad(sSQL);
   }

   bool
   IncomingRelays::IsIncomingRelay(const IPAddress &address) const
   {
      if (vecObjects.size() == 0)
      {
         // If no security ranges exist, default is deny.
         return false;
      }

      boost_foreach(shared_ptr<IncomingRelay> relay, vecObjects)
      {
         if (relay->IPIsWithinRange(address))
         {
            return true;
         }
      }

      return false;
   }

}

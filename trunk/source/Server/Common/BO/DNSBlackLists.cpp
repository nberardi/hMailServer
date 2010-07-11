// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include "DNSBlackLists.h"

namespace HM
{
   DNSBlackLists::DNSBlackLists()
   {
   }

   DNSBlackLists::~DNSBlackLists(void)
   {
   }


   void 
   DNSBlackLists::Refresh()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reloads all routes from the database.
   //---------------------------------------------------------------------------()
   {

      String sSQL = "select * from hm_dnsbl order by sblid asc";
      _DBLoad(sSQL);
   }
}
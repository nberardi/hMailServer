// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "SURBLServers.h"

namespace HM
{
   SURBLServers::SURBLServers()
   {
   }

   SURBLServers::~SURBLServers(void)
   {
   }


   void 
   SURBLServers::Refresh()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads all SURBL servers from the database.
   //---------------------------------------------------------------------------()
   {
      String sSQL = "select * from hm_surblservers order by surblid asc";
      _DBLoad(sSQL);
   }
}
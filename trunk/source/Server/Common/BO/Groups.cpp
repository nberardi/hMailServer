// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "Groups.h"

#include "../Persistence/PersistentGroup.h"

namespace HM
{
   Groups::Groups()
   {
      
   }

   Groups::~Groups(void)
   {
   }

   void 
   Groups::Refresh()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads all groups form the database
   //---------------------------------------------------------------------------()
   {
      String sSQL = "select * from hm_groups order by groupname asc";

      _DBLoad(sSQL);
   }
}
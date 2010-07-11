// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "WhiteListAddresses.h"

namespace HM
{
   WhiteListAddresses::WhiteListAddresses()
   {
   }

   WhiteListAddresses::~WhiteListAddresses(void)
   {
   }


   void 
   WhiteListAddresses::Refresh()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads all SURBL servers from the database.
   //---------------------------------------------------------------------------()
   {
      String sSQL = "select * from hm_whitelist order by whiteloweripaddress1 asc, whiteloweripaddress2 asc";
      _DBLoad(sSQL);
   }



}
// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include "DefaultDomain.h"

namespace HM
{
   DefaultDomain::DefaultDomain(void)
   {
   }

   DefaultDomain::~DefaultDomain(void)
   {
   }

   String 
   DefaultDomain::ApplyDefaultDomain(const String &sAddress)
   {     
      if (sAddress.Find(_T("@")) >= 0 || sAddress.IsEmpty())
         return sAddress;

      // Append default domain
      String sDefaultDomain = Configuration::Instance()->GetDefaultDomain();

      if (sDefaultDomain.IsEmpty())
         return sAddress;

      return sAddress + "@" + sDefaultDomain;
   }
}
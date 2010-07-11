// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "SSLCertificates.h"

#include "../Persistence/PersistentSSLCertificate.h"

namespace HM
{
   SSLCertificates::SSLCertificates()
   {
   }

   SSLCertificates::~SSLCertificates(void)
   {
   }


   void
   SSLCertificates::Refresh()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads all SURBL servers from the database.
   //---------------------------------------------------------------------------()
   {
      String sSQL = "select * from hm_sslcertificates order by sslcertificatename asc";
      _DBLoad(sSQL);
   }

}
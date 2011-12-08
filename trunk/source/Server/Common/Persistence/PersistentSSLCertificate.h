// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class SSLCertificate;

   class PersistentSSLCertificate
   {
   public:
      PersistentSSLCertificate(void);
      ~PersistentSSLCertificate(void);
      
      static bool DeleteObject(boost::shared_ptr<SSLCertificate> pObject);
      static bool SaveObject(boost::shared_ptr<SSLCertificate> pObject);
      static bool SaveObject(boost::shared_ptr<SSLCertificate> pObject, String &errorMessage);
      static bool ReadObject(boost::shared_ptr<SSLCertificate> pObject, boost::shared_ptr<DALRecordset> pRS);

   };
}
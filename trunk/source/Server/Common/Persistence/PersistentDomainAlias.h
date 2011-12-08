// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class DomainAlias;

   class PersistentDomainAlias
   {
   public:
      PersistentDomainAlias(void);
      ~PersistentDomainAlias(void);

      static bool ReadObject(boost::shared_ptr<DomainAlias> oFA, const SQLCommand & sSQL);
      static bool ReadObject(boost::shared_ptr<DomainAlias> oFA, boost::shared_ptr<DALRecordset> pRS);
      static bool SaveObject(boost::shared_ptr<DomainAlias> oFA);
      static bool SaveObject(boost::shared_ptr<DomainAlias> oFA, String &sErrorMessage);
      static bool DeleteObject(boost::shared_ptr<DomainAlias> pDA);
   };
}
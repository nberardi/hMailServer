// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "../BO/DistributionListRecipient.h"

namespace HM
{
   class PersistentDistributionListRecipient
   {
   public:
      PersistentDistributionListRecipient(void);
      ~PersistentDistributionListRecipient(void);

      static bool DeleteByListID(__int64 iListID);
      static bool DeleteObject(boost::shared_ptr<DistributionListRecipient> pRecipient);
      
      static bool SaveObject(boost::shared_ptr<DistributionListRecipient> pRecipient);
      static bool SaveObject(boost::shared_ptr<DistributionListRecipient> pRecipient, String &sErrorMessage);

      static bool ReadObject(boost::shared_ptr<DistributionListRecipient> pRecipient, long ObjectID);
      static bool ReadObject(boost::shared_ptr<DistributionListRecipient> pRecipient, const SQLCommand &command);
      static bool ReadObject(boost::shared_ptr<DistributionListRecipient> pRecipient, boost::shared_ptr<DALRecordset> pRS);

   };
}

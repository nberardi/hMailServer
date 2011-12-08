// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once


namespace HM
{
   class DistributionList;

   class PersistentDistributionList
   {
   public:
      PersistentDistributionList(void);
      ~PersistentDistributionList(void);

      static bool DeleteObject(boost::shared_ptr<DistributionList> pDistList);
      
      static bool SaveObject(boost::shared_ptr<DistributionList> pDistList);
      static bool SaveObject(boost::shared_ptr<DistributionList> pDistList, String &sErrorMessage);

      static bool ReadObject(boost::shared_ptr<DistributionList> pDistList, const String &sAddress);
      static bool ReadObject(boost::shared_ptr<DistributionList> pDistList, __int64 ObjectID);
      static bool ReadObject(boost::shared_ptr<DistributionList> pDistList, const SQLCommand &command);
      static bool ReadObject(boost::shared_ptr<DistributionList> pDistList, boost::shared_ptr<DALRecordset> pRS);

      static bool DeleteMembers(boost::shared_ptr<DistributionList> pDistList);


   private:

      
   };
}

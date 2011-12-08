// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Alias;
   class DistributionList;
   class Group;
   class Domain;
   class DomainAlias;
   class DistributionListRecipient;
   class Route;

   class PreSaveLimitationsCheck
   {
   public:
      PreSaveLimitationsCheck(void);
      ~PreSaveLimitationsCheck(void);


      static bool CheckLimitations(boost::shared_ptr<Domain> domain, String &resultDescription);
      static bool CheckLimitations(boost::shared_ptr<DomainAlias> domainAlias, String &resultDescription);
      static bool CheckLimitations(boost::shared_ptr<Account> account, String &resultDescription);
      static bool CheckLimitations(boost::shared_ptr<Alias> alias, String &resultDescription);
      static bool CheckLimitations(boost::shared_ptr<DistributionList> list, String &resultDescription);
      static bool CheckLimitations(boost::shared_ptr<Group> group, String &resultDescription);
      static bool CheckLimitations(boost::shared_ptr<DistributionListRecipient> pRecipient, String &resultDescription);
      static bool CheckLimitations(boost::shared_ptr<Route> route, String &resultDescription);
    
      
   private:

      enum ObjectType
      {
         TypeAccount = 1,
         TypeAlias = 2,
         TypeList = 3,
         TypeGroup = 4
      };



      static boost::shared_ptr<Domain> GetDomain(__int64 id);
      static bool DuplicateError(String &resultDescription);

      static bool GetDuplicateExist(boost::shared_ptr<Domain> domain, ObjectType objectType, __int64 objectID, const String &objectName);
   };
}
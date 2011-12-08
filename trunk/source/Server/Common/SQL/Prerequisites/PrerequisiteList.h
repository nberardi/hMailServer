// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once


namespace HM
{
   class IPrerequisite;

   class PrerequisiteList
   {
   public:
      PrerequisiteList(void);
      ~PrerequisiteList(void);

      bool Ensure(boost::shared_ptr<DALConnection> connection, int scriptDatabaseVersion, String &sErrorMessage);

   private:

      void _Initialize();

      vector<pair<int, boost::shared_ptr<IPrerequisite > > > _prerequisites;
      
   };
}
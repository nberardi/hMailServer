// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Rule;

   class PersistentRule
   {
   public:
      PersistentRule(void);
      ~PersistentRule(void);

      static bool ReadObject(boost::shared_ptr<Rule> pRule, const SQLCommand& sSQL);
      static bool ReadObject(boost::shared_ptr<Rule> pRule, boost::shared_ptr<DALRecordset> pRS);

      static bool SaveObject(boost::shared_ptr<Rule> pRule, String &errorMessage);
      static bool SaveObject(boost::shared_ptr<Rule> pRule);
      static bool DeleteObject(boost::shared_ptr<Rule> pRule);

      static void DeleteByAccountID(__int64 ID);

   private:

      static void _NotifyReload(boost::shared_ptr<Rule> pRule);
   };
}
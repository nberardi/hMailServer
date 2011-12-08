// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class RuleAction;

   class PersistentRuleAction
   {
   public:
      PersistentRuleAction(void);
      ~PersistentRuleAction(void);

      static bool ReadObject(boost::shared_ptr<RuleAction> pRuleAction, const SQLCommand& sSQL);
      static bool ReadObject(boost::shared_ptr<RuleAction> pRuleAction, boost::shared_ptr<DALRecordset> pRS);

      static bool SaveObject(boost::shared_ptr<RuleAction> pRule, String &errorMessage);
      static bool SaveObject(boost::shared_ptr<RuleAction> pRule);
      static bool DeleteObject(boost::shared_ptr<RuleAction> pRule);

      static bool DeleteObjects(__int64 iRuleID);

      static bool GetExistsFolderReferenceContainingCharacter(String theChar);
      static bool UpdateHierarchyDelimiter(String oldDelimiter, String newDelimiter);
   };
}
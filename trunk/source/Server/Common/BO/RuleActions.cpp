// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include "RuleActions.h"


#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   RuleActions::RuleActions(__int64 iRuleID) :
      m_iRuleID(iRuleID)
   {
   }

   RuleActions::~RuleActions(void)
   {
   }

   void 
   RuleActions::Refresh()
   {
      String sSQL;
      sSQL.Format(_T("select * from hm_rule_actions where actionruleid = %I64d order by actionsortorder asc"), m_iRuleID);

      _DBLoad(sSQL);
   }



   bool
   RuleActions::PreSaveObject(boost::shared_ptr<RuleAction> pRuleAction, XNode *node)
   {
      pRuleAction->SetRuleID(m_iRuleID);
      return true;
   }   

   void
   RuleActions::MoveUp(boost::shared_ptr<RuleAction> pRuleToMove)
   {
      vector<boost::shared_ptr<RuleAction> >::iterator iter = _GetRuleActionIterator(pRuleToMove);
      vector<boost::shared_ptr<RuleAction> >::iterator iterEnd = vecObjects.end();

      if (iter == iterEnd || iter == vecObjects.begin())
         return;

      vector<boost::shared_ptr<RuleAction> >::iterator iterPrevious = iter - 1;

      // Move the rule to the previous position in the vector.
      boost::shared_ptr<RuleAction> pRuleAction = (*iter);

      // Delete it from the current position
      vecObjects.erase(iter);

      // Insert the rule one step back
      vecObjects.insert(iterPrevious, pRuleAction);

      // Check that sort order is correct.
      _UpdateSortOrder();
   }

   void
   RuleActions::MoveDown(boost::shared_ptr<RuleAction> pRuleAction)
   {
      vector<boost::shared_ptr<RuleAction> >::iterator iter = _GetRuleActionIterator(pRuleAction);
      vector<boost::shared_ptr<RuleAction> >::iterator iterEnd = vecObjects.end();

      vector<boost::shared_ptr<RuleAction> >::iterator iterNext = iter +1;

      if (iter == iterEnd || iterNext == vecObjects.end())
         return;

      // Move the rule to the next position in the vector.
      boost::shared_ptr<RuleAction> pNextRuleAction = (*iterNext);

      // Delete the next rule from the current position.
      vecObjects.erase(iterNext);

      // Insert the next rule before this one.
      vecObjects.insert(iter, pNextRuleAction);

      // Check that sort order is correct.
      _UpdateSortOrder();
   }

   void 
   RuleActions::_UpdateSortOrder()
   {
      vector<boost::shared_ptr<RuleAction> >::iterator iter = vecObjects.begin();
      vector<boost::shared_ptr<RuleAction> >::iterator iterEnd = vecObjects.end();

      int iSortOrder = 1;

      for (; iter != iterEnd; iter++, iSortOrder ++)
      {
         boost::shared_ptr<RuleAction> pRuleAction = (*iter);

         if (pRuleAction->GetSortOrder() != iSortOrder)
         {
            // We need to update the sort order of this rule.
            pRuleAction->SetSortOrder(iSortOrder);

            // If it's a new rule action, we should not save it now.
            if (pRuleAction->GetID() > 0)
            {
               PersistentRuleAction::SaveObject(pRuleAction);
            }
         }
      }
   }

   vector<boost::shared_ptr<RuleAction> >::iterator 
   RuleActions::_GetRuleActionIterator(boost::shared_ptr<RuleAction> pRuleAction)
   {
      vector<boost::shared_ptr<RuleAction> >::iterator iter = vecObjects.begin();
      vector<boost::shared_ptr<RuleAction> >::iterator iterEnd = vecObjects.end();

      int iCurrentSortOrder = -1;

      for (; iter != iterEnd; iter++)
      {
         boost::shared_ptr<RuleAction> pCurRuleAction = (*iter);

         if (pCurRuleAction == pRuleAction)
         {
            return iter;
         }
      }

      return iterEnd;
   }


}
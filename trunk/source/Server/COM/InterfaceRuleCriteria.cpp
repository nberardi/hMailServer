// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceRuleCriteria.h"

#include "../Common/BO/RuleCriteria.h"
#include "../Common/BO/RuleCriterias.h"
#include "../Common/Persistence/PersistentRuleCriteria.h"

#include "COMError.h"

STDMETHODIMP InterfaceRuleCriteria::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::Save()
{
   if (m_pParentCollection->GetRuleID() > 0)
   {
      if (!HM::PersistentRuleCriteria::SaveObject(m_pObject))
      {
         // Saving failed.
         return COMError::GenerateError("Failed to save object. See hMailServer error log.");
      }
   }

   AddToParentCollection();
      
   return S_OK;
   
}

STDMETHODIMP InterfaceRuleCriteria::get_RuleID(long *pVal)
{
   *pVal = (long) m_pObject->GetRuleID();
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::put_RuleID(long newVal)
{
   m_pObject->SetRuleID(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceRuleCriteria::get_UsePredefined(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetUsePredefined() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::put_UsePredefined(VARIANT_BOOL newVal)
{
   m_pObject->SetUsePredefined(newVal == VARIANT_TRUE);

   return S_OK;
}
STDMETHODIMP InterfaceRuleCriteria::get_HeaderField(BSTR *pVal)
{
   *pVal = m_pObject->GetHeaderField().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::put_HeaderField(BSTR newVal)
{
   m_pObject->SetHeaderField(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::get_MatchValue(BSTR *pVal)
{
   *pVal = m_pObject->GetMatchValue().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::put_MatchValue(BSTR newVal)
{
   m_pObject->SetMatchValue(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::get_PredefinedField(eRulePredefinedField *pVal)
{
   *pVal = (eRulePredefinedField) m_pObject->GetPredefinedField();
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::put_PredefinedField(eRulePredefinedField newVal)
{
   m_pObject->SetPredefinedField((HM::RuleCriteria::PredefinedField)newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::get_MatchType(eRuleMatchType *pVal)
{
   *pVal = (eRuleMatchType) m_pObject->GetMatchType();
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::put_MatchType(eRuleMatchType newVal)
{
   m_pObject->SetMatchType((HM::RuleCriteria::MatchType)newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleCriteria::Delete()
{
   if (!m_pParentCollection)
      return HM::PersistentRuleCriteria::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}


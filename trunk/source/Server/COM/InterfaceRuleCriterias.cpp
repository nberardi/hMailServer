// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceRuleCriterias.h"

#include "InterfaceRuleCriteria.h"

#include "../Common/BO/RuleCriterias.h"
#include "../Common/BO/RuleCriteria.h"

void 
InterfaceRuleCriterias::Attach(shared_ptr<HM::RuleCriterias> pCriterias)
{
   m_pRuleCriterias = pCriterias;
}

STDMETHODIMP InterfaceRuleCriterias::get_ItemByDBID(long lDBID, IInterfaceRuleCriteria** pVal)
{
   CComObject<InterfaceRuleCriteria>* pInterfaceRuleCriteria = new CComObject<InterfaceRuleCriteria>();
   pInterfaceRuleCriteria->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::RuleCriteria> pRule = m_pRuleCriterias->GetItemByDBID(lDBID);
   if (!pRule)
      return DISP_E_BADINDEX;

   pInterfaceRuleCriteria->AttachItem(pRule);
   pInterfaceRuleCriteria->AttachParent(m_pRuleCriterias, true);
   pInterfaceRuleCriteria->AddRef();
   *pVal = pInterfaceRuleCriteria;   

   return S_OK;
}

STDMETHODIMP InterfaceRuleCriterias::get_Item(long lIndex, IInterfaceRuleCriteria** pVal)
{
   CComObject<InterfaceRuleCriteria>* pInterfaceRuleCriteria = new CComObject<InterfaceRuleCriteria>();
   pInterfaceRuleCriteria->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::RuleCriteria> pRule = m_pRuleCriterias->GetItem(lIndex);
   if (!pRule)
      return DISP_E_BADINDEX;

   pInterfaceRuleCriteria->AttachItem(pRule);
   pInterfaceRuleCriteria->AttachParent(m_pRuleCriterias, true);

   pInterfaceRuleCriteria->AddRef();
   *pVal = pInterfaceRuleCriteria;   

   return S_OK;
}

STDMETHODIMP InterfaceRuleCriterias::get_Count(LONG* pVal)
{
   *pVal = m_pRuleCriterias->GetCount();

   return S_OK;
}

STDMETHODIMP InterfaceRuleCriterias::Add(IInterfaceRuleCriteria** pVal)
{
   if (!m_pRuleCriterias)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceRuleCriteria>* pIntDA = new CComObject<InterfaceRuleCriteria>();
   pIntDA->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::RuleCriteria> pDA = shared_ptr<HM::RuleCriteria>(new HM::RuleCriteria);

   pDA->SetRuleID(m_pRuleCriterias->GetRuleID());

   pIntDA->AttachItem(pDA);
   pIntDA->AttachParent(m_pRuleCriterias, false);
   pIntDA->AddRef();

   *pVal = pIntDA;

   return S_OK;   

   return S_OK;
}

STDMETHODIMP InterfaceRuleCriterias::DeleteByDBID(LONG DBID)
{
   m_pRuleCriterias->DeleteItemByDBID(DBID);

   return S_OK;
}

STDMETHODIMP InterfaceRuleCriterias::Delete(LONG DBID)
{
   m_pRuleCriterias->DeleteItem(DBID);

   return S_OK;
}

STDMETHODIMP InterfaceRuleCriterias::Refresh(void)
{
   m_pRuleCriterias->Refresh();

   return S_OK;
}



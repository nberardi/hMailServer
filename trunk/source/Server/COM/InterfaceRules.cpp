// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceRules.h"

#include "InterfaceRule.h"

#include "../Common/BO/Rules.h"
#include "../Common/BO/Rule.h"

void 
InterfaceRules::Attach(shared_ptr<HM::Rules> pRules)
{
   m_pRules = pRules;
}

STDMETHODIMP InterfaceRules::get_ItemByDBID(long lDBID, IInterfaceRule** pVal)
{
   CComObject<InterfaceRule>* pInterfaceRule = new CComObject<InterfaceRule>();
   pInterfaceRule->SetAuthentication(m_pAuthentication);


   shared_ptr<HM::Rule> pRule = m_pRules->GetItemByDBID(lDBID);
   if (!pRule)
      return DISP_E_BADINDEX;

   pInterfaceRule->AttachParent(m_pRules, true);
   pInterfaceRule->AttachItem(pRule);
   pInterfaceRule->AddRef();
   *pVal = pInterfaceRule;   

   return S_OK;
}

STDMETHODIMP InterfaceRules::get_Item(long lIndex, IInterfaceRule** pVal)
{
   CComObject<InterfaceRule>* pInterfaceRule = new CComObject<InterfaceRule>();
   pInterfaceRule->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Rule> pRule = m_pRules->GetItem(lIndex);
   if (!pRule)
      return DISP_E_BADINDEX;

   pInterfaceRule->AttachParent(m_pRules, true);
   pInterfaceRule->AttachItem(pRule);
   pInterfaceRule->AddRef();
   *pVal = pInterfaceRule;   

   return S_OK;
}

STDMETHODIMP InterfaceRules::get_Count(LONG* pVal)
{
   *pVal = m_pRules->GetCount();

   return S_OK;
}

STDMETHODIMP InterfaceRules::Add(IInterfaceRule** pVal)
{
   if (!m_pRules)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceRule>* pIntDA = new CComObject<InterfaceRule>();
   pIntDA->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Rule> pDA = shared_ptr<HM::Rule>(new HM::Rule);

   // Make sure that the new rule is
   // added to the right account.
   pDA->SetAccountID(m_pRules->GetAccountID());

   pIntDA->AttachItem(pDA);
   pIntDA->AttachParent(m_pRules, false);
   pIntDA->AddRef();

   *pVal = pIntDA;

   return S_OK;   

   return S_OK;
}

STDMETHODIMP InterfaceRules::DeleteByDBID(LONG DBID)
{
   m_pRules->DeleteItemByDBID(DBID);

   return S_OK;
}

STDMETHODIMP InterfaceRules::Refresh(void)
{
   m_pRules->Refresh();

   return S_OK;
}

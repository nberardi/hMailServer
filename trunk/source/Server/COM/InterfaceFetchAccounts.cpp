// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "InterfaceFetchAccounts.h"

#include "../COM/InterfaceFetchAccount.h"

void 
InterfaceFetchAccounts::Attach(shared_ptr<HM::FetchAccounts> pFetchAccounts)
{
   m_pFetchAccounts = pFetchAccounts;
}

STDMETHODIMP InterfaceFetchAccounts::get_ItemByDBID(long lDBID, IInterfaceFetchAccount** pVal)
{
   CComObject<InterfaceFetchAccount>* pInterfaceAccount = new CComObject<InterfaceFetchAccount>();
   pInterfaceAccount->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::FetchAccount> pFetchAccount = m_pFetchAccounts->GetItemByDBID(lDBID);
   if (!pFetchAccount)
      return DISP_E_BADINDEX;

   pInterfaceAccount->AttachItem(pFetchAccount);
   pInterfaceAccount->AttachParent(m_pFetchAccounts, true);
   pInterfaceAccount->AddRef();
   *pVal = pInterfaceAccount;   

   return S_OK;
}

STDMETHODIMP InterfaceFetchAccounts::get_Item(long lIndex, IInterfaceFetchAccount** pVal)
{
   CComObject<InterfaceFetchAccount>* pInterfaceAccount = new CComObject<InterfaceFetchAccount>();
   pInterfaceAccount->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::FetchAccount> pFetchAccount = m_pFetchAccounts->GetItem(lIndex);
   if (!pFetchAccount)
      return DISP_E_BADINDEX;

   pInterfaceAccount->AttachItem(pFetchAccount);
   pInterfaceAccount->AttachParent(m_pFetchAccounts, true);
   pInterfaceAccount->AddRef();
   *pVal = pInterfaceAccount;   

   return S_OK;
}

STDMETHODIMP InterfaceFetchAccounts::Refresh(void)
{
   m_pFetchAccounts->Refresh();

   return S_OK;
}

STDMETHODIMP InterfaceFetchAccounts::Delete(LONG Index)
{
   m_pFetchAccounts->DeleteItem(Index);

   return S_OK;
}

STDMETHODIMP InterfaceFetchAccounts::DeleteByDBID(LONG DBID)
{
   m_pFetchAccounts->DeleteItemByDBID(DBID);

   return S_OK;
}

STDMETHODIMP InterfaceFetchAccounts::get_Count(long *pVal)
{
   *pVal = m_pFetchAccounts->GetCount();

   return S_OK;
}

STDMETHODIMP InterfaceFetchAccounts::Add(IInterfaceFetchAccount **pVal)
{
   if (!m_pFetchAccounts)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceFetchAccount>* pIntFA = new CComObject<InterfaceFetchAccount>();
   pIntFA->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::FetchAccount> pFA = shared_ptr<HM::FetchAccount>(new HM::FetchAccount);

   pFA->SetAccountID(m_pFetchAccounts->GetAccountID());

   pIntFA->AttachItem(pFA);
   pIntFA->AttachParent(m_pFetchAccounts, false);

   pIntFA->AddRef();
   *pVal = pIntFA;

   return S_OK;
}
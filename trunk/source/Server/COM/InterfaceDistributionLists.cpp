// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceDistributionLists.h"

#include "InterfaceDistributionList.h"

#include "../common/bo/distributionlists.h"
#include "../common/persistence/PersistentDistributionList.h"

void 
InterfaceDistributionLists::Attach(shared_ptr<HM::DistributionLists> pDistributionLists)
{
   m_pDistributionLists= pDistributionLists;
}

STDMETHODIMP
InterfaceDistributionLists::get_Count(long *pVal)
{
   *pVal = m_pDistributionLists->GetCount();

   return S_OK;

}

STDMETHODIMP InterfaceDistributionLists::DeleteByDBID(long DBID)
{
   m_pDistributionLists->DeleteItemByDBID(DBID);

   return S_OK;
}

STDMETHODIMP InterfaceDistributionLists::Add(IInterfaceDistributionList **pVal)
{
   if (!m_pDistributionLists)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceDistributionList>* pList = new CComObject<InterfaceDistributionList>();
   pList->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::DistributionList> pPersList = shared_ptr<HM::DistributionList>(new HM::DistributionList);
   pPersList->SetDomainID(m_iDomainID);

   pList->AttachItem(pPersList);
   pList->AttachParent(m_pDistributionLists, false);
   pList->AddRef();

   *pVal = pList;


   return S_OK;
}

STDMETHODIMP InterfaceDistributionLists::Delete(long Index)
{
   shared_ptr<HM::DistributionList> pPersList = m_pDistributionLists->GetItem(Index);

   HM::PersistentDistributionList::DeleteObject(pPersList);

   return S_OK;
}

STDMETHODIMP InterfaceDistributionLists::get_Item(long Index, IInterfaceDistributionList **pVal)
{
   CComObject<InterfaceDistributionList>* pList = new CComObject<InterfaceDistributionList>();
   pList->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::DistributionList> pPersList = m_pDistributionLists->GetItem(Index);

   if (!pPersList)
      return DISP_E_BADINDEX;  

   pList->AttachItem(pPersList);
   pList->AttachParent(m_pDistributionLists, true);
   pList->AddRef();
   *pVal = pList;

   return S_OK;
}


STDMETHODIMP InterfaceDistributionLists::Refresh()
{
   m_pDistributionLists->Refresh();
   return S_OK;
}

STDMETHODIMP InterfaceDistributionLists::get_ItemByDBID(long DBID, IInterfaceDistributionList **pVal)
{
   CComObject<InterfaceDistributionList>* pList = new CComObject<InterfaceDistributionList>();
   pList->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::DistributionList> pPersList = m_pDistributionLists->GetItemByDBID(DBID);

   if (!pPersList)
      return DISP_E_BADINDEX;  

   pList->AttachItem(pPersList);
   pList->AttachParent(m_pDistributionLists, true);
   pList->AddRef();
   *pVal = pList;

   return S_OK;
}

STDMETHODIMP InterfaceDistributionLists::get_ItemByAddress(BSTR sAddress, IInterfaceDistributionList **pVal)
{
   CComObject<InterfaceDistributionList>* pList = new CComObject<InterfaceDistributionList>();
   pList->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::DistributionList> pPersList = m_pDistributionLists->GetItemByAddress(sAddress);

   if (!pPersList)
      return DISP_E_BADINDEX;  

   pList->AttachItem(pPersList);
   pList->AttachParent(m_pDistributionLists, true);
   pList->AddRef();
   *pVal = pList;

   return S_OK;
}

// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceWhiteListAddresses.h"


#include "InterfaceWhiteListAddress.h"

#include "..\Common\BO\WhiteListAddress.h"
#include "..\Common\BO\WhiteListAddresses.h"


void 
InterfaceWhiteListAddresses::Attach(shared_ptr<HM::WhiteListAddresses> pBA) 
{ 
   m_pWhiteListAddresses = pBA; 
}

STDMETHODIMP 
InterfaceWhiteListAddresses::Refresh()
{
   if (!m_pWhiteListAddresses)
      return S_FALSE;

   m_pWhiteListAddresses->Refresh();

   return S_OK;
}

STDMETHODIMP 
InterfaceWhiteListAddresses::Clear()
{
   if (!m_pWhiteListAddresses)
      return S_FALSE;

   m_pWhiteListAddresses->DeleteAll();

   return S_OK;
}



STDMETHODIMP InterfaceWhiteListAddresses::get_Count(long *pVal)
{
   *pVal = m_pWhiteListAddresses->GetCount();

   return S_OK;
}

STDMETHODIMP 
InterfaceWhiteListAddresses::get_Item(long Index, IInterfaceWhiteListAddress **pVal)
{
   CComObject<InterfaceWhiteListAddress>* pInterfaceWhiteListAddress = new CComObject<InterfaceWhiteListAddress>();
   pInterfaceWhiteListAddress->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::WhiteListAddress> pBA = m_pWhiteListAddresses->GetItem(Index);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceWhiteListAddress->AttachItem(pBA);
   pInterfaceWhiteListAddress->AttachParent(m_pWhiteListAddresses, true);
   pInterfaceWhiteListAddress->AddRef();
   *pVal = pInterfaceWhiteListAddress;

   return S_OK;
}

STDMETHODIMP 
InterfaceWhiteListAddresses::DeleteByDBID(long DBID)
{
   m_pWhiteListAddresses->DeleteItemByDBID(DBID);
   return S_OK;
}

STDMETHODIMP 
InterfaceWhiteListAddresses::get_ItemByDBID(long lDBID, IInterfaceWhiteListAddress **pVal)
{
   CComObject<InterfaceWhiteListAddress>* pInterfaceWhiteListAddress = new CComObject<InterfaceWhiteListAddress>();
   pInterfaceWhiteListAddress->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::WhiteListAddress> pBA = m_pWhiteListAddresses->GetItemByDBID(lDBID);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceWhiteListAddress->AttachItem(pBA);
   pInterfaceWhiteListAddress->AttachParent(m_pWhiteListAddresses, true);
   pInterfaceWhiteListAddress->AddRef();

   *pVal = pInterfaceWhiteListAddress;

   return S_OK;
}

STDMETHODIMP 
InterfaceWhiteListAddresses::get_ItemByName(BSTR sName, IInterfaceWhiteListAddress **pVal)
{
   CComObject<InterfaceWhiteListAddress>* pInterfaceWhiteListAddress = new CComObject<InterfaceWhiteListAddress>();
   pInterfaceWhiteListAddress->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::WhiteListAddress> pBA = m_pWhiteListAddresses->GetItemByName(sName);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceWhiteListAddress->AttachItem(pBA);
   pInterfaceWhiteListAddress->AttachParent(m_pWhiteListAddresses, true);
   pInterfaceWhiteListAddress->AddRef();

   *pVal = pInterfaceWhiteListAddress;

   return S_OK;
}

STDMETHODIMP 
InterfaceWhiteListAddresses::Add(IInterfaceWhiteListAddress **pVal)
{
   if (!m_pWhiteListAddresses)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceWhiteListAddress>* pInterfaceWhiteListAddress = new CComObject<InterfaceWhiteListAddress>();
   pInterfaceWhiteListAddress->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::WhiteListAddress> pBA = shared_ptr<HM::WhiteListAddress>(new HM::WhiteListAddress);

   pInterfaceWhiteListAddress->AttachItem(pBA);
   pInterfaceWhiteListAddress->AttachParent(m_pWhiteListAddresses, false);

   pInterfaceWhiteListAddress->AddRef();

   *pVal = pInterfaceWhiteListAddress;

   return S_OK;
}

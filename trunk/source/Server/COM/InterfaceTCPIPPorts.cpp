// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceTCPIPPorts.h"


#include "..\Common\BO\TCPIPPort.h"
#include "InterfaceTCPIPPort.h"

void 
InterfaceTCPIPPorts::Attach(shared_ptr<HM::TCPIPPorts> pBA) 
{ 
   m_pTCPIPPorts = pBA; 
}

STDMETHODIMP 
InterfaceTCPIPPorts::Refresh()
{
   if (!m_pTCPIPPorts)
      return S_FALSE;

   m_pTCPIPPorts->Refresh();

   return S_OK;
}

STDMETHODIMP 
InterfaceTCPIPPorts::SetDefault()
{
   if (!m_pTCPIPPorts)
      return S_FALSE;

   m_pTCPIPPorts->SetDefault();

   return S_OK;
}



STDMETHODIMP InterfaceTCPIPPorts::get_Count(long *pVal)
{
   *pVal = m_pTCPIPPorts->GetCount();

   return S_OK;
}

STDMETHODIMP 
InterfaceTCPIPPorts::get_Item(long Index, IInterfaceTCPIPPort **pVal)
{
   CComObject<InterfaceTCPIPPort>* pInterfaceTCPIPPort = new CComObject<InterfaceTCPIPPort>();
   pInterfaceTCPIPPort->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::TCPIPPort> pBA = m_pTCPIPPorts->GetItem(Index);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceTCPIPPort->AttachItem(pBA);
   pInterfaceTCPIPPort->AttachParent(m_pTCPIPPorts, true);
   pInterfaceTCPIPPort->AddRef();
   *pVal = pInterfaceTCPIPPort;

   return S_OK;
}

STDMETHODIMP 
InterfaceTCPIPPorts::DeleteByDBID(long DBID)
{
   m_pTCPIPPorts->DeleteItemByDBID(DBID);
   return S_OK;
}

STDMETHODIMP 
InterfaceTCPIPPorts::get_ItemByDBID(long lDBID, IInterfaceTCPIPPort **pVal)
{
   CComObject<InterfaceTCPIPPort>* pInterfaceTCPIPPort = new CComObject<InterfaceTCPIPPort>();
   pInterfaceTCPIPPort->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::TCPIPPort> pBA = m_pTCPIPPorts->GetItemByDBID(lDBID);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceTCPIPPort->AttachItem(pBA);
   pInterfaceTCPIPPort->AttachParent(m_pTCPIPPorts, true);
   pInterfaceTCPIPPort->AddRef();

   *pVal = pInterfaceTCPIPPort;

   return S_OK;
}

STDMETHODIMP 
InterfaceTCPIPPorts::Add(IInterfaceTCPIPPort **pVal)
{
   if (!m_pTCPIPPorts)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceTCPIPPort>* pInterfaceTCPIPPort = new CComObject<InterfaceTCPIPPort>();
   pInterfaceTCPIPPort->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::TCPIPPort> pBA = shared_ptr<HM::TCPIPPort>(new HM::TCPIPPort);

   pInterfaceTCPIPPort->AttachItem(pBA);
   pInterfaceTCPIPPort->AttachParent(m_pTCPIPPorts, false);

   pInterfaceTCPIPPort->AddRef();

   *pVal = pInterfaceTCPIPPort;

   return S_OK;
}







// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceTCPIPPort.h"
#include "COMError.h"


STDMETHODIMP 
InterfaceTCPIPPort::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceTCPIPPort,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}


STDMETHODIMP 
InterfaceTCPIPPort::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentTCPIPPort::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();
   }

   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::put_Protocol(eSessionType newVal)
{
   m_pObject->SetProtocol((HM::SessionType) newVal);
   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::get_Protocol(eSessionType *pVal)
{
   *pVal = (eSessionType) m_pObject->GetProtocol();

   return S_OK;
}



STDMETHODIMP InterfaceTCPIPPort::put_PortNumber(long newVal)
{
   m_pObject->SetPortNumber(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::get_PortNumber(long *pVal)
{
   *pVal = m_pObject->GetPortNumber();

   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::put_UseSSL(VARIANT_BOOL newVal)
{
   m_pObject->SetUseSSL(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::get_UseSSL(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetUseSSL() ? VARIANT_TRUE : VARIANT_FALSE ;

   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::put_Address(BSTR newVal)
{
   if (!m_pObject->SetAddress(newVal))
      return COMError::GenerateError("Invalid IP address string.");

   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::get_Address(BSTR *pVal)
{
   HM::String sIPAddress = m_pObject->GetAddressString();
   *pVal = sIPAddress.AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::put_SSLCertificateID(long newVal)
{
   m_pObject->SetSSLCertificateID(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::get_SSLCertificateID(long *pVal)
{
   *pVal = (long) m_pObject->GetSSLCertificateID();

   return S_OK;
}

STDMETHODIMP InterfaceTCPIPPort::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentTCPIPPort::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
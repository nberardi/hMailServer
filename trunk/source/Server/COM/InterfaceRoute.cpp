// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceRoute.h"

#include "InterfaceRouteAddresses.h"

#include "../Common/BO/Routes.h"

#include "COMError.h"

STDMETHODIMP InterfaceRoute::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceRoute,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}

STDMETHODIMP InterfaceRoute::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_DomainName(BSTR *pVal)
{
   *pVal = m_pObject->DomainName().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_DomainName(BSTR newVal)
{
   m_pObject->DomainName(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_Description(BSTR *pVal)
{
   *pVal = m_pObject->GetDescription().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_Description(BSTR newVal)
{
   m_pObject->SetDescription(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceRoute::get_TargetSMTPHost(BSTR *pVal)
{
   *pVal = m_pObject->TargetSMTPHost().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_TargetSMTPHost(BSTR newVal)
{
   m_pObject->TargetSMTPHost(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_TargetSMTPPort(long *pVal)
{
   *pVal = m_pObject->TargetSMTPPort();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_TargetSMTPPort(long newVal)
{
   m_pObject->TargetSMTPPort(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_NumberOfTries(long *pVal)
{
   *pVal = m_pObject->NumberOfTries();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_NumberOfTries(long newVal)
{
   m_pObject->NumberOfTries(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_MinutesBetweenTry(long *pVal)
{
   *pVal = m_pObject->MinutesBetweenTry();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_MinutesBetweenTry(long newVal)
{
   m_pObject->MinutesBetweenTry(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRoute::Save()
{
   HM::String sErrorMessage;
   if (HM::PersistentRoute::SaveObject(m_pObject, sErrorMessage))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError(sErrorMessage);
}


STDMETHODIMP InterfaceRoute::get_AllAddresses(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->ToAllAddresses() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_AllAddresses(VARIANT_BOOL newVal)
{
   m_pObject->ToAllAddresses(newVal == VARIANT_TRUE ? true : false);

   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_Addresses(IInterfaceRouteAddresses **pVal)
{
   CComObject<InterfaceRouteAddresses>* pInterfaceAddresses = new CComObject<InterfaceRouteAddresses>;
   pInterfaceAddresses->SetAuthentication(m_pAuthentication);
   
   shared_ptr<HM::RouteAddresses> pAdresses = m_pObject->GetAddresses();

   pInterfaceAddresses->Attach(pAdresses);
   pInterfaceAddresses->AddRef();

   *pVal = pInterfaceAddresses;

   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_RelayerRequiresAuth(VARIANT_BOOL *pVal)
{

   *pVal = m_pObject->GetRelayerRequiresAuth() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_RelayerRequiresAuth(VARIANT_BOOL newVal)
{

   m_pObject->SetRelayerRequiresAuth(newVal == VARIANT_TRUE ? true : false);

   return S_OK;
}

// OBSOLETE: Remove in 6.0
STDMETHODIMP InterfaceRoute::get_TreatSecurityAsLocalDomain(VARIANT_BOOL *pVal)
{

   *pVal = m_pObject->GetTreatRecipientAsLocalDomain() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

// OBSOLETE: Remove in 6.0
STDMETHODIMP InterfaceRoute::put_TreatSecurityAsLocalDomain(VARIANT_BOOL newVal)
{
   m_pObject->SetTreatRecipientAsLocalDomain(newVal == VARIANT_TRUE ? true : false);
   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_TreatSenderAsLocalDomain(VARIANT_BOOL *pVal)
{

   *pVal = m_pObject->GetTreatSenderAsLocalDomain() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_TreatSenderAsLocalDomain(VARIANT_BOOL newVal)
{
   m_pObject->SetTreatSenderAsLocalDomain(newVal == VARIANT_TRUE ? true : false);
   return S_OK;
}



STDMETHODIMP InterfaceRoute::get_TreatRecipientAsLocalDomain(VARIANT_BOOL *pVal)
{

   *pVal = m_pObject->GetTreatRecipientAsLocalDomain() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_TreatRecipientAsLocalDomain(VARIANT_BOOL newVal)
{
   m_pObject->SetTreatRecipientAsLocalDomain(newVal == VARIANT_TRUE ? true : false);
   return S_OK;
}


STDMETHODIMP InterfaceRoute::get_RelayerAuthUsername(BSTR *pVal)
{
   *pVal = m_pObject->GetRelayerAuthUsername().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_RelayerAuthUsername(BSTR newVal)
{
   m_pObject->SetRelayerAuthUsername(HM::String(newVal));
   return S_OK;
}

STDMETHODIMP InterfaceRoute::SetRelayerAuthPassword(BSTR newVal)
{
   m_pObject->SetRelayerAuthPassword(HM::String(newVal));
   return S_OK;
}

STDMETHODIMP InterfaceRoute::get_UseSSL(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetUseSSL() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceRoute::put_UseSSL(VARIANT_BOOL newVal)
{
   m_pObject->SetUseSSL(newVal == VARIANT_TRUE ? true : false);
   return S_OK;
}

STDMETHODIMP InterfaceRoute::Delete()
{
   
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentRoute::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}

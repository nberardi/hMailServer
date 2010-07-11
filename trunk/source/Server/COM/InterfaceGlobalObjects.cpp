// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceGlobalObjects.h"
#include "InterfaceDeliveryQueue.h"
#include "InterfaceLanguages.h"

#include "COMAuthentication.h"

STDMETHODIMP 
InterfaceGlobalObjects::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceGlobalObjects,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}

void
InterfaceGlobalObjects::SetAuthentication(shared_ptr<HM::COMAuthentication> pAuthentication)
{
   m_pAuthentication = pAuthentication;
}


STDMETHODIMP InterfaceGlobalObjects::get_DeliveryQueue(IInterfaceDeliveryQueue **pVal)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceDeliveryQueue>* pInterfaceDeliveryQueue = new CComObject<InterfaceDeliveryQueue>;
   pInterfaceDeliveryQueue->SetAuthentication(m_pAuthentication);

   pInterfaceDeliveryQueue->AddRef();
   *pVal = pInterfaceDeliveryQueue;

   return S_OK;
}

STDMETHODIMP InterfaceGlobalObjects::get_Languages(IInterfaceLanguages **pVal)
{
   CComObject<InterfaceLanguages>* pLanguageInt = new CComObject<InterfaceLanguages>();

   pLanguageInt->AddRef();
   *pVal = pLanguageInt;

   return S_OK;
}

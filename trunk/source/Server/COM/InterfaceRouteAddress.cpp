// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceRouteAddress.h"

#include "../Common/Persistence/PersistentRouteAddress.h"
#include "../Common/BO/RouteAddresses.h"
#include "../Common/BO/RouteAddress.h"

#include "COMError.h"

STDMETHODIMP 
InterfaceRouteAddress::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();
   return S_OK;
}


STDMETHODIMP 
InterfaceRouteAddress::get_RouteID(long *pVal)
{
   *pVal = (long) m_pObject->GetRouteID();
   return S_OK;
}

STDMETHODIMP 
InterfaceRouteAddress::put_RouteID(long newVal)
{
   m_pObject->SetRouteID(newVal);

   return S_OK;
}


STDMETHODIMP 
InterfaceRouteAddress::get_Address(BSTR *pVal)
{


   *pVal = m_pObject->GetAddress().AllocSysString();

   return S_OK;
}

STDMETHODIMP 
InterfaceRouteAddress::put_Address(BSTR newVal)
{
   m_pObject->SetAddress(newVal);

   return S_OK;
}


STDMETHODIMP 
InterfaceRouteAddress::Save()
{
   if (HM::PersistentRouteAddress::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. See hMailServer error log.");
}


STDMETHODIMP InterfaceRouteAddress::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentRouteAddress::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
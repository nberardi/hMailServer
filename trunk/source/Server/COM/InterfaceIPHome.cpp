// InterfaceIPHome.cpp : Implementation of InterfaceIPHome

#include "stdafx.h"
#include "InterfaceIPHome.h"

#include "../Common/Persistence/PersistentIPHome.h"
#include "../Common/BO/IPHome.h"
#include "../Common/BO/IPHomes.h"

#include "COMError.h"

STDMETHODIMP InterfaceIPHome::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentIPHome::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. See hMailServer error log.");
}

STDMETHODIMP InterfaceIPHome::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceIPHome::get_IPAddress(BSTR *pVal)
{
   *pVal = m_pObject->GetIPAddressString().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceIPHome::put_IPAddress(BSTR newVal)
{
   m_pObject->SetIPAddressString(newVal);
   return S_OK;
}

// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceDomainAlias.h"

#include "../Common/BO/DomainAlias.h"
#include "../Common/BO/DomainAliases.h"

#include "../Common/Persistence/PersistentDomainAlias.h"

#include "COMError.h"


STDMETHODIMP InterfaceDomainAlias::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceDomainAlias,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}

STDMETHODIMP InterfaceDomainAlias::get_ID(LONG* pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceDomainAlias::get_DomainID(LONG* pVal)
{
   *pVal = (long) m_pObject->GetDomainID();

   return S_OK;
}

STDMETHODIMP InterfaceDomainAlias::get_AliasName(BSTR* pVal)
{
   *pVal = m_pObject->GetAlias().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceDomainAlias::put_AliasName(BSTR newVal)
{
   m_pObject->SetAlias(newVal);

   return S_OK;
}


STDMETHODIMP InterfaceDomainAlias::Save()
{
   HM::String sErrorMessage;
   if (HM::PersistentDomainAlias::SaveObject(m_pObject, sErrorMessage))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. " +  sErrorMessage);
}

STDMETHODIMP InterfaceDomainAlias::put_DomainID(LONG newVal)
{
   // Only here for backwards compatibility (4.x)
   return S_OK;
}


STDMETHODIMP InterfaceDomainAlias::Delete()
{
   if (!m_pAuthentication->GetIsDomainAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentDomainAlias::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
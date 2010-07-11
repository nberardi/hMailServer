// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceGreyListingWhiteAddress.h"


STDMETHODIMP 
InterfaceGreyListingWhiteAddress::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentGreyListingWhiteAddress::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();
   }

   return S_OK;
}

STDMETHODIMP InterfaceGreyListingWhiteAddress::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceGreyListingWhiteAddress::put_IPAddress(BSTR newVal)
{
   m_pObject->SetUserEditableIPAddress(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceGreyListingWhiteAddress::get_IPAddress(BSTR *pVal)
{
   *pVal = m_pObject->GetUserEditableIPAddress().AllocSysString();

   return S_OK;
}


STDMETHODIMP InterfaceGreyListingWhiteAddress::put_Description(BSTR newVal)
{
   m_pObject->SetDescription(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceGreyListingWhiteAddress::get_Description(BSTR *pVal)
{
   *pVal = m_pObject->GetDescription().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceGreyListingWhiteAddress::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentGreyListingWhiteAddress::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
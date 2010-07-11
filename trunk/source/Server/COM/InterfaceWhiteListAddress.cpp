// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceWhiteListAddress.h"

STDMETHODIMP 
InterfaceWhiteListAddress::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentWhiteListAddress::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();
   }

   return S_OK;
}



STDMETHODIMP InterfaceWhiteListAddress::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentWhiteListAddress::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::put_LowerIPAddress(BSTR newVal)
{
   m_pObject->SetLowerIPAddress(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::get_LowerIPAddress(BSTR *pVal)
{
   *pVal = m_pObject->GetLowerIPAddressString().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::put_UpperIPAddress(BSTR newVal)
{
   m_pObject->SetUpperIPAddress(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::get_UpperIPAddress(BSTR *pVal)
{
   *pVal = m_pObject->GetUpperIPAddressString().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::put_Description(BSTR newVal)
{
   m_pObject->SetDescription(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::get_Description(BSTR *pVal)
{
   *pVal = m_pObject->GetDescription().AllocSysString();
   return S_OK;
}


STDMETHODIMP InterfaceWhiteListAddress::put_EmailAddress(BSTR newVal)
{
   m_pObject->SetUserEditableEMailAddress(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceWhiteListAddress::get_EmailAddress(BSTR *pVal)
{
   *pVal = m_pObject->GetUserEditableEmailAddress().AllocSysString();
   return S_OK;
}
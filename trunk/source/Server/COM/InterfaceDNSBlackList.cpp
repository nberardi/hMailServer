// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceDNSBlackList.h"

#include "..\Common\Persistence\PersistentDNSBlackList.h"

#include "../Common/BO/DNSBlackLists.h"

#include "COMError.h"

STDMETHODIMP 
InterfaceDNSBlackList::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentDNSBlackList::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();
      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. See hMailServer error log.");
}


STDMETHODIMP InterfaceDNSBlackList::get_Active(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetIsActive() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::put_Active(VARIANT_BOOL newVal)
{
   m_pObject->SetIsActive(newVal == VARIANT_TRUE);

   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::put_DNSHost(BSTR newVal)
{
   m_pObject->SetDNSHost(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::get_DNSHost(BSTR *pVal)
{
   *pVal = m_pObject->GetDNSHost().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::put_RejectMessage(BSTR newVal)
{
   m_pObject->SetRejectMessage(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::get_RejectMessage(BSTR *pVal)
{
   *pVal = m_pObject->GetRejectMessage().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::put_ExpectedResult(BSTR newVal)
{
   m_pObject->SetExpectedResult(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::get_ExpectedResult(BSTR *pVal)
{
   *pVal = m_pObject->GetExpectedResult().AllocSysString();

   return S_OK;
}


STDMETHODIMP InterfaceDNSBlackList::put_Score(long newVal)
{
   m_pObject->SetScore(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceDNSBlackList::get_Score(long *pVal)
{
   *pVal = m_pObject->GetScore();

   return S_OK;
}


STDMETHODIMP InterfaceDNSBlackList::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentDNSBlackList::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
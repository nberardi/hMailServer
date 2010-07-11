// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "..\COM\InterfaceBlockedAttachment.h"

#include "..\Common\Persistence\PersistentBlockedAttachment.h"
#include "..\Common\BO\BlockedAttachment.h"

// InterfaceBlockedAttachment

STDMETHODIMP 
InterfaceBlockedAttachment::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentBlockedAttachment::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();
   }

   return S_OK;
}

STDMETHODIMP InterfaceBlockedAttachment::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceBlockedAttachment::put_Wildcard(BSTR newVal)
{
   m_pObject->SetWildcard(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceBlockedAttachment::get_Wildcard(BSTR *pVal)
{
   *pVal = m_pObject->GetWildcard().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceBlockedAttachment::put_Description(BSTR newVal)
{
   m_pObject->SetDescription(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceBlockedAttachment::get_Description(BSTR *pVal)
{
   *pVal = m_pObject->GetDescription().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceBlockedAttachment::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentBlockedAttachment::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
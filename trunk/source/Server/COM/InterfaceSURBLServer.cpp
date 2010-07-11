// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "..\COM\InterfaceSURBLServer.h"

#include "../Common/Persistence/PersistentSURBLServer.h"

#include "COMError.h"

STDMETHODIMP 
InterfaceSURBLServer::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentSURBLServer::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. See hMailServer error log.");
}


STDMETHODIMP InterfaceSURBLServer::get_Active(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetIsActive() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::put_Active(VARIANT_BOOL newVal)
{
   m_pObject->SetIsActive(newVal == VARIANT_TRUE);

   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::put_DNSHost(BSTR newVal)
{
   m_pObject->SetDNSHost(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::get_DNSHost(BSTR *pVal)
{
   *pVal = m_pObject->GetDNSHost().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::put_RejectMessage(BSTR newVal)
{
   m_pObject->SetRejectMessage(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::get_RejectMessage(BSTR *pVal)
{
   *pVal = m_pObject->GetRejectMessage().AllocSysString();

   return S_OK;
}


STDMETHODIMP InterfaceSURBLServer::put_Score(long newVal)
{
   m_pObject->SetScore(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::get_Score(long *pVal)
{
   *pVal = m_pObject->GetScore();

   return S_OK;
}

STDMETHODIMP InterfaceSURBLServer::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentSURBLServer::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
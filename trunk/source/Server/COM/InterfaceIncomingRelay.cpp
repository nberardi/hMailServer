// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceIncomingRelay.h"
#include "../Common/Persistence/PersistentIncomingRelay.h"
#include "../Common/BO/IncomingRelays.h"
#include "../Common/BO/IncomingRelay.h"

#include "COMError.h"

STDMETHODIMP InterfaceIncomingRelay::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (HM::PersistentIncomingRelay::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. See hMailServer error log.");
}


STDMETHODIMP InterfaceIncomingRelay::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceIncomingRelay::get_LowerIP(BSTR *pVal)
{
   *pVal = m_pObject->GetLowerIPString().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceIncomingRelay::put_LowerIP(BSTR newVal)
{
   m_pObject->SetLowerIPString(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceIncomingRelay::get_UpperIP(BSTR *pVal)
{
   *pVal = m_pObject->GetUpperIPString().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceIncomingRelay::put_UpperIP(BSTR newVal)
{
   m_pObject->SetUpperIPString(newVal);

   return S_OK;
}


STDMETHODIMP InterfaceIncomingRelay::get_Name(BSTR *pVal)
{
   *pVal = m_pObject->GetName().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceIncomingRelay::put_Name(BSTR newVal)
{
   m_pObject->SetName(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceIncomingRelay::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentIncomingRelay::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
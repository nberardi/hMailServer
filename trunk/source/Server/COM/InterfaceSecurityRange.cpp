// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceSecurityRange.h"

#include "../Common/Persistence/PersistentSecurityRange.h"
#include "../Common/BO/SecurityRanges.h"
#include "../Common/BO/SecurityRange.h"

#include "COMError.h"


STDMETHODIMP InterfaceSecurityRange::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceSecurityRange,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}


STDMETHODIMP InterfaceSecurityRange::Save()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   HM::String result;
   if (HM::PersistentSecurityRange::SaveObject(m_pObject, result))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError(result);
}


STDMETHODIMP InterfaceSecurityRange::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_LowerIP(BSTR *pVal)
{
   *pVal = m_pObject->GetLowerIPString().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_LowerIP(BSTR newVal)
{
   m_pObject->SetLowerIPString(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_UpperIP(BSTR *pVal)
{
   *pVal = m_pObject->GetUpperIPString().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_UpperIP(BSTR newVal)
{
   m_pObject->SetUpperIPString(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_Priority(long *pVal)
{
   *pVal = m_pObject->GetPriority();

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_Priority(long newVal)
{
   m_pObject->SetPriority(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceSecurityRange::get_AllowPOP3Connections(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetAllowPOP3() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_AllowPOP3Connections(VARIANT_BOOL newVal)
{
   m_pObject->SetAllowPOP3 (newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_AllowSMTPConnections(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetAllowSMTP() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_AllowSMTPConnections(VARIANT_BOOL newVal)
{
   m_pObject->SetAllowSMTP (newVal == VARIANT_TRUE);
   return S_OK;
}


STDMETHODIMP InterfaceSecurityRange::get_AllowIMAPConnections(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetAllowIMAP() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_AllowIMAPConnections(VARIANT_BOOL newVal)
{
   m_pObject->SetAllowIMAP (newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_Name(BSTR *pVal)
{
   *pVal = m_pObject->GetName().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_Name(BSTR newVal)
{
   m_pObject->SetName(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceSecurityRange::get_RequireAuthForDeliveryToLocal(VARIANT_BOOL *pVal)
{
   // OBSOLETE: Removed i 5.1
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_RequireAuthForDeliveryToLocal(VARIANT_BOOL newVal)
{
   // OBSOLETE: Removed i 5.1
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_RequireAuthForDeliveryToRemote(VARIANT_BOOL *pVal)
{
   // OBSOLETE: Removed i 5.1
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_RequireAuthForDeliveryToRemote(VARIANT_BOOL newVal)
{
   // OBSOLETE: Removed i 5.1
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_RequireSMTPAuthLocalToLocal(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetRequireSMTPAuthLocalToLocal() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_RequireSMTPAuthLocalToLocal(VARIANT_BOOL newVal)
{
   m_pObject->SetRequireSMTPAuthLocalToLocal(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_RequireSMTPAuthLocalToExternal(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetRequireSMTPAuthLocalToExternal() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_RequireSMTPAuthLocalToExternal(VARIANT_BOOL newVal)
{
   m_pObject->SetRequireSMTPAuthLocalToExternal(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_RequireSMTPAuthExternalToLocal(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetRequireSMTPAuthExternalToLocal() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_RequireSMTPAuthExternalToLocal(VARIANT_BOOL newVal)
{
   m_pObject->SetRequireSMTPAuthExternalToLocal(newVal == VARIANT_TRUE);
   return S_OK;
}


STDMETHODIMP InterfaceSecurityRange::get_RequireSMTPAuthExternalToExternal(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetRequireSMTPAuthExternalToExternal() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_RequireSMTPAuthExternalToExternal(VARIANT_BOOL newVal)
{
   m_pObject->SetRequireSMTPAuthExternalToExternal(newVal == VARIANT_TRUE);
   return S_OK;
}


STDMETHODIMP InterfaceSecurityRange::get_AllowDeliveryFromLocalToLocal(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetAllowRelayL2L() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_AllowDeliveryFromLocalToLocal(VARIANT_BOOL newVal)
{
   m_pObject->SetAllowRelayL2L(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_AllowDeliveryFromLocalToRemote(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetAllowRelayL2R() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_AllowDeliveryFromLocalToRemote(VARIANT_BOOL newVal)
{
   m_pObject->SetAllowRelayL2R(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_AllowDeliveryFromRemoteToLocal(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetAllowRelayR2L() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_AllowDeliveryFromRemoteToLocal(VARIANT_BOOL newVal)
{
   m_pObject->SetAllowRelayR2L(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_AllowDeliveryFromRemoteToRemote(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetAllowRelayR2R() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_AllowDeliveryFromRemoteToRemote(VARIANT_BOOL newVal)
{
   m_pObject->SetAllowRelayR2R(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_EnableSpamProtection(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetSpamProtection() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_EnableSpamProtection(VARIANT_BOOL newVal)
{
   m_pObject->SetSpamProtection(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_EnableAntiVirus(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetVirusProtection() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_EnableAntiVirus(VARIANT_BOOL newVal)
{
   m_pObject->SetVirusProtection(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_IsForwardingRelay(VARIANT_BOOL *pVal)
{
   // OBSOLETE: Remove in 6.0. No longer used as of 5.1.
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_IsForwardingRelay(VARIANT_BOOL newVal)
{
   // OBSOLETE: Remove in 6.0. No longer used as of 5.1.
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::Delete()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();
   
   if (!m_pParentCollection)
      return HM::PersistentSecurityRange::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_Expires(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetExpires() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_Expires(VARIANT_BOOL newVal)
{
   m_pObject->SetExpires(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::get_ExpiresTime(VARIANT *pVal)
{
   *pVal = m_pObject->GetExpiresTime().GetVariant();
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRange::put_ExpiresTime(VARIANT newVal)
{
  
   m_pObject->SetExpiresTime(newVal);
   return S_OK;
}
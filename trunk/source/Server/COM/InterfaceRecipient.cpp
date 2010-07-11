// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceRecipient.h"


void 
InterfaceRecipient::AttachItem(shared_ptr<HM::MessageRecipient> pRecipient)
{
   m_pObject = pRecipient;
}

STDMETHODIMP 
InterfaceRecipient::get_Address(BSTR *pVal)
{
   *pVal = m_pObject->GetAddress().AllocSysString();
   return S_OK;
}

STDMETHODIMP 
InterfaceRecipient::get_OriginalAddress(BSTR *pVal)
{
   *pVal = m_pObject->GetOriginalAddress().AllocSysString();
   return S_OK;
}

STDMETHODIMP 
InterfaceRecipient::get_IsLocalUser(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetLocalAccountID() > 0 ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}


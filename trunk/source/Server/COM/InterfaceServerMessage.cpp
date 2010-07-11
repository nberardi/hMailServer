// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "..\COM\InterfaceServerMessage.h"

#include "..\Common\Persistence\PersistentServerMessage.h"
#include "..\Common\BO\ServerMessage.h"

#include "COMError.h"

STDMETHODIMP 
InterfaceServerMessage::Save()
{
   if (HM::PersistentServerMessage::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. See hMailServer error log.");
   
}

STDMETHODIMP InterfaceServerMessage::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceServerMessage::put_Name(BSTR newVal)
{
   m_pObject->SetName(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceServerMessage::get_Name(BSTR *pVal)
{
   *pVal = m_pObject->GetName().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceServerMessage::put_Text(BSTR newVal)
{
   m_pObject->SetText(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceServerMessage::get_Text(BSTR *pVal)
{
   *pVal = m_pObject->GetText().AllocSysString();

   return S_OK;
}
// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com



#include "stdafx.h"
#include "InterfaceAlias.h"

#include "../Common/BO/Aliases.h"
#include "../Common/Persistence/PersistentAlias.h"

#include "COMError.h"

#ifdef _DEBUG
long InterfaceAlias::counter = 0;
#endif


STDMETHODIMP InterfaceAlias::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceAlias,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}


STDMETHODIMP InterfaceAlias::get_Active(VARIANT_BOOL *pVal)
{
   *pVal = m_pObject->GetIsActive() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceAlias::put_Active(VARIANT_BOOL newVal)
{
   m_pObject->SetIsActive(newVal == VARIANT_TRUE);
   return S_OK;
}

STDMETHODIMP InterfaceAlias::get_DomainID(long *pVal)
{
   *pVal = (long) m_pObject->GetDomainID();

   return S_OK;
}

STDMETHODIMP InterfaceAlias::put_DomainID(LONG newVal)
{
   // Only here for backwards compatibility (4.x)
   return S_OK;
}


STDMETHODIMP InterfaceAlias::get_Name(BSTR *pVal)
{
   *pVal = m_pObject->GetName().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceAlias::put_Name(BSTR newVal)
{
   m_pObject->SetName(newVal);

   return S_OK;
}


STDMETHODIMP InterfaceAlias::get_Value(BSTR *pVal)
{
   *pVal = m_pObject->GetValue().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceAlias::put_Value(BSTR newVal)
{
   m_pObject->SetValue(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceAlias::Delete()
{
   HM::PersistentAlias::DeleteObject(m_pObject);

   return S_OK;
}

STDMETHODIMP InterfaceAlias::Save()
{
   HM::String sErrorMessage;
   if (HM::PersistentAlias::SaveObject(m_pObject, sErrorMessage))
   {
      // Add to parent collection
      AddToParentCollection();
      return S_OK;
   }

   return COMError::GenerateError("Failed to save object. " +  sErrorMessage);
}



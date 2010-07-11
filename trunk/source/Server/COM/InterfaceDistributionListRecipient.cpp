// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceDistributionListRecipient.h"

#include "../common/persistence/PersistentDistributionListRecipient.h"

#include "../Common/BO/DistributionListRecipients.h"

#include "COMError.h"

STDMETHODIMP InterfaceDistributionListRecipient::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceDistributionListRecipient,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}

STDMETHODIMP InterfaceDistributionListRecipient::get_ID(long *pVal)
{


   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceDistributionListRecipient::put_ID(long newVal)
{


   m_pObject->SetID(newVal);

   return S_OK;
}


STDMETHODIMP InterfaceDistributionListRecipient::get_RecipientAddress(BSTR *pVal)
{


   HM::String sVal = m_pObject->GetAddress();
   *pVal = sVal.AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceDistributionListRecipient::put_RecipientAddress(BSTR newVal)
{


   HM::String sNewVal = newVal;
   m_pObject->SetAddress(sNewVal);

   return S_OK;
}

STDMETHODIMP InterfaceDistributionListRecipient::Delete()
{
   if (!m_pObject)
      return S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}

STDMETHODIMP InterfaceDistributionListRecipient::Save()
{
   if (!m_pObject)
      return S_FALSE;

   HM::String sErrorMessage;
   if (HM::PersistentDistributionListRecipient::SaveObject(m_pObject, sErrorMessage))
   {
      AddToParentCollection();

      return S_OK;
   }

   return COMError::GenerateError(sErrorMessage);
}

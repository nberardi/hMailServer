// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "InterfaceGroup.h"
#include "InterfaceGroups.h"
#include "InterfaceGroupMembers.h"

#include "../Common/Persistence/PersistentGroup.h"
#include "../Common/BO/Group.h"
#include "../Common/BO/Groups.h"

#include "COMError.h"

STDMETHODIMP InterfaceGroup::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceGroup,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}


STDMETHODIMP 
InterfaceGroup::Save()
{
   HM::String sErrorMessage;
   if (HM::PersistentGroup::SaveObject(m_pObject, sErrorMessage))
   {
      // Add to parent collection
      AddToParentCollection();
      return S_OK;
   }
   
   return COMError::GenerateError("Failed to save object. " +  sErrorMessage);
}

STDMETHODIMP InterfaceGroup::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceGroup::get_Name(BSTR *pVal)
{
   *pVal = m_pObject->GetName().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceGroup::put_Name(BSTR sVal)
{
   m_pObject->SetName(sVal);
   return S_OK;
}

STDMETHODIMP InterfaceGroup::get_Members(IInterfaceGroupMembers **pVal)
{

   CComObject<InterfaceGroupMembers>* pItem = new CComObject<InterfaceGroupMembers>();
   pItem->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::GroupMembers> pGM = m_pObject->GetMembers();

   if (pGM)
   {
      pItem->Attach(pGM);
      pItem->AddRef();
      *pVal = pItem;
   }


   return S_OK;
}


STDMETHODIMP InterfaceGroup::Delete()
{
   if (!m_pAuthentication->GetIsDomainAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentGroup::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
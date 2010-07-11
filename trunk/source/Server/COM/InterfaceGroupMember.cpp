// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceGroupMember.h"
#include "InterfaceAccount.h"

#include "../Common/BO/GroupMember.h"
#include "../Common/BO/GroupMembers.h"
#include "../Common/BO/Account.h"
#include "../Common/Cache/CacheContainer.h"
#include "../Common/Persistence/PersistentGroupMember.h"
#include "../Common/Persistence/PersistentAccount.h"


STDMETHODIMP 
InterfaceGroupMember::Save()
{
   if (HM::PersistentGroupMember::SaveObject(m_pObject))
   {
      // Add to parent collection
      AddToParentCollection();
   }

   return S_OK;
}

STDMETHODIMP InterfaceGroupMember::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();

   return S_OK;
}

STDMETHODIMP InterfaceGroupMember::get_GroupID(long *pVal)
{
   *pVal = (long) m_pObject->GetGroupID();

   return S_OK;
}

STDMETHODIMP InterfaceGroupMember::put_GroupID(long iVal)
{
   m_pObject->SetGroupID(iVal);

   return S_OK;
}

STDMETHODIMP InterfaceGroupMember::get_AccountID(long *pVal)
{
   *pVal = (long) m_pObject->GetAccountID();

   return S_OK;
}

STDMETHODIMP InterfaceGroupMember::put_AccountID(long iVal)
{
   m_pObject->SetAccountID(iVal);

   return S_OK;
}

STDMETHODIMP 
InterfaceGroupMember::get_Account(IInterfaceAccount **pVal)
{
   CComObject<InterfaceAccount>* pInterfaceAccount = new CComObject<InterfaceAccount>();
   pInterfaceAccount->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Account> pAccount = shared_ptr<HM::Account>(new HM::Account);
      
   if (!HM::PersistentAccount::ReadObject(pAccount, (__int64) m_pObject->GetAccountID()))
      return DISP_E_BADINDEX;

   pInterfaceAccount->AttachItem(pAccount);
   pInterfaceAccount->AddRef();
   *pVal = pInterfaceAccount;

   return S_OK;
}


STDMETHODIMP InterfaceGroupMember::Delete()
{
   if (!m_pAuthentication->GetIsDomainAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pParentCollection)
      return HM::PersistentGroupMember::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}
// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceGroupMembers.h"

#include "..\Common\BO\GroupMember.h"
#include "..\Common\BO\GroupMembers.h"

#include "InterfaceGroupMember.h"

void 
InterfaceGroupMembers::Attach(shared_ptr<HM::GroupMembers> pBA) 
{ 
   m_pGroupMembers = pBA; 
}

STDMETHODIMP 
InterfaceGroupMembers::Refresh()
{
   if (!m_pGroupMembers)
      return S_FALSE;

   m_pGroupMembers->Refresh();

   return S_OK;
}


STDMETHODIMP InterfaceGroupMembers::get_Count(long *pVal)
{
   *pVal = m_pGroupMembers->GetCount();

   return S_OK;
}

STDMETHODIMP 
InterfaceGroupMembers::get_Item(long Index, IInterfaceGroupMember **pVal)
{
   CComObject<InterfaceGroupMember>* pInterfaceGroupMember = new CComObject<InterfaceGroupMember>();
   pInterfaceGroupMember->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::GroupMember> pBA = m_pGroupMembers->GetItem(Index);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceGroupMember->AttachItem(pBA);
   pInterfaceGroupMember->AttachParent(m_pGroupMembers, true);
   pInterfaceGroupMember->AddRef();
   *pVal = pInterfaceGroupMember;

   return S_OK;
}

STDMETHODIMP 
InterfaceGroupMembers::DeleteByDBID(long DBID)
{
   m_pGroupMembers->DeleteItemByDBID(DBID);
   return S_OK;
}

STDMETHODIMP 
InterfaceGroupMembers::get_ItemByDBID(long lDBID, IInterfaceGroupMember **pVal)
{
   CComObject<InterfaceGroupMember>* pInterfaceGroupMember = new CComObject<InterfaceGroupMember>();
   pInterfaceGroupMember->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::GroupMember> pBA = m_pGroupMembers->GetItemByDBID(lDBID);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceGroupMember->AttachItem(pBA);
   pInterfaceGroupMember->AttachParent(m_pGroupMembers, true);
   pInterfaceGroupMember->AddRef();

   *pVal = pInterfaceGroupMember;

   return S_OK;
}

STDMETHODIMP 
InterfaceGroupMembers::Add(IInterfaceGroupMember **pVal)
{
   if (!m_pGroupMembers)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceGroupMember>* pInterfaceGroupMember = new CComObject<InterfaceGroupMember>();
   pInterfaceGroupMember->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::GroupMember> pBA = shared_ptr<HM::GroupMember>(new HM::GroupMember);
   pBA->SetGroupID(m_pGroupMembers->GetGroupID());

   pInterfaceGroupMember->AttachItem(pBA);
   pInterfaceGroupMember->AttachParent(m_pGroupMembers, false);

   pInterfaceGroupMember->AddRef();

   *pVal = pInterfaceGroupMember;

   return S_OK;
}






// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceGroups.h"

#include "..\Common\BO\Group.h"
#include "..\Common\BO\Groups.h"

#include "InterfaceGroup.h"

void 
InterfaceGroups::Attach(shared_ptr<HM::Groups> pBA) 
{ 
   m_pGroups = pBA; 
}

STDMETHODIMP 
InterfaceGroups::Refresh()
{
   if (!m_pGroups)
      return S_FALSE;

   m_pGroups->Refresh();

   return S_OK;
}


STDMETHODIMP InterfaceGroups::get_Count(long *pVal)
{
   *pVal = m_pGroups->GetCount();

   return S_OK;
}

STDMETHODIMP 
InterfaceGroups::get_Item(long Index, IInterfaceGroup **pVal)
{
   CComObject<InterfaceGroup>* pInterfaceGroup = new CComObject<InterfaceGroup>();
   pInterfaceGroup->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Group> pBA = m_pGroups->GetItem(Index);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceGroup->AttachItem(pBA);
   pInterfaceGroup->AttachParent(m_pGroups, true);
   pInterfaceGroup->AddRef();
   *pVal = pInterfaceGroup;

   return S_OK;
}

STDMETHODIMP 
InterfaceGroups::DeleteByDBID(long DBID)
{
   m_pGroups->DeleteItemByDBID(DBID);
   return S_OK;
}

STDMETHODIMP 
InterfaceGroups::get_ItemByDBID(long lDBID, IInterfaceGroup **pVal)
{
   CComObject<InterfaceGroup>* pInterfaceGroup = new CComObject<InterfaceGroup>();
   pInterfaceGroup->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Group> pBA = m_pGroups->GetItemByDBID(lDBID);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceGroup->AttachItem(pBA);
   pInterfaceGroup->AttachParent(m_pGroups, true);
   pInterfaceGroup->AddRef();

   *pVal = pInterfaceGroup;

   return S_OK;
}

STDMETHODIMP 
InterfaceGroups::get_ItemByName(BSTR sName, IInterfaceGroup **pVal)
{
   CComObject<InterfaceGroup>* pInterfaceGroup = new CComObject<InterfaceGroup>();
   pInterfaceGroup->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Group> pBA = m_pGroups->GetItemByName(sName);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceGroup->AttachItem(pBA);
   pInterfaceGroup->AttachParent(m_pGroups, true);
   pInterfaceGroup->AddRef();

   *pVal = pInterfaceGroup;

   return S_OK;
}

STDMETHODIMP 
InterfaceGroups::Add(IInterfaceGroup **pVal)
{
   if (!m_pGroups)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceGroup>* pInterfaceGroup = new CComObject<InterfaceGroup>();
   pInterfaceGroup->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Group> pBA = shared_ptr<HM::Group>(new HM::Group);

   pInterfaceGroup->AttachItem(pBA);
   pInterfaceGroup->AttachParent(m_pGroups, false);

   pInterfaceGroup->AddRef();

   *pVal = pInterfaceGroup;

   return S_OK;
}






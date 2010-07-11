// InterfaceIPHomes.cpp : Implementation of InterfaceIPHomes

#include "stdafx.h"
#include "InterfaceIPHomes.h"

#include "../Common/Persistence/PersistentIPHome.h"
#include "../Common/BO/IPHome.h"

#include "InterfaceIPHome.h"

#include "../Common/Cache/SingleObjectCache.h"

bool 
InterfaceIPHomes::LoadSettings()
{
   if (!GetIsServerAdmin())
      return false;

   m_pIPHomes = HM::SingleObjectCache<HM::IPHomes>::Instance()->GetObject();

   return true;
}

STDMETHODIMP 
InterfaceIPHomes::get_Count(long *pVal)
{
   *pVal = m_pIPHomes->GetCount();
   return S_OK;
}

STDMETHODIMP 
InterfaceIPHomes::DeleteByDBID(long DBID)
{
   m_pIPHomes->DeleteItemByDBID(DBID);
   return S_OK;
}


STDMETHODIMP InterfaceIPHomes::Refresh()
{
   m_pIPHomes->Refresh();
   return S_OK;
}

STDMETHODIMP InterfaceIPHomes::get_Item(long Index, IInterfaceIPHome **pVal)
{
   CComObject<InterfaceIPHome>* pIPHomeInt = new CComObject<InterfaceIPHome>();
   pIPHomeInt->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::IPHome> pIPHome = m_pIPHomes->GetItem(Index);

   if (!pIPHome)
      return DISP_E_BADINDEX;  

   pIPHomeInt->AttachItem(pIPHome);
   pIPHomeInt->AddRef();
   *pVal = pIPHomeInt;

   return S_OK;
}

STDMETHODIMP InterfaceIPHomes::get_ItemByDBID(long DBID, IInterfaceIPHome **pVal)
{
   CComObject<InterfaceIPHome>* pIPHomeInt = new CComObject<InterfaceIPHome>();
   pIPHomeInt->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::IPHome> pIPHome = m_pIPHomes->GetItemByDBID(DBID);

   if (!pIPHome)
      return DISP_E_BADINDEX;  

   pIPHomeInt->AttachItem(pIPHome);
   pIPHomeInt->AddRef();
   *pVal = pIPHomeInt;

   return S_OK;
}


STDMETHODIMP InterfaceIPHomes::Add(IInterfaceIPHome **pVal)
{
   if (!m_pIPHomes)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceIPHome>* pInterfaceIPHome = new CComObject<InterfaceIPHome>();
   pInterfaceIPHome->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::IPHome> pIPHome = shared_ptr<HM::IPHome>(new HM::IPHome); 

   pInterfaceIPHome->AttachItem(pIPHome);
   pInterfaceIPHome->AttachParent(m_pIPHomes, false);
   pInterfaceIPHome->AddRef();

   *pVal = pInterfaceIPHome;

   return S_OK;
}

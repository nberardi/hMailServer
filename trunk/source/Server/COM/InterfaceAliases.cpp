// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "InterfaceAliases.h"
#include "InterfaceAlias.h"

void
InterfaceAliases::Attach(shared_ptr<HM::Aliases> pAliases)
{
   m_pAliases = pAliases;
} 

STDMETHODIMP InterfaceAliases::get_Count(long *pVal)
{
   *pVal = (int) m_pAliases->GetCount();
   return S_OK;
}


STDMETHODIMP InterfaceAliases::Delete(long Index)
{
   m_pAliases->DeleteItem(Index);
   return S_OK;
}

STDMETHODIMP InterfaceAliases::Refresh()
{
   m_pAliases->Refresh();
   return S_OK;
}

STDMETHODIMP InterfaceAliases::get_Item(long Index, IInterfaceAlias **pVal)
{
   CComObject<InterfaceAlias>* pAlias = new CComObject<InterfaceAlias>();
   pAlias->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Alias> pPersAlias = m_pAliases->GetItem(Index);

   if (!pPersAlias)
      return DISP_E_BADINDEX;  

   pAlias->AttachItem(pPersAlias);
   pAlias->AddRef();
   *pVal = pAlias;
   return S_OK;
}

STDMETHODIMP InterfaceAliases::Add(IInterfaceAlias **pVal)
{
   if (!m_pAuthentication->GetIsDomainAdmin())
      return m_pAuthentication->GetAccessDenied();

   if (!m_pAliases)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceAlias>* pIntAlias = new CComObject<InterfaceAlias>();
   pIntAlias->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Alias> pAliasADO = shared_ptr<HM::Alias>(new HM::Alias);
   
   pIntAlias->AttachItem(pAliasADO);
   pIntAlias->AttachParent(m_pAliases, false);

   pAliasADO->SetDomainID(m_iDomainID);

   pIntAlias->AddRef();
   *pVal = pIntAlias;

   return S_OK;
}

STDMETHODIMP InterfaceAliases::get_ItemByDBID(long DBID, IInterfaceAlias **pVal)
{
   CComObject<InterfaceAlias>* pAlias = new CComObject<InterfaceAlias>();
   pAlias->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Alias> pPersAlias = m_pAliases->GetItemByDBID(DBID);

   if (pPersAlias)
   {
      pAlias->AttachItem(pPersAlias);
      pAlias->AddRef();
      *pVal = pAlias;
   }
   else
   {
      return DISP_E_BADINDEX;  
   }


   return S_OK;
}


STDMETHODIMP InterfaceAliases::DeleteByDBID(long DBID)
{

   if (m_pAliases)
      m_pAliases->DeleteItemByDBID(DBID);

   return S_OK;
}

STDMETHODIMP InterfaceAliases::get_ItemByName(BSTR Name, IInterfaceAlias **pVal)
{
   CComObject<InterfaceAlias>* pAlias = new CComObject<InterfaceAlias>();
   pAlias->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Alias> pPersAlias = m_pAliases->GetItemByName(Name);

   if (pPersAlias)
   {
      pAlias->AttachItem(pPersAlias);
      pAlias->AddRef();
      *pVal = pAlias;
   }
   else
   {
      return DISP_E_BADINDEX;  
   }


   return S_OK;
}


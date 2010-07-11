// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceSecurityRanges.h"

#include "../Common/Persistence/PersistentSecurityRange.h"

#include "InterfaceSecurityRange.h"

bool 
InterfaceSecurityRanges::LoadSettings()
{
   if (!GetIsServerAdmin())
      return false;

   m_pSecurityRanges = shared_ptr<HM::SecurityRanges> (new HM::SecurityRanges);
   m_pSecurityRanges->Refresh();

   return true;
}


STDMETHODIMP 
InterfaceSecurityRanges::get_Count(long *pVal)
{
   *pVal = m_pSecurityRanges->GetCount();
   return S_OK;
}

STDMETHODIMP 
InterfaceSecurityRanges::Delete(long Index)
{
   m_pSecurityRanges->DeleteItem(Index);
   return S_OK;
}

STDMETHODIMP 
InterfaceSecurityRanges::DeleteByDBID(long DBID)
{
   m_pSecurityRanges->DeleteItemByDBID(DBID);
   return S_OK;
}


STDMETHODIMP InterfaceSecurityRanges::Refresh()
{
   m_pSecurityRanges->Refresh();
   return S_OK;
}

STDMETHODIMP InterfaceSecurityRanges::get_Item(long Index, IInterfaceSecurityRange **pVal)
{
   CComObject<InterfaceSecurityRange>* pRangeInt = new CComObject<InterfaceSecurityRange>();
   pRangeInt->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::SecurityRange> pRange = m_pSecurityRanges->GetItem(Index);

   if (pRange)
   {
      pRangeInt->AttachItem(pRange);
      pRangeInt->AttachParent(m_pSecurityRanges, true);
      pRangeInt->AddRef();
      *pVal = pRangeInt;
   }
   else
   {
      return DISP_E_BADINDEX;  
   }



   return S_OK;
}

STDMETHODIMP InterfaceSecurityRanges::get_ItemByDBID(long DBID, IInterfaceSecurityRange **pVal)
{
   CComObject<InterfaceSecurityRange>* pRangeInt = new CComObject<InterfaceSecurityRange>();
   pRangeInt->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::SecurityRange> pRange = m_pSecurityRanges->GetItemByDBID(DBID);

   if (pRange)
   {
      pRangeInt->AttachItem(pRange);
      pRangeInt->AttachParent(m_pSecurityRanges, true);
      pRangeInt->AddRef();
      *pVal = pRangeInt;
   }
   else
   {
      return DISP_E_BADINDEX;  
   }

   return S_OK;
}


STDMETHODIMP InterfaceSecurityRanges::Add(IInterfaceSecurityRange **pVal)
{
   if (!m_pSecurityRanges)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceSecurityRange>* pInterfaceRange = new CComObject<InterfaceSecurityRange>();
   pInterfaceRange->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::SecurityRange> pRange = shared_ptr<HM::SecurityRange>(new HM::SecurityRange); 

   pInterfaceRange->AttachItem(pRange);
   pInterfaceRange->AttachParent(m_pSecurityRanges, false);

   pInterfaceRange->AddRef();
   *pVal = pInterfaceRange;

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRanges::get_ItemByName(BSTR sName, IInterfaceSecurityRange **pVal)
{
   CComObject<InterfaceSecurityRange>* pRangeInt = new CComObject<InterfaceSecurityRange>();
   pRangeInt->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::SecurityRange> pRange = m_pSecurityRanges->GetItemByName(sName);

   if (pRange)
   {
      pRangeInt->AttachItem(pRange);
      pRangeInt->AttachParent(m_pSecurityRanges, true);
      pRangeInt->AddRef();
      *pVal = pRangeInt;
   }
   else
   {
      return DISP_E_BADINDEX;  
   }

   return S_OK;
}

STDMETHODIMP InterfaceSecurityRanges::SetDefault()
{
   if (!m_pSecurityRanges)
      return m_pAuthentication->GetAccessDenied();

   m_pSecurityRanges->SetDefault();

   return S_OK;
}


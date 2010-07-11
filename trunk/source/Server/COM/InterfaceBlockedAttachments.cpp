// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "..\COM\InterfaceBlockedAttachments.h"

#include "..\Common\BO\BlockedAttachment.h"
#include "InterfaceBlockedAttachment.h"

void 
InterfaceBlockedAttachments::Attach(shared_ptr<HM::BlockedAttachments> pBA) 
{ 
   m_pBlockedAttachments = pBA; 
}

STDMETHODIMP 
InterfaceBlockedAttachments::Refresh()
{
   if (!m_pBlockedAttachments)
      return S_FALSE;

   m_pBlockedAttachments->Refresh();

   return S_OK;
}


STDMETHODIMP InterfaceBlockedAttachments::get_Count(long *pVal)
{
   *pVal = m_pBlockedAttachments->GetCount();

   return S_OK;
}

STDMETHODIMP 
InterfaceBlockedAttachments::get_Item(long Index, IInterfaceBlockedAttachment **pVal)
{
   CComObject<InterfaceBlockedAttachment>* pInterfaceBlockedAttachment = new CComObject<InterfaceBlockedAttachment>();
   pInterfaceBlockedAttachment->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::BlockedAttachment> pBA = m_pBlockedAttachments->GetItem(Index);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceBlockedAttachment->AttachItem(pBA);
   pInterfaceBlockedAttachment->AttachParent(m_pBlockedAttachments, true);
   pInterfaceBlockedAttachment->AddRef();
   *pVal = pInterfaceBlockedAttachment;

   return S_OK;
}

STDMETHODIMP 
InterfaceBlockedAttachments::DeleteByDBID(long DBID)
{
   m_pBlockedAttachments->DeleteItemByDBID(DBID);
   return S_OK;
}

STDMETHODIMP 
InterfaceBlockedAttachments::get_ItemByDBID(long lDBID, IInterfaceBlockedAttachment **pVal)
{
   CComObject<InterfaceBlockedAttachment>* pInterfaceBlockedAttachment = new CComObject<InterfaceBlockedAttachment>();
   pInterfaceBlockedAttachment->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::BlockedAttachment> pBA = m_pBlockedAttachments->GetItemByDBID(lDBID);

   if (!pBA)
      return DISP_E_BADINDEX;

   pInterfaceBlockedAttachment->AttachItem(pBA);
   pInterfaceBlockedAttachment->AttachParent(m_pBlockedAttachments, true);
   pInterfaceBlockedAttachment->AddRef();

   *pVal = pInterfaceBlockedAttachment;

   return S_OK;
}

STDMETHODIMP 
InterfaceBlockedAttachments::Add(IInterfaceBlockedAttachment **pVal)
{
   if (!m_pBlockedAttachments)
      return m_pAuthentication->GetAccessDenied();

   CComObject<InterfaceBlockedAttachment>* pInterfaceBlockedAttachment = new CComObject<InterfaceBlockedAttachment>();
   pInterfaceBlockedAttachment->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::BlockedAttachment> pBA = shared_ptr<HM::BlockedAttachment>(new HM::BlockedAttachment);

   pInterfaceBlockedAttachment->AttachItem(pBA);
   pInterfaceBlockedAttachment->AttachParent(m_pBlockedAttachments, false);

   pInterfaceBlockedAttachment->AddRef();

   *pVal = pInterfaceBlockedAttachment;

   return S_OK;
}






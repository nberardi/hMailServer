// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "InterfaceAttachments.h"
#include "InterfaceAttachment.h"

#include "COMError.h"

STDMETHODIMP InterfaceAttachments::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceAttachments,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}


void
InterfaceAttachments::Attach(shared_ptr<HM::Attachments> pAttachments)
{
   m_pAttachments = pAttachments;
}

STDMETHODIMP InterfaceAttachments::get_Count(long *pVal)
{
   *pVal = (int) m_pAttachments->GetCount();
   return S_OK;
}

STDMETHODIMP InterfaceAttachments::get_Item(long Index, IInterfaceAttachment **pVal)
{
   CComObject<InterfaceAttachment>* pInterfaceAttachment = new CComObject<InterfaceAttachment>();
   pInterfaceAttachment->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::Attachment> pAttachment = m_pAttachments->GetItem(Index);

   if (!pAttachment)
      return DISP_E_BADINDEX;  

   pInterfaceAttachment->Attach(pAttachment);
   pInterfaceAttachment->AddRef();
   *pVal = pInterfaceAttachment;

   return S_OK;
}


STDMETHODIMP 
InterfaceAttachments::Clear()
{
   m_pAttachments->Clear();
   return S_OK;
}

STDMETHODIMP 
InterfaceAttachments::Add(BSTR sFilename)
{
   if (!m_pAttachments->Add(sFilename))
   {
      return COMError::GenerateError("Failed to attach file.");
   }

   return S_OK;
}


// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceAttachment.h"

void 
InterfaceAttachment::Attach(shared_ptr<HM::Attachment> pAttachment) 
{ 

   m_pAttachment = pAttachment; 
}

STDMETHODIMP InterfaceAttachment::get_Filename(BSTR *pVal)
{
   *pVal = m_pAttachment->GetFileName().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceAttachment::get_Size(long *pVal)
{
   *pVal = m_pAttachment->GetSize();
   return S_OK;
}

STDMETHODIMP InterfaceAttachment::SaveAs(BSTR sName)
{
   m_pAttachment->SaveAs(sName);
   return S_OK;
}


STDMETHODIMP 
InterfaceAttachment::Delete()
{
   m_pAttachment->Delete();
   return S_OK;
}

// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "..\COM\InterfaceResult.h"


// InterfaceResult

void 
InterfaceResult::AttachItem(shared_ptr<HM::Result> pResult)
{
   m_pResult = pResult;
}

STDMETHODIMP InterfaceResult::get_Value(long *pVal)
{
   *pVal = m_pResult->GetValue();
   return S_OK;
}

STDMETHODIMP InterfaceResult::put_Value(long newVal)
{
   m_pResult->SetValue(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceResult::get_Parameter(long *pVal)
{
   *pVal = m_pResult->GetParameter();
   return S_OK;
}

STDMETHODIMP InterfaceResult::put_Parameter(long newVal)
{
   m_pResult->SetParameter(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceResult::get_Message(BSTR *pVal)
{
   *pVal = m_pResult->GetMessage().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceResult::put_Message(BSTR newVal)
{
   m_pResult->SetMessage(newVal);
   return S_OK;
}
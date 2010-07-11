// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceLanguage.h"
#include "../Common/Util/Language.h"
#include "COMError.h"

void 
InterfaceLanguage::Attach(shared_ptr<HM::Language> pLanguage)
{
   m_pLanguage = pLanguage;
}

STDMETHODIMP InterfaceLanguage::get_Name(BSTR *pVal)
{
   HM::String sName = m_pLanguage->GetName();
   *pVal = sName.AllocSysString();

   return S_OK;
}


STDMETHODIMP InterfaceLanguage::get_String(BSTR EnglishString, BSTR *pVal)
{
   HM::String sText = m_pLanguage->GetString(EnglishString);
   *pVal = sText.AllocSysString();

   return S_OK;
}


STDMETHODIMP InterfaceLanguage::get_IsDownloaded(VARIANT_BOOL *pVal)
{
   *pVal = m_pLanguage->GetIsDownloded() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceLanguage::Download()
{
   // m_pLanguage->Download();   

   return COMError::GenerateError("Not implemented.");
}

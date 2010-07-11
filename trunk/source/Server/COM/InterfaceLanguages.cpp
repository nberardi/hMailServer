// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "InterfaceLanguages.h"
#include "InterfaceLanguage.h"

#include "../Common/Util/Languages.h"

STDMETHODIMP InterfaceLanguages::get_Count(long *pVal)
{
   *pVal = HM::Languages::Instance()->GetCount();

   return S_OK;
}


STDMETHODIMP InterfaceLanguages::get_ItemByName(BSTR ItemName, IInterfaceLanguage **pVal)
{
   CComObject<InterfaceLanguage>* pInterfaceLanguage = new CComObject<InterfaceLanguage>();

   shared_ptr<HM::Language> pLanguage = HM::Languages::Instance()->GetLanguage(ItemName);

   if (!pLanguage)
      return DISP_E_BADINDEX;

   pInterfaceLanguage->Attach(pLanguage);
   pInterfaceLanguage->AddRef();

   *pVal = pInterfaceLanguage;

   return S_OK;
}

STDMETHODIMP InterfaceLanguages::get_Item(long Index, IInterfaceLanguage **pVal)
{
   CComObject<InterfaceLanguage>* pInterfaceLanguage = new CComObject<InterfaceLanguage>();

   shared_ptr<HM::Language> pLanguage = HM::Languages::Instance()->GetLanguage(Index);

   if (!pLanguage)
      return DISP_E_BADINDEX;

   pInterfaceLanguage->Attach(pLanguage);
   pInterfaceLanguage->AddRef();

   *pVal = pInterfaceLanguage;


   return S_OK;
}

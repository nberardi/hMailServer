// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceDiagnostics.h"
#include "InterfaceDiagnosticResults.h"


// InterfaceDiagnostics

STDMETHODIMP InterfaceDiagnostics::PerformTests(IInterfaceDiagnosticResults **pVal)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   HM::String str;
   
   vector<HM::DiagnosticResult> results = _diagnostics.PerformTests();
   
   CComObject<InterfaceDiagnosticResults>* pResult = new CComObject<InterfaceDiagnosticResults>();
   pResult->SetAuthentication(m_pAuthentication);
   pResult->AttachResults(results);
   pResult->AddRef();
   *pVal = pResult;

   return S_OK;
}

STDMETHODIMP InterfaceDiagnostics::get_LocalDomainName(BSTR *pVal)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   *pVal = _diagnostics.GetLocalDomain().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceDiagnostics::put_LocalDomainName(BSTR newVal)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   HM::String localDomainName = newVal;
   _diagnostics.SetLocalDomain(localDomainName);

   return S_OK;
}

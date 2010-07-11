// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceDirectories.h"

STDMETHODIMP InterfaceDirectories::get_ProgramDirectory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetProgramDirectory().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::put_ProgramDirectory(BSTR newVal)
{
   m_pIniFileSettings->SetProgramDirectory(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceDirectories::get_DatabaseDirectory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetDatabaseDirectory().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::put_DatabaseDirectory(BSTR newVal)
{
   m_pIniFileSettings->SetDatabaseDirectory(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceDirectories::get_DataDirectory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetDataDirectory().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::put_DataDirectory(BSTR newVal)
{
   m_pIniFileSettings->SetDataDirectory(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::get_LogDirectory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetLogDirectory().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::put_LogDirectory(BSTR newVal)
{
   m_pIniFileSettings->SetLogDirectory(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::get_TempDirectory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetTempDirectory().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::put_TempDirectory(BSTR newVal)
{
   m_pIniFileSettings->SetTempDirectory(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceDirectories::get_EventDirectory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetEventDirectory().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceDirectories::put_EventDirectory(BSTR newVal)
{
   m_pIniFileSettings->SetEventDirectory(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceDirectories::get_DBScriptDirectory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetDBScriptDirectory().AllocSysString();
   return S_OK;
}
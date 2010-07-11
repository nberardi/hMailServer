

#include "stdafx.h"

#include "InterfaceLogging.h"

bool 
InterfaceLogging::LoadSettings()
{
   if (!GetIsServerAdmin())
      return false;

   m_pConfig = HM::Configuration::Instance();
   m_pIniFileSettings = HM::IniFileSettings::Instance();

   return true;
}


STDMETHODIMP
InterfaceLogging::get_Enabled(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetUseLogging() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP
InterfaceLogging::put_Enabled(VARIANT_BOOL newVal)
{
   m_pConfig->SetUseLogging(newVal == VARIANT_TRUE);
   
   return S_OK;
}

STDMETHODIMP
InterfaceLogging::get_LogSMTP(VARIANT_BOOL *pVal)
{
   if (m_pConfig->GetLogSMTPConversations() )
      *pVal = VARIANT_TRUE;
   else
      *pVal = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::put_LogSMTP(VARIANT_BOOL newVal)
{
   m_pConfig->SetLogSMTPConversations(newVal == VARIANT_TRUE);

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::get_LogPOP3(VARIANT_BOOL *pVal)
{
   if (m_pConfig->GetLogPOP3Conversations() )
      *pVal = VARIANT_TRUE;
   else
      *pVal = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::put_LogPOP3(VARIANT_BOOL newVal)
{
   m_pConfig->SetLogPOP3Conversations(newVal == VARIANT_TRUE);

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::get_LogIMAP(VARIANT_BOOL *pVal)
{


   if (m_pConfig->GetLogIMAPConversations() )
      *pVal = VARIANT_TRUE;
   else
      *pVal = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::put_LogIMAP(VARIANT_BOOL newVal)
{
   m_pConfig->SetLogIMAPConversations(newVal == VARIANT_TRUE);

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::get_AWStatsEnabled(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetAWStatsEnabled() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::put_AWStatsEnabled(VARIANT_BOOL newVal)
{
   m_pConfig->SetAWStatsEnabled(newVal == VARIANT_TRUE);

   return S_OK;
}
STDMETHODIMP
InterfaceLogging::get_LogTCPIP(VARIANT_BOOL *pVal)
{
   if (m_pConfig->GetLogTCPIP() )
      *pVal = VARIANT_TRUE;
   else
      *pVal = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::put_LogTCPIP(VARIANT_BOOL newVal)
{
   m_pConfig->SetLogTCPIP(newVal == VARIANT_TRUE);

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::get_LogApplication(VARIANT_BOOL *pVal)
{


   if (m_pConfig->GetLogApplication())
      *pVal = VARIANT_TRUE;
   else
      *pVal = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP
InterfaceLogging::put_LogApplication(VARIANT_BOOL newVal)
{
   m_pConfig->SetLogApplication(newVal == VARIANT_TRUE);

   return S_OK;
}


STDMETHODIMP 
InterfaceLogging::EnableLiveLogging(VARIANT_BOOL newVal)
{
   HM::Logger::Instance()->EnableLiveLogging(newVal == VARIANT_TRUE);

   return S_OK;
}

STDMETHODIMP InterfaceLogging::get_Device(eLogDevice *pVal)
{

   *pVal = _INTLogDevice2COMLogDevice(m_pConfig->GetLogDevice());
   return S_OK;
}

STDMETHODIMP InterfaceLogging::put_Device(eLogDevice newVal)
{


   m_pConfig->SetLogDevice (_COMLogDevice2INTLogDevice((newVal)));
   return S_OK;
}

int
InterfaceLogging::_COMLogDevice2INTLogDevice(eLogDevice newVal)
{
   switch (newVal)
   {
   case hLogDeviceUnknown:
      return 0;
      break;
   case hLogDeviceSQL:
      return 1;
      break;
   case hLogDeviceFile:
      return 2;
      break;
   default:
      return 0;
      break;
   }
}

eLogDevice
InterfaceLogging::_INTLogDevice2COMLogDevice(int RelayMode)
{
   switch (RelayMode)
   {
   case 0:
      return hLogDeviceUnknown;
      break;
   case 1:
      return hLogDeviceSQL;
      break;
   case 2:
      return hLogDeviceFile;
      break;
   default:
      return hLogDeviceUnknown;
      break;
   }
}

STDMETHODIMP InterfaceLogging::get_LogFormat(eLogOutputFormat *pVal)
{

   *pVal = _IntLogFormat2ComLogFormat(m_pConfig->GetLogFormat());

   return S_OK;
}

STDMETHODIMP InterfaceLogging::put_LogFormat(eLogOutputFormat newVal)
{
   m_pConfig->SetLogFormat(_COMLogFormat2IntLogFormat(newVal));

   return S_OK;
}

int
InterfaceLogging::_COMLogFormat2IntLogFormat(eLogOutputFormat newVal)
{
   switch (newVal)
   {
   case hLogFormatDefault:
      return 0;
      break;
   case hLogFormatCSA:
      return 1;
      break;
   default:
      return 0;
      break;
   }
}

eLogOutputFormat
InterfaceLogging::_IntLogFormat2ComLogFormat(int RelayMode)
{
   switch (RelayMode)
   {
   case 0:
      return hLogFormatDefault;
      break;
   case 1:
      return hLogFormatCSA;
      break;

   default:
      return hLogFormatDefault;
      break;
   }
}

STDMETHODIMP InterfaceLogging::get_LogDebug(VARIANT_BOOL *pVal)
{
   if (m_pConfig->GetLogDebug() )
      *pVal = VARIANT_TRUE;
   else
      *pVal = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceLogging::put_LogDebug(VARIANT_BOOL newVal)
{
   m_pConfig->SetLogDebug(newVal == VARIANT_TRUE);

   return S_OK;
}


STDMETHODIMP InterfaceLogging::get_Directory(BSTR *pVal)
{
   *pVal = m_pIniFileSettings->GetLogDirectory().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceLogging::get_LiveLog(BSTR *pVal)
{
   *pVal = HM::Logger::Instance()->GetLiveLog().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceLogging::get_LiveLoggingEnabled(VARIANT_BOOL *pVal)
{
   *pVal = HM::Logger::Instance()->GetLiveLogEnabled();

   return S_OK;
}

STDMETHODIMP InterfaceLogging::get_MaskPasswordsInLog(VARIANT_BOOL *pVal)
{
   // OBSOLETE
   return S_OK;
}

STDMETHODIMP InterfaceLogging::put_MaskPasswordsInLog(VARIANT_BOOL newVal)
{
   // OBSOLETE
   return S_OK;
}

STDMETHODIMP InterfaceLogging::get_KeepFilesOpen(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetKeepFilesOpen() ? VARIANT_TRUE : VARIANT_FALSE;
   return S_OK;
}

STDMETHODIMP InterfaceLogging::put_KeepFilesOpen(VARIANT_BOOL newVal)
{
   m_pConfig->SetKeepFilesOpen(newVal == VARIANT_TRUE);
   return S_OK;
}



STDMETHODIMP InterfaceLogging::get_CurrentEventLog(BSTR *pVal)
{
   *pVal = HM::Logger::Instance()->GetCurrentLogFileName(HM::Logger::Events).AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceLogging::get_CurrentErrorLog(BSTR *pVal)
{
   *pVal = HM::Logger::Instance()->GetCurrentLogFileName(HM::Logger::Error).AllocSysString();
   return S_OK;
}


STDMETHODIMP InterfaceLogging::get_CurrentAwstatsLog(BSTR *pVal)
{
   *pVal = HM::Logger::Instance()->GetCurrentLogFileName(HM::Logger::AWStats).AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceLogging::get_CurrentDefaultLog(BSTR *pVal)
{
   *pVal = HM::Logger::Instance()->GetCurrentLogFileName(HM::Logger::Normal).AllocSysString();
   return S_OK;
}


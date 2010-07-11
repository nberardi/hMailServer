// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceStatus.h"

#include "../Common/Util/ServerStatus.h"

bool 
InterfaceStatus::LoadSettings()
{
   if (!GetIsServerAdmin())
      return false;

   m_pStatus = HM::ServerStatus::Instance();
   m_pApplication = HM::Application::Instance();

   return true;
}


STDMETHODIMP 
InterfaceStatus::get_UndeliveredMessages(BSTR *pVal)
{
   HM::String sRetVal = m_pStatus->GetUnsortedMessageStatus();
   *pVal = sRetVal.AllocSysString();

   return S_OK;
}

STDMETHODIMP 
InterfaceStatus::get_StartTime(BSTR *pVal)
{
   HM::String sRetVal = m_pApplication->GetStartTime();
   *pVal = sRetVal.AllocSysString();
   return S_OK;
}


STDMETHODIMP 
InterfaceStatus::get_ProcessedMessages(long *pVal)
{
   *pVal = m_pStatus->GetNumberOfProcessedMessages();
   return S_OK;
}


STDMETHODIMP 
InterfaceStatus::get_RemovedViruses(long *pVal)
{
   *pVal = m_pStatus->GetNumberOfRemovedViruses();
   return S_OK;
}



STDMETHODIMP 
InterfaceStatus::get_RemovedSpamMessages(long *pVal)
{
   *pVal = m_pStatus->GetNumberOfDetectedSpamMessages();
   return S_OK;
}

STDMETHODIMP 
InterfaceStatus::get_SessionCount(eSessionType iType, long *pVal)
{
   *pVal = m_pStatus->GetNumberOfSessions(iType);
   return S_OK;
}


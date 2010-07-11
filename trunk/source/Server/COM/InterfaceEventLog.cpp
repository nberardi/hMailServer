// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceEventLog.h"


STDMETHODIMP 
InterfaceEventLog::Write(BSTR sMessage)
{
   HM::Logger::Instance()->LogEvent(sMessage);

   return S_OK;
}
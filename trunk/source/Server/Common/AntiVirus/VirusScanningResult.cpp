// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "VirusScanningResult.h"

namespace HM
{
   

   VirusScanningResult::VirusScanningResult(ScanningResult result, const String &details) :
      m_scanningResult(result),
      m_details(details)
   {
      
   }

   VirusScanningResult::VirusScanningResult(const String &errorMessageSource, const String &errorMessage) :
      m_scanningResult(ErrorOccurred),
      m_details(errorMessage),
      m_errorMessageSource(errorMessageSource)
   {

   }
}

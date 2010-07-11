// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include "SpamTestResult.h"

namespace HM
{
   SpamTestResult::SpamTestResult(const String &testName, Result result, int iSpamScore, const String &sMessage) :
      m_iSpamScore(iSpamScore),
      m_sMessage(sMessage),
      _testName(testName),
      _result(result)
   {

   }

   SpamTestResult::~SpamTestResult(void)
   {

   }

}
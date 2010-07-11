// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "./RuleResult.h"

namespace HM
{ 
   RuleResult::RuleResult(void) :
      m_iSendUsingRoute(0),
      m_bDeleteEmail(false)
   {
   }

   RuleResult::~RuleResult(void)
   {
   }

}
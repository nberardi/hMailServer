// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "DiagnosticResult.h"

namespace HM
{
   DiagnosticResult::DiagnosticResult(String name, String description, bool success, String details) :
      _name(name), _description(description), _success(success), _details(details)
   {
      
   }

   DiagnosticResult::DiagnosticResult()
   {

   }
   
      
}

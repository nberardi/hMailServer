// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "DiagnosticResult.h"

namespace HM
{
   
   class Diagnostic
   {
   public:
	   Diagnostic();
	   virtual ~Diagnostic();
  
      void SetLocalDomain(String &sDomainName);
      String GetLocalDomain() const;

      vector<DiagnosticResult> PerformTests();

   private:

      String _localDomainName;
   };


}

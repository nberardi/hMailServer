// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "TestInformationGatherer.h"

namespace HM
{
   TestInformationGatherer::TestInformationGatherer()
   {

   }

   TestInformationGatherer::~TestInformationGatherer()
   {

   }

   DiagnosticResult
   TestInformationGatherer::PerformTest()
   {
      DiagnosticResult diagResult;
      diagResult.SetName("Collect server details");
      diagResult.SetDescription("Collects basic server details");

      String result;

      String formattedLine;
      formattedLine.Format(_T("hMailServer version: %s\r\n"), Application::Instance()->GetVersion());
      result.append(formattedLine);

      String databaseType = DatabaseSettings::GetDatabaseTypeName(IniFileSettings::Instance()->GetDatabaseType());
      formattedLine.Format(_T("Database type: %s\r\n"), databaseType);
      result.append(formattedLine);

      diagResult.SetSuccess(true);
      diagResult.SetDetails(result);

      return diagResult;
   }


   
      
}

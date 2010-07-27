// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "CustomVirusScanner.h"
#include "../../../SMTP/SMTPConfiguration.h"
#include "../ProcessLauncher.h"

namespace HM
{
   CustomVirusScanner::CustomVirusScanner(void)
   {
   }

   CustomVirusScanner::~CustomVirusScanner(void)
   {

   }

   bool 
   CustomVirusScanner::Scan(const String &sFilename)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:

   //---------------------------------------------------------------------------()
   {
      LOG_DEBUG("Running custom virus scanner...");

      AntiVirusConfiguration &pConfig = Configuration::Instance()->GetAntiVirusConfiguration();
      String sExecutable = pConfig.GetCustomScannerExecutable();

      String sPath = FileUtilities::GetFilePath(sFilename);

      String sCommandLine;

      if (sExecutable.Find(_T("%FILE%")) >= 0)
      {
         sCommandLine = sExecutable;
         sCommandLine.Replace(_T("%FILE%"), sFilename);
      }
      else
         sCommandLine.Format(_T("%s %s"), sExecutable, sFilename);

      unsigned int exitCode = 0;
      ProcessLauncher launcher(sCommandLine, sPath);
      launcher.SetErrorLogTimeout(20000);
      if (!launcher.Launch(exitCode))
      {
         return false;
      }

      String sDebugMessage = Formatter::Format("Scanner: {0}. Return code: {1}", sCommandLine, exitCode);
      LOG_DEBUG(sDebugMessage);

      if (exitCode == pConfig.GetCustomScannerReturnValue())
         return true;
      else
         return false;

   }
}
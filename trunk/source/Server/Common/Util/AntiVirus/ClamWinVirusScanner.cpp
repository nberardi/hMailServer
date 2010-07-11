// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "ClamWinVirusScanner.h"

#include "../../../SMTP/SMTPConfiguration.h"
#include "../Utilities.h"
#include "../ProcessLauncher.h"

namespace HM
{
   ClamWinVirusScanner::ClamWinVirusScanner()
   {

   }

   ClamWinVirusScanner::~ClamWinVirusScanner()
   {

   }

   bool 
   ClamWinVirusScanner::Scan(const String &sFilename)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   
   //---------------------------------------------------------------------------()
   {
      LOG_DEBUG("Running ClamWin");

      String sExecutable = Configuration::Instance()->GetSMTPConfiguration()->ClamWinExecutable();
      String sDatabase = Configuration::Instance()->GetSMTPConfiguration()->ClamWinDatabase();

      String sPath = FileUtilities::GetFilePath(sFilename);
      String sFileToScan = FileUtilities::GetFileNameFromFullPath(sFilename);
      String sTempDir = Utilities::GetWin32TempDirectory();

      String sCommandLine;
      sCommandLine.Format(_T("%s --database=\"%s\" \"%s\" --tempdir=\"%s\""), sExecutable, sDatabase, sFileToScan, sTempDir);


      unsigned int exitCode = 0;
      ProcessLauncher launcher(sCommandLine, sPath);
      launcher.SetErrorLogTimeout(20000);
      if (!launcher.Launch(exitCode))
      {
         return false;
      }

      String sDebugMessage = Formatter::Format("ClamWin: {0}. Return code: {1}", sCommandLine, exitCode);
      LOG_DEBUG(sDebugMessage);

      if (exitCode == 1)
         return true;
      else
         return false;

   }
}
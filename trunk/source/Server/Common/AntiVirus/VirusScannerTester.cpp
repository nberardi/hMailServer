// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "VirusScannerTester.h"
#include "../Util/AntiVirus/CustomVirusScanner.h"
#include "../Util/AntiVirus/ClamWinVirusScanner.h"
#include "ClamAVVirusScanner.h"
#include "../Util/GUIDCreator.h"
#include "VirusScanningResult.h"

namespace HM
{
   bool 
   VirusScannerTester::TestClamAVConnect(const String &hostName, int port, String &message)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   //---------------------------------------------------------------------------()
   {
      String testFile = _GenerateTestFile();

      ClamAVVirusScanner scanner;
      VirusScanningResult result = scanner.Scan(hostName, port, testFile);

      FileUtilities::DeleteFile(testFile);

      message = result.GetDetails();

      return result.GetVirusFound();
   }

   bool 
   VirusScannerTester::TestCustomVirusScanner(const String &executable, int returnValue, String &message)
   {
      String testFile = _GenerateTestFile();

      CustomVirusScanner scanner;
      VirusScanningResult result = scanner.Scan(executable, returnValue, testFile);

      FileUtilities::DeleteFile(testFile);

      message = result.GetDetails();

      return result.GetVirusFound();
   }

   bool 
   VirusScannerTester::TestClamWinVirusScanner(const String &executable, const String &databasePath, String &message)
   {
      String testFile = _GenerateTestFile();

      ClamWinVirusScanner scanner;
      VirusScanningResult result = scanner.Scan(executable, databasePath, testFile);

      FileUtilities::DeleteFile(testFile);

      message = result.GetDetails();

      return result.GetVirusFound();
   }

   String
   VirusScannerTester::_GenerateTestFile()
   {
      // Store the test virus in reversed form so we don't trigger any virus scanner...
      String eicarTestString = " *H+H$!ELIF-TSET-SURIVITNA-DRADNATS-RACIE$}7)CC7)^P(45XZP\\4[PA@%P!O5X";      

      // Write the test virus to the data directory to simulate email.
      String dataDir = IniFileSettings::Instance()->GetDataDirectory();

      String messageFileName = GUIDCreator::GetGUID() + ".eml";
      String fullPathToMessage = FileUtilities::Combine(dataDir, messageFileName);

      eicarTestString.MakeReverse();
      FileUtilities::WriteToFile(fullPathToMessage, eicarTestString, false);

      return fullPathToMessage;
   }
}

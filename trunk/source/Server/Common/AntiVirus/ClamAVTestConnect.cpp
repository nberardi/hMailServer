// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "ClamAVTestConnect.h"
#include "ClamAVVirusScanner.h"
#include "../Util/GUIDCreator.h"


namespace HM
{
   bool 
   ClamAVTestConnect::TestConnect(const String &hostName, int port, String &message)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   //---------------------------------------------------------------------------()
   {
      // Store the test virus in reversed form so we don't trigger any virus scanner...
      String eicarTestString = " *H+H$!ELIF-TSET-SURIVITNA-DRADNATS-RACIE$}7)CC7)^P(45XZP\\4[PA@%P!O5X";      

      // Write the test virus to the data directory to simulate email.
      String dataDir = IniFileSettings::Instance()->GetDataDirectory();

      String messageFileName = GUIDCreator::GetGUID() + ".eml";
      String fullPathToMessage = FileUtilities::Combine(dataDir, messageFileName);
      
      eicarTestString.MakeReverse();
      FileUtilities::WriteToFile(fullPathToMessage, eicarTestString, false);

      ClamAVVirusScanner scanner;
      bool result = scanner.Scan(fullPathToMessage, message);

      if (!result)
      {
         message = "Unable to scan message file. Please review the hMailServer logs.";
      }

      return result;
   }
}

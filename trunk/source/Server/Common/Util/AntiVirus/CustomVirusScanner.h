// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class CustomVirusScanner
   {
   public:
      CustomVirusScanner(void);
      ~CustomVirusScanner(void);

      static bool Scan(const String &sFilename);
   };

}
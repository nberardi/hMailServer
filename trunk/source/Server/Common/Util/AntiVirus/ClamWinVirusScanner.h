// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class ClamWinVirusScanner  
   {
   public:
	   ClamWinVirusScanner();
	   virtual ~ClamWinVirusScanner();

      static bool Scan(const String &sFilename);

   protected:
      
   private:


   };
}

// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include ".\systeminformation.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{

   //---------------------------------------------------------------------------//
   // SystemInformation
   // This class contains static functions that can be used
   // to detect operating system, memory usage, hard disks etc.
   //---------------------------------------------------------------------------//

   SystemInformation::SystemInformation(void)
   {
   }

   SystemInformation::~SystemInformation(void)
   {
   }

   SystemInformation::OperatingSystem 
   SystemInformation::GetOperatingSystem()
   {
      OSVERSIONINFO OSversion;

      OSversion.dwOSVersionInfoSize=sizeof(OSVERSIONINFO);
      ::GetVersionEx(&OSversion);

      switch(OSversion.dwPlatformId)
      {
      case VER_PLATFORM_WIN32s: 
         return Windows3;
      case VER_PLATFORM_WIN32_WINDOWS:
         if(OSversion.dwMinorVersion==0)
            return Windows95;
         else if(OSversion.dwMinorVersion==10)  
            return Windows98;
         else if(OSversion.dwMinorVersion==90)  
            return Windows98;
         break;
      case VER_PLATFORM_WIN32_NT:
         if(OSversion.dwMajorVersion==5 && OSversion.dwMinorVersion==0)
            return Windows2000;
         else if(OSversion.dwMajorVersion==5 &&   OSversion.dwMinorVersion==1)
            return WindowsXP;
         else if(OSversion.dwMajorVersion<=4)
            return WindowsNT;
         else	
            //for unknown windows/newest windows version
            return Windows2003;
      }      

      return Unknown;
   }
}
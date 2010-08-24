#include "StdAfx.h"

#include "SSPIValidation.h"

namespace HM
{
   bool 
   SSPIValidation::ValidateUser(const String &sDomain, const String &sUsername, const String &sPassword)
   {
	  HANDLE token;
      BOOL result = LogonUser(sUsername, sDomain, sPassword, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &token);
	  CloseHandle(token);

	  return result != 0;
   }
}
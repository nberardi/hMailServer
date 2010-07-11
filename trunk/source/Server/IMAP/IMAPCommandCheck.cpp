// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "IMAPCommandCheck.h"

#include "IMAPConnection.h"

namespace HM
{
   IMAPResult
   IMAPCommandCHECK::ExecuteCommand(shared_ptr<IMAPConnection> pConnection, shared_ptr<IMAPCommandArgument> pArgument)
   {
      if (!pConnection->IsAuthenticated())
         return IMAPResult(IMAPResult::ResultNo, "Authenticate first");

      String sResponse; 
      sResponse += pArgument->Tag() + " OK CHECK completed\r\n";
      pConnection->SendAsciiData(sResponse);   

      return IMAPResult();
   }
}
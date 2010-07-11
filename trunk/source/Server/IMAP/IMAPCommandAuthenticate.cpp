// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "IMAPCommandAuthenticate.h"
#include "IMAPConnection.h"

namespace HM
{
   IMAPResult
   IMAPCommandAUTHENTICATE::ExecuteCommand(shared_ptr<IMAPConnection> pConnection, shared_ptr<IMAPCommandArgument> pArgument)
   {
      return IMAPResult(IMAPResult::ResultNo, "Unsupported authentication mechanism.");
   }
}
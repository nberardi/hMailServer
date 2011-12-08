// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommand.h"

namespace HM
{
   
   class IMAPCommandLIST  : public IMAPCommand
   {
   public:
	   IMAPCommandLIST();
	   virtual ~IMAPCommandLIST();

      virtual IMAPResult ExecuteCommand(boost::shared_ptr<HM::IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument);
   };

}

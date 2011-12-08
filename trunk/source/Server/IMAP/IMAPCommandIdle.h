// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommand.h"

namespace HM
{
   class IMAPCommandIdle : public IMAPCommand
   {
   public:
	   IMAPCommandIdle(boost::shared_ptr<IMAPConnection> pConnection);
	   virtual ~IMAPCommandIdle();

      IMAPResult ExecuteCommand(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument);
      void Finish(bool sendNotificationToClient);

   private:

      String m_sTag;

      boost::weak_ptr<IMAPConnection> _connection;
   };

}

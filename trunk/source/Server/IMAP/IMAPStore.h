// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommandRangeAction.h"

namespace HM
{

   class IMAPStore : public IMAPCommandRangeAction
   {
   public:
	   IMAPStore();
	   virtual ~IMAPStore();

      IMAPResult DoAction(boost::shared_ptr<IMAPConnection> pConnection, int messageIndex, boost::shared_ptr<Message> pMessage, const boost::shared_ptr<IMAPCommandArgument> pArgument);
      static String GetMessageFlags(boost::shared_ptr<Message> pMessage, int messageIndex);
   };

}

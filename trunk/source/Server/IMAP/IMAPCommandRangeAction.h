// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommand.h"

namespace HM
{
   class IMAPCommandRangeAction : public IMAPCommand  
   {
   public:
	   IMAPCommandRangeAction();
	   virtual ~IMAPCommandRangeAction();

      void SetIsUID(bool bIsUID);
      
      IMAPResult ExecuteCommand(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument) {return IMAPResult();}
      IMAPResult DoForMails(boost::shared_ptr<IMAPConnection> pConnection, const String &sMailNos, const boost::shared_ptr<IMAPCommandArgument> pArgument);

   protected:

      bool GetIsUID();
      virtual IMAPResult DoAction(boost::shared_ptr<IMAPConnection> pConnection, int messageIndex, boost::shared_ptr<Message> pMessage, const boost::shared_ptr<IMAPCommandArgument> pArgument) = 0;

   private:

      bool _isUID;
     
   };

}

// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommandRangeAction.h"

namespace HM
{
   class IMAPConnection;

   class IMAPCommandUID : public HM::IMAPCommandRangeAction
   {
   public:
	   IMAPCommandUID();
	   virtual ~IMAPCommandUID();

      virtual IMAPResult ExecuteCommand(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument);
      virtual IMAPResult DoAction(boost::shared_ptr<IMAPConnection> pConnection, int messageIndex, boost::shared_ptr<Message> pMessage, const boost::shared_ptr<IMAPCommandArgument> pArgument) {assert(0); return IMAPResult(IMAPResult::ResultBad, "Internal parsing error.");}

   private:
      
      void _ShowForMails(const String &sMailNo, const String &sShowPart);
      
      boost::shared_ptr<HM::IMAPCommandRangeAction> m_pCommand;
   };

}
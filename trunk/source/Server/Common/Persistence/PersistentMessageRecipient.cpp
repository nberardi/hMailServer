// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "PersistentMessageRecipient.h"


#include "../BO/MessageRecipient.h"


namespace HM
{
   PersistentMessageRecipient::PersistentMessageRecipient(void)
   {
   }

   PersistentMessageRecipient::~PersistentMessageRecipient(void)
   {
   }


   bool 
   PersistentMessageRecipient::DeleteObject(shared_ptr<MessageRecipient> pRecipient)
   {
      SQLCommand command("delete from hm_messagerecipients where recipientaddress = @ADDRESS AND recipientmessageid = @MESSAGEID");
      command.AddParameter("@ADDRESS", pRecipient->GetAddress());
      command.AddParameter("@MESSAGEID", pRecipient->GetMessageID());

      return Application::Instance()->GetDBManager()->Execute(command);

   }
}
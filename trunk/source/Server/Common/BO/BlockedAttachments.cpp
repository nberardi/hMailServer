// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "BlockedAttachments.h"

#include "../Persistence/PersistentBlockedAttachment.h"

namespace HM
{
   BlockedAttachments::BlockedAttachments()
   {
   }

   BlockedAttachments::~BlockedAttachments(void)
   {
   }


   void 
   BlockedAttachments::Refresh()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads all SURBL servers from the database.
   //---------------------------------------------------------------------------()
   {
      String sSQL = _T("select * from hm_blocked_attachments order by bawildcard asc");
      _DBLoad(sSQL);
   }

}
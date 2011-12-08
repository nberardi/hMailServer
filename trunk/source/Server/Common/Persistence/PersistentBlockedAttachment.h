// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class BlockedAttachment;

   class PersistentBlockedAttachment
   {
   public:
      PersistentBlockedAttachment(void);
      ~PersistentBlockedAttachment(void);
      
      static bool DeleteObject(boost::shared_ptr<BlockedAttachment> pObject);
      static bool SaveObject(boost::shared_ptr<BlockedAttachment> pObject);
      static bool SaveObject(boost::shared_ptr<BlockedAttachment> pObject, String &errorMessage);
      static bool ReadObject(boost::shared_ptr<BlockedAttachment> pObject, boost::shared_ptr<DALRecordset> pRS);

   };
}
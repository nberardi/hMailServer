// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class ServerMessage;

   class PersistentServerMessage
   {
   public:
      PersistentServerMessage(void);
      ~PersistentServerMessage(void);
      
      static bool DeleteObject(boost::shared_ptr<ServerMessage> pObject);
      static bool SaveObject(boost::shared_ptr<ServerMessage> pObject);
      static bool ReadObject(boost::shared_ptr<ServerMessage> pObject, boost::shared_ptr<DALRecordset> pRS);

   };
}
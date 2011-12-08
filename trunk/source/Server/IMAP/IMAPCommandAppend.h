// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommand.h"
#include "../Common/Util/ByteBuffer.h"

namespace HM
{
   class ByteBuffer;
   class IMAPFolder;
   class Domain;

   class IMAPCommandAppend : public IMAPCommand  
   {
   public:
	   IMAPCommandAppend();
	   virtual ~IMAPCommandAppend();

      virtual IMAPResult ExecuteCommand(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument);
      void ParseBinary(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<ByteBuffer> pBuf);
      

   private:

      void _Finish(boost::shared_ptr<IMAPConnection> pConnection);
      bool _TruncateBuffer(const boost::shared_ptr<IMAPConnection> pConnection );
      bool _WriteData(const boost::shared_ptr<IMAPConnection> pConnection, const BYTE *pBuf, int WriteLen);
      void _KillCurrentMessage();
      
      int _GetMaxMessageSize(boost::shared_ptr<const Domain> pDomain);

      String m_sCurrentTag;
      String m_sFlagsToSet;
      String m_sCreateTimeToSet;
      long m_lBytesLeftToReceive;

      String m_sMessageFileName;

      ByteBuffer _appendBuffer;
      boost::shared_ptr<IMAPFolder> m_pDestinationFolder;
      boost::shared_ptr<Message> m_pCurrentMessage;

      
   };

}

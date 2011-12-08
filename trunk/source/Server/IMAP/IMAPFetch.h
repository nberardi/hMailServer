// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommandRangeAction.h"
#include "../Common/MIME/Mime.h"
#include "IMAPFetchParser.h"

namespace HM
{

   class IMAPConnection;
   class Message;
   class ByteBuffer; 
   class IMAPFetchParser;
   

   class IMAPFetch : public IMAPCommandRangeAction
   {
   public:
	   IMAPFetch();
	   virtual ~IMAPFetch();

      virtual IMAPResult DoAction(boost::shared_ptr<IMAPConnection> pConnection, int messageIndex, boost::shared_ptr<Message> pMessage, const boost::shared_ptr<IMAPCommandArgument> pArgument);

      
   private:
      
      String _CreateEnvelopeStructure(MimeHeader& oHeader);
      String _GetPartStructure(boost::shared_ptr<MimeBody> oPart, bool bExtensible, int iRecursion);
      String _IteratePartRecursive(boost::shared_ptr<MimeBody> oPart, bool bExtensible, int iRecursion);
      String _CreateEmailStructure(const String &sField);
      boost::shared_ptr<MimeBody>_GetMessagePartByPartNo(boost::shared_ptr<MimeBody>pBody, long iPartNo);

      boost::shared_ptr<ByteBuffer> _GetByteBufferByBodyPart(const String &messageFileName, boost::shared_ptr<MimeBody> pBodyPart, IMAPFetchParser::BodyPart &oPart);
      boost::shared_ptr<MimeBody> _GetBodyPartByRecursiveIdentifier(boost::shared_ptr<MimeBody> pBody, const String &sName);


      void _GetBytesToSend(int iBufferSize, IMAPFetchParser::BodyPart &oPart, int &iOutStart, int &iOutCount);

      void _ReportCriticalError(const String &messageFileName, const String &sMessage);

      void _AppendOutput(String &sOutput, const String &sAppend);
      void _SendAndReset(boost::shared_ptr<IMAPConnection> pConnection, String &sOutput);

      boost::shared_ptr<MimeBody> _LoadMimeBody(boost::shared_ptr<IMAPFetchParser> pParser, const String &fileName);
      bool _GetMessageBodyNeeded(boost::shared_ptr<IMAPFetchParser> pParser);

      bool m_bAppendSpace;

      boost::shared_ptr<IMAPFetchParser> m_pParser;

   };

}

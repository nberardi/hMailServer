// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include ".\SpamAssassinClient.h"

#include "../../Util/ByteBuffer.h"
#include "../../Util/File.h"
#include "../../TCPIP/TCPConnection.h"

namespace HM
{
   SpamAssassinClient::SpamAssassinClient(const String &sFile) 
   {
      SetTimeout(30); 
      
      m_sMessageFile = sFile;
   }


   SpamAssassinClient::~SpamAssassinClient(void)
   {

   }

   void
   SpamAssassinClient::OnConnected()
   {
      // We'll handle all incoming data as binary.
      SetReceiveBinary(true);

      SendData("PROCESS SPAMC/1.0\r\n");

      _SendFileContents(m_sMessageFile);
   }

   AnsiString 
   SpamAssassinClient::GetCommandSeparator() const
   {
      return "\r\n";
   }

   void 
   SpamAssassinClient::OnCouldNotConnect(const AnsiString &sErrorDescription)
   {
      String logMessage;
      logMessage.Format(_T("Failed to connect to SpamAssassin. Session %d"), GetSessionID());
      LOG_DEBUG(logMessage);
   }

   bool
   SpamAssassinClient::_SendFileContents(const String &sFilename)
   {
      String logMessage;
      logMessage.Format(_T("Sending message to SpamAssassin. Session %d, File: %s"), GetSessionID(), sFilename);
      LOG_DEBUG(logMessage);

      File oFile;
      if (!oFile.Open(sFilename, File::OTReadOnly))
      {
         String sErrorMsg;
         sErrorMsg.Format(_T("Could not send file %s via socket since it does not exist."), sFilename);

         ErrorManager::Instance()->ReportError(ErrorManager::High, 5019, "SMTPClientConnection::_SendFileContents", sErrorMsg);

         return false;
      }

      const int maxIterations = 100000;
      for (int i = 0; i < maxIterations; i++)
      {
         shared_ptr<ByteBuffer> pBuf = oFile.ReadChunk(20000);

         if (!pBuf)
            break;

         BYTE *pSendBuffer = (BYTE*) pBuf->GetBuffer();
         int iSendBufferSize = pBuf->GetSize();

         SendData(pBuf);
      }

      PostShutdown(TCPConnection::ShutdownSend);

      // Request the response...
      PostBufferReceive();
      
      return true;
   }

   void
   SpamAssassinClient::OnConnectionTimeout()
   {
      // do nothing
   }

   void
   SpamAssassinClient::OnExcessiveDataReceived()
   {
      // do nothing
   }

   void
   SpamAssassinClient::ParseData(const AnsiString &sData)
   {
      
   }

   void
   SpamAssassinClient::ParseData(shared_ptr<ByteBuffer> pBuf)
   {
      if (!m_pResult)
      {
         String logMessage;
         logMessage.Format(_T("Parsing response from SpamAssassin. Session %d"), GetSessionID());
         LOG_DEBUG(logMessage);

         m_pResult = shared_ptr<File>(new File);
         m_pResult->Open(FileUtilities::GetTempFileName(), File::OTAppend);

         _ParseFirstBuffer(pBuf);
      }

      // Append output to the file
      DWORD dwWritten = 0;
      m_pResult->Write(pBuf, dwWritten);

      PostReceive();
   }

   bool
   SpamAssassinClient::FinishTesting()
   {
      if (!m_pResult)
         return false;

      m_pResult->Close();

      // Copy message if test has been run
      bool bTestsRun = true;

      String sTempFile = m_pResult->GetName();
      if (bTestsRun && FileUtilities::FileSize(sTempFile) > 0)
      {
         // Copy temp file to message file
         FileUtilities::Copy(sTempFile, m_sMessageFile, false);
      }

      FileUtilities::DeleteFile(sTempFile);
      return true;
   }

   void
   SpamAssassinClient::_ParseFirstBuffer(shared_ptr<ByteBuffer> pBuffer) const
   {
      // Don't send first line, since it's the Result header.
      char *pFoundPos = StringParser::Search(pBuffer->GetCharBuffer(), pBuffer->GetSize(), "\r\n");
      if (!pFoundPos)
      {
         // We should never get here, since we should always have
         // a header in the result
         assert(0);
         return;
      }

      // Extract the first line from the first buffer. This buffer
      // contains the result of the operation (success / failure).
      int iFirstLineLength = pFoundPos - pBuffer->GetCharBuffer() + 2;
      AnsiString sFirstLine(pBuffer->GetCharBuffer(), iFirstLineLength);

      // Trim away the first line from the result.
      int iEndingBytesSize = pBuffer->GetSize() - iFirstLineLength;
      pBuffer->Empty(iEndingBytesSize);

      if (sFirstLine.Compare("SPAMD/1.0 0 EX_OK\r\n") != 0)
	  {
         // We should never get here, since we should always have
         // a header in the result
         assert(0);
	  }
   }

   /*
      Handles the situation where SpamAssasin does not send the entire
      response to hMailServer. In this case, an error will be logged and
      SA won't have any effect.

   */
   void 
   SpamAssassinClient::OnReadError(int errorCode)
   {
      String errorMessage;
      errorMessage.Format(_T("There was a communication error with SpamAssassin. ")
                          _T("hMailServer tried to retrieve data from SpamAssassin but the connection ")
                          _T("to SpamAssassin was lost. The WinSock error code is %d. Enable debug ")
                          _T("logging to retrieve more information regarding this problem. ")
                          _T("The problem could be that SpamAssassin is malfunctioning."), errorCode);

      ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5157, "SpamAssassinClient::OnReadError", errorMessage);

      if (m_pResult)
      {
         m_pResult->Close();
         FileUtilities::DeleteFile(m_pResult->GetName());
         m_pResult.reset();
      }
   }
}

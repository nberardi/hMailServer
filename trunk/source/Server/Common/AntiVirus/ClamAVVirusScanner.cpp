// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "ClamAVVirusScanner.h"
#include "AntiVirusConfiguration.h"

#include "../TCPIP/SynchronousConnection.h"
#include "../Util/ByteBuffer.h"
#include "../Util/RegularExpression.h"


namespace HM
{
   ClamAVVirusScanner::ClamAVVirusScanner(void)
   {
   }

   ClamAVVirusScanner::~ClamAVVirusScanner(void)
   {

   }

   bool 
   ClamAVVirusScanner::Scan(const String &sFilename, String &virusName)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   //---------------------------------------------------------------------------()
   {
      LOG_DEBUG("Connecting to ClamAV virus scanner...");

      AntiVirusConfiguration& config = Configuration::Instance()->GetAntiVirusConfiguration();

      String hostName = config.GetClamAVHost();
      int primaryPort = config.GetClamAVPort();
      int streamPort = 0;

      SynchronousConnection commandConnection(15);
      if (!commandConnection.Connect(hostName, primaryPort))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5406, "ClamAVVirusScanner::Scan", 
            Formatter::Format("Unable to connect to ClamAV server at {0}:{1}.", hostName, primaryPort));  
         
         return false;
      }

      if (!commandConnection.Write("STREAM\r\n"))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5407, "ClamAVVirusScanner::Scan", 
            "Unable to write command.");

         return false;
      }

      AnsiString readData;
      if (!commandConnection.ReadUntil("\n", readData))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5408, "ClamAVVirusScanner::Scan", 
            "Unable to read response.");

         return false;
      }

      if (!readData.StartsWith("PORT"))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5409, "ClamAVVirusScanner::Scan", 
            Formatter::Format("Protocol error. Unexpected response: {0}.", readData));

         return false;
      }
      
      readData.TrimRight("\n");

      // Determine port.
      string portString = readData.Mid(5);
      
      if (!StringParser::TryParseInt(portString, streamPort))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5409, "ClamAVVirusScanner::Scan", 
            Formatter::Format("Protocol error. Unexpected response: {0} (Unable to parse port).", readData));

         return false;
      }

      LOG_DEBUG("Connecting to ClamAV stream port...");
      SynchronousConnection streamConnection(15);
      if (!streamConnection.Connect(hostName, streamPort))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5410, "ClamAVVirusScanner::Scan", 
            Formatter::Format("Unable to connect to ClamAV stream port at {0}:{1}.", hostName, streamPort)); 

         return false;
      }

      // Send the file on the stream socket.
      File oFile;
      if (!oFile.Open(sFilename, File::OTReadOnly))
      {
         String sErrorMsg = Formatter::Format("Could not send file {0} via socket since it does not exist.", sFilename);
         ErrorManager::Instance()->ReportError(ErrorManager::High, 5411, "ClamAVVirusScanner::Scan", sErrorMsg);
         return false;
      }

      const int STREAM_BLOCK_SIZE = 4096;
      const int maxIterations = 100000;
      for (int i = 0; i < maxIterations; i++)
      {
         shared_ptr<ByteBuffer> pBuf = oFile.ReadChunk(STREAM_BLOCK_SIZE);

         if (!pBuf)
            break;

         // Send the request.
         if (!streamConnection.Write(*pBuf))
         {
            ErrorManager::Instance()->ReportError(ErrorManager::High, 5411, "ClamAVVirusScanner::Scan", "Unable to write data to stream port.");
            return false;
         }
      }

      streamConnection.Close();

      if (!commandConnection.ReadUntil("\n", readData))
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5408, "ClamAVVirusScanner::Scan", 
            "Unable to read response (after streaming).");

         return false;
      }

      readData.TrimRight("\n");

      // Parse the response and see if a virus was reported.
      try
      {
         const regex expression("^stream.*: (.*) FOUND$"); 
         cmatch what; 
         if(regex_match(readData.c_str(), what, expression)) 
         {
            virusName = what[1];
            LOG_DEBUG("Virus detected: " + what[1]);
            return true;
         }
         else
         {
            LOG_DEBUG("No virus detected: " + readData);
            return false;
         }
      }
      catch (std::runtime_error &) // regex_match will throw runtime_error if regexp is too complex.
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5413, "ClamAVVirusScanner::Scan", 
            "Unable to parse regular expression.");

         return false;
      }

      
   }
}

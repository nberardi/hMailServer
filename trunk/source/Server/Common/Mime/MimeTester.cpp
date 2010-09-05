// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include "MimeTester.h"
#include "Mime.h"
#include "MimeCode.h"
#include "../BO/Message.h"
#include "../BO/MessageData.h"
#include "../Persistence/PersistentMessage.h"

namespace HM
{
   MimeTester::MimeTester(void)
   {
   }

   MimeTester::~MimeTester(void)
   {
   }
   
   bool 
   MimeTester::TestFolder(const String &sFolderName)
   {
      MimeParameterRFC2184Decoder rfc2184tester;
      AnsiString result = rfc2184tester.Decode("us-ascii'en'This%20is%20even%20more%20%2A%2A%2Afun%2A%2A%2A%20isn't it!");

      return true;

      String sCleanFolder = sFolderName;
      if (sCleanFolder.Right(1) == _T("\\"))
         sCleanFolder = sCleanFolder.Left(sCleanFolder.GetLength() - 1);

      if (sCleanFolder.Right(1) != _T("\\"))
         sCleanFolder += "\\";

      String sWildCard = sCleanFolder + "*.*";

      // Locate first match
      WIN32_FIND_DATA ffData;
      HANDLE hFileFound = FindFirstFile(sWildCard, &ffData);

      if (hFileFound == INVALID_HANDLE_VALUE)
         return FALSE;

      while (hFileFound && FindNextFile(hFileFound, &ffData))
      {
         String sFullPath = sCleanFolder + ffData.cFileName;

         if (ffData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) 
         {
            if( (_tcscmp(ffData.cFileName, _T(".")) != 0) &&
               (_tcscmp(ffData.cFileName, _T("..")) != 0) ) 
            {
               if( !TestFolder(sFullPath) )
                  return false;
            }

         }
         else
         { 
            TestLoadFile(sFullPath);
         }
      }

      FindClose(hFileFound);

      return true;
   
   }

   void 
   MimeTester::TestLoadFile(const String &sFilename)
   {
	   try
	   {
		   shared_ptr<Message> pMessage = shared_ptr<Message>(new Message(false));

		   shared_ptr<MessageData> pMsgData = shared_ptr<MessageData>(new MessageData());
		   pMsgData->LoadFromMessage(sFilename, pMessage);
	   }
	   catch (...)
	   {
		   assert(0);
		   MessageBox(0,_T("ERROR"), _T("ERROR"), 0);
		   throw;
	   }
   }

   void 
   MimeTester::TestFile(const String &sFilename)
   {
      try
      {
         shared_ptr<Message> pMessage = shared_ptr<Message>(new Message(false));
         // pMessage->SetFileName(sFilename);

         shared_ptr<MessageData> pMsgData = shared_ptr<MessageData>(new MessageData());
         pMsgData->LoadFromMessage(sFilename, pMessage);

         String sOutput = "hMailServer: [MimeTester] --> "; 
         sOutput += sFilename + " --> "; 
         sOutput += pMsgData->GetSubject();
         sOutput += "\n";
         OutputDebugString(sOutput);

         // Add a message header
         pMsgData->SetFieldValue("X-MyHeader", "ValueOfMyHeader");

         // New message
         shared_ptr<Message> pNewMessage = shared_ptr<Message>(new Message());
         shared_ptr<Account> account;
         String newFileName = PersistentMessage::GetFileName(account, pNewMessage);

         pMsgData->Write(newFileName);

         // Delete the new message.
         FileUtilities::DeleteFile(newFileName);

      }
      catch (...)
      {
         assert(0);
         MessageBox(0,_T("ERROR"), _T("ERROR"), 0);
         throw;
      }
   }

}
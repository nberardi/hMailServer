// Copyright (c) 2005 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "PersistentMessage.h"
#include "PersistentDomain.h"
#include "PersistentAccount.h"
#include "PersistentIMAPFolder.h"
#include "PersistentAlias.h"
#include "PersistentDistributionList.h"
#include "PersistentServerMessage.h"
#include "PersistentMessageMetaData.h"
#include "../Util/MailerDaemonAddressDeterminer.h"
#include "../../SMTP/SMTPConfiguration.h"
#include "../../IMAP/IMAPConfiguration.h"
#include "../../SMTP/RecipientParser.h"
#include "../BO/Account.h"
#include "../BO/Message.h"
#include "../BO/MessageRecipient.h"
#include "../BO/MessageRecipients.h"
#include "../BO/MessageData.h"
#include "../BO/ServerMessages.h"
#include "../BO/IMAPFolder.h"
#include "../Util/File.h"
#include "../Util/Time.h"
#include "../Cache/CacheContainer.h"
#include "../Cache/AccountSizeCache.h"
#include "..\Util\FolderManipulationLock.h"

namespace HM
{
   PersistentMessage::PersistentMessage()
   {
      
   }

   PersistentMessage::~PersistentMessage()
   {

   }

   bool
   PersistentMessage::DeleteObject(shared_ptr<Message> pMessage)
   {
      LOG_DEBUG("Deleting message");
      __int64 iMessageID = pMessage->GetID();

      if (iMessageID > 0)
      {
         SQLCommand command(_T("delete from hm_messages where messageid = @MESSAGEID"));
         command.AddParameter("@MESSAGEID", iMessageID);
         
         if (!Application::Instance()->GetDBManager()->Execute(command))
            return false;

         // If the message is placed into an account, there won't be any recipients
         // connected to it. If the message is still in the queue, we must delete the
         // recipients as well.
         if (pMessage->GetState() != Message::Delivered)
         {
            // Delete recipients.
            SQLCommand deleteCommand("delete from hm_messagerecipients where recipientmessageid = @MESSAGEID");
            deleteCommand.AddParameter("@MESSAGEID", iMessageID);
            
            if (!Application::Instance()->GetDBManager()->Execute(deleteCommand))
            {
               return false;
            }
         }


         // Update the account size cache.
         if (pMessage->GetAccountID() > 0)
         {
            AccountSizeCache::Instance()->ModifySize(pMessage->GetAccountID(), pMessage->GetSize(), false);
         }

         // Delete meta-data connected to this message.
         if (Configuration::Instance()->GetMessageIndexing())
         {
            PersistentMessageMetaData md;
            md.DeleteForMessage(pMessage);
         }

         // Reset the message ID.
         pMessage->SetID(0);

         shared_ptr<const Account> account;
         
         if (pMessage->GetAccountID() > 0)
         {
            account = CacheContainer::Instance()->GetAccount(pMessage->GetAccountID());
         }

         if (!DeleteFile(account, pMessage))
         {
            return false;
         }
      }

      return true;
   }

   bool
   PersistentMessage::FileExistsAsMessage(const String &sFilename, bool &isPartialFilename)
   {
      __int64 messageID = 0;
      if (GetMessageID(sFilename, messageID, isPartialFilename))
      {
         if (messageID > 0)
            return true;
      }

      return false;
   }

   bool
   PersistentMessage::GetMessageID(const String &fileName, __int64 &messageID, bool &isPartialFilename)
   {
      messageID = 0;
      isPartialFilename = false;

      // Create a partial file name from the full path.
      String partialFileName;
      if (GetPartialFilename(fileName, partialFileName))
      {
         // Check if the partial file name exists.
         SQLCommand command("select messageid from hm_messages where messagefilename = @FILENAME");
         command.AddParameter("@FILENAME", partialFileName);

         shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
         if (!pRS)
            return false;

         if (!pRS->IsEOF())
         {
            messageID = pRS->GetInt64Value("messageid");
            isPartialFilename = true;
            return true;
         }
      }

      // Check if the full path exists.
      SQLCommand command("select messageid from hm_messages where messagefilename = @FILENAME");
      command.AddParameter("@FILENAME", fileName);

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      if (!pRS->IsEOF())
      {
         messageID = pRS->GetInt64Value("messageid");
         return true;
      }

      return true;
      
   }

   bool
   PersistentMessage::DeleteFile(shared_ptr<const Account> account, shared_ptr<Message> pMessage)
   {
      if (pMessage->GetPartialFileName().IsEmpty())
         return true;

      String messageFile = GetFileName(account, pMessage);

      LOG_DEBUG("Deleting message file");

      // We do not allow deletion of file if the message still
      // exists in the database.

      if (pMessage->GetID() > 0)
      {
         // A message with this ID already exists. Disallow deletion and log to 
         // the event logger.
         String sErrorMessage;
         sErrorMessage.Format(_T("Tried to delete the file %s even though the message was not deleted."), messageFile);

         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5025, "PersistentAccount::DeleteFile", sErrorMessage);


         return false;
      }


      bool bResult = FileUtilities::DeleteFile(messageFile);   

      return bResult;
   }

   bool
   PersistentMessage::UnlockAll()
   {
      SQLCommand command("update hm_messages set messagelocked = 0 where messagetype = 1 and messagelocked = 1");
      return Application::Instance()->GetDBManager()->Execute(command);
   }

   bool 
   PersistentMessage::ReadObject(shared_ptr<DALRecordset> pRS, shared_ptr<Message> pMessage, bool bReadRecipients)
   {
      LOG_DEBUG("Reading message from database");

      pMessage->SetID(pRS->GetInt64Value("messageid"));
      pMessage->SetAccountID(pRS->GetLongValue("messageaccountid"));
      pMessage->SetPartialFileName(pRS->GetStringValue("messagefilename"));

      pMessage->SetState((Message::State) pRS->GetLongValue("messagetype"));
      pMessage->SetFromAddress(pRS->GetStringValue("messagefrom"));
      pMessage->SetCreateTime(pRS->GetStringValue("messagecreatetime"));
      pMessage->SetSize(pRS->GetLongValue("messagesize"));
      pMessage->SetNoOfRetries((unsigned short) pRS->GetLongValue("messagecurnooftries"));
      pMessage->SetFolderID(pRS->GetLongValue("messagefolderid"));

      pMessage->SetFlags((short) pRS->GetLongValue("messageflags"));
      pMessage->SetUID((unsigned int) pRS->GetLongValue("messageuid"));

      if (bReadRecipients)
      {
         // The message recipients has been parsed.
         _ReadRecipients(pMessage);
      }


      if (pMessage->GetFolderID() > 0 && pMessage->GetUID() == 0)
      {
         // May be removed if it turns out not to result in any error.
         String sErrorMessage;
         sErrorMessage.Format(_T("The message %I64d in mailbox %I64d in account %I64d has no UID set."), 
            pMessage->GetID(), pMessage->GetFolderID(), pMessage->GetAccountID());

         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5025, "PersistentMessage::ReadObject", sErrorMessage);         
      }

      return true;
   }

   bool
   PersistentMessage::_ReadRecipients(shared_ptr<Message> pMessage)
   {
   
      shared_ptr<MessageRecipients> pRecipients = pMessage->GetRecipients();

      SQLCommand command("select * from hm_messagerecipients where recipientmessageid = @MESSAGEID");
      command.AddParameter("@MESSAGEID", pMessage->GetID());

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      while (pRS->IsEOF() == false)
      {
     
         shared_ptr<MessageRecipient> pRecipient = shared_ptr<MessageRecipient>(new MessageRecipient());

         pRecipient->SetAddress(pRS->GetStringValue("recipientaddress"));
         pRecipient->SetLocalAccountID(pRS->GetLongValue("recipientlocalaccountid"));
         pRecipient->SetMessageID(pRS->GetLongValue ("recipientmessageid"));
         pRecipient->SetOriginalAddress(pRS->GetStringValue("recipientoriginaladdress"));

         String sAddress = pRecipient->GetAddress();

         if (!MailerDaemonAddressDeterminer::IsMailerDaemonAddress(sAddress))
         {
            if (sAddress.IsEmpty())
               ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4201, "PersistentAccount::_ReadRecipients", "Read recipient from database without an address.");
            else
               pRecipients->Add(pRecipient);
         }

         pRS->MoveNext();
      }

   
      return true;
   }

   bool 
   PersistentMessage::ReadObject(shared_ptr<Message> pMessage, const SQLCommand &command)
   {
      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);

      if (!pRS || pRS->IsEOF())
         return false;

      ReadObject(pRS, pMessage);
  
      return true;
   }

   bool 
   PersistentMessage::ReadObject(shared_ptr<Message> pMessage, __int64 ObjectID)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads an object from the database.
   //---------------------------------------------------------------------------()
   {

      SQLCommand command("select * from hm_messages where messageid = @MESSAGEID");
      command.AddParameter("@MESSAGEID", ObjectID);

      return ReadObject(pMessage, command);

   }

   bool
   PersistentMessage::_SaveRecipients(shared_ptr<Message> pMessage)
   {
      std::vector<shared_ptr<MessageRecipient> > vecRecipients = pMessage->GetRecipients()->GetVector();
      std::vector<shared_ptr<MessageRecipient> >::iterator iterRecipient = vecRecipients.begin();

      while (iterRecipient != vecRecipients.end())
      {
         shared_ptr<MessageRecipient> pRecipient = (*iterRecipient);

         // Check that the recipient address is really specified
         if (pRecipient->GetAddress().IsEmpty() && pRecipient->GetLocalAccountID() == 0)
         {
            ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4224, "PersistentMessage::_SaveRecipients", "Tried to save recipient without an address.");

            iterRecipient++;
            continue;
         }

         // Update message ID in memory.
         pRecipient->SetMessageID(pMessage->GetID());

         // Do the saving
         SQLStatement oStatement;
         oStatement.AddColumnInt64("recipientmessageid", pRecipient->GetMessageID());
         oStatement.AddColumn("recipientaddress", pRecipient->GetAddress());
         oStatement.AddColumnInt64("recipientlocalaccountid", pRecipient->GetLocalAccountID());
         oStatement.AddColumn("recipientoriginaladdress", pRecipient->GetOriginalAddress());

         oStatement.SetTable ("hm_messagerecipients");
         oStatement.SetStatementType(SQLStatement::STInsert);
         oStatement.SetIdentityColumn("recipientid");
      
         bool bResult = Application::Instance()->GetDBManager()->Execute(oStatement);

         if (!bResult)
            return false;

         iterRecipient++;

      }

      return true;
   }

   bool
   PersistentMessage::LockObject(__int64 ObjectID)
   {
      ASSERT(ObjectID > 0);

      SQLCommand command("update hm_messages set messagelocked = 1 where messageid = @MESSAGEID");
      command.AddParameter("@MESSAGEID", ObjectID);

      return Application::Instance()->GetDBManager()->Execute(command);
   
      return false;
   }

   bool
   PersistentMessage::LockObject(shared_ptr<Message> pMessage)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Locks the message in the database.
   //---------------------------------------------------------------------------()
   {
      return LockObject (pMessage->GetID());
   }  

   bool
   PersistentMessage::UnlockObject(shared_ptr<Message> pMessage)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Unlocks the object in the database.
   //---------------------------------------------------------------------------()
   {
      ASSERT(pMessage->GetID() > 0);

      SQLCommand command("update hm_messages set messagelocked = 0 where messageid = @MESSAGEID");
      command.AddParameter("@MESSAGEID", pMessage->GetID());

      return Application::Instance()->GetDBManager()->Execute(command);
   }

   shared_ptr<Message>
   PersistentMessage::CopyToQueue(shared_ptr<const Account> sourceAccount, shared_ptr<Message> sourceMessage)
   {
      shared_ptr<Message> newMessage = _CreateCopy(sourceMessage, 0);
      newMessage->SetState(Message::Delivering);

      // Copy the message file.
      const String sourceFile = GetFileName(sourceAccount, sourceMessage);
      const String destinationFile = GetFileName(newMessage, QueueFolder);

      if (!FileUtilities::Copy(sourceFile, destinationFile, true))
      {
         shared_ptr<Message> pEmpty;
         return pEmpty;
      }

      return newMessage;
   }

   shared_ptr<Message>
   PersistentMessage::CopyToIMAPFolder(shared_ptr<const Account> sourceAccount, shared_ptr<Message> sourceMessage, shared_ptr<IMAPFolder> destinationFolder)
   {
      shared_ptr<Message> messageCopy = _CreateCopy(sourceMessage, (int) destinationFolder->GetAccountID());
      messageCopy->SetState(Message::Delivered);
      messageCopy->SetFolderID(destinationFolder->GetID());

      // Copy the message file.
      const String sourceFile = GetFileName(sourceAccount, sourceMessage);
      
      String destinationFile = "";
      
      if (destinationFolder->IsPublicFolder())
         destinationFile = GetFileName(messageCopy, PublicFolder);
      else
      {
         // Copy within the same account.
         destinationFile = GetFileName(sourceAccount, messageCopy, AccountFolder);
      }

      if (!FileUtilities::Copy(sourceFile, destinationFile, true))
      {
         shared_ptr<Message> pEmpty;
         return pEmpty;
      }

      return messageCopy;
   }

   shared_ptr<Message>
   PersistentMessage::CopyFromQueueToInbox(shared_ptr<Message> sourceMessage, shared_ptr<const Account> destinationAccount)
   {
      shared_ptr<Message> messageCopy = _CreateCopy(sourceMessage, (int) destinationAccount->GetID());
      messageCopy->SetState(Message::Delivered);

      // Locate the inbox ID
      __int64  inboxID = CacheContainer::Instance()->GetInboxIDCache().GetUserInboxFolder(destinationAccount->GetID());
      if (inboxID == 0)
      {
         shared_ptr<Message> empty;
         return empty;
      }

      messageCopy->SetFolderID(inboxID);

      const String sourceFile = GetFileName(sourceMessage, QueueFolder);
      const String destinationFile = GetFileName(destinationAccount, messageCopy, AccountFolder);
      String destinationPath = FileUtilities::GetFilePath(destinationFile);

      if (!FileUtilities::Copy(sourceFile, destinationFile, true))
      {
         shared_ptr<Message> pEmpty;
         return pEmpty;
      }

      return messageCopy;
   }

   shared_ptr<Message>
   PersistentMessage::_CreateCopy(shared_ptr<Message> sourceMessage, int destinationAccountID)
   {
      LOG_DEBUG("Copying mail contents");
      shared_ptr<Message> pTo = shared_ptr<Message>(new Message(true));

      shared_ptr<MessageRecipients> pToRecipients = pTo->GetRecipients();
      pToRecipients->Clear();

      pTo->SetAccountID(destinationAccountID);
      pTo->SetSize(sourceMessage->GetSize());
      pTo->SetFromAddress(sourceMessage->GetFromAddress());
      pTo->SetState(sourceMessage->GetState());
      pTo->SetCreateTime(sourceMessage->GetCreateTime());
      pTo->SetFlags(sourceMessage->GetFlags());

      return pTo;
   }

   bool
   PersistentMessage::SaveObject(shared_ptr<Message> pMessage, String &errorMessage)
   {
      // errorMessage - not supported yet.
      return SaveObject(pMessage);
   }


   bool
   PersistentMessage::SaveObject(shared_ptr<Message> pMessage)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Saves the object in the database. If the message already exist, it is
   // updated. After a message has been added, the message-id of it is updated.
   //---------------------------------------------------------------------------()
   {
   
      if (pMessage->GetState() == Message::Created)
      {
         // The message should either be delivered, or it should currently
         // be delivering.
         ErrorManager::Instance()->ReportError(ErrorManager::High, 5111, "PersistentMessage::SaveObject", "The message could not be saved in the database. Message state is 'Created'");
         return false;
      }

      bool bNewMessage = pMessage->GetID() == 0;

      if (pMessage->GetAccountID() > 0)
      {
         // Increase account size cache.
         if (pMessage->GetUID() == 0)
         {
            AccountSizeCache::Instance()->ModifySize(pMessage->GetAccountID(), pMessage->GetSize(), true);
         }
      }

      if (!AddObject(pMessage))
         return false;

      // Should we fetch the message id now?
      if (bNewMessage && pMessage->GetRecipients()->GetCount())
      {
         // If there are any recipients, save them in the database.
         if (!_SaveRecipients(pMessage))
            return false;

         // Message is now completely saved so we may unlock it so that
         // it can be delivered by the SMTPDeliveryManager.
         SQLCommand command("update hm_messages set messagelocked = 0 where messageid = @MESSAGEID");
         command.AddParameter("@MESSAGEID", pMessage->GetID());

         bool bResult = Application::Instance()->GetDBManager()->Execute(command);
         
         if (!bResult)
            return false;

      }

      return true;
   }

   bool 
   PersistentMessage::AddObject(const shared_ptr<Message> pMessage)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Adds an object to the database. If the message already exists, 
   // it is updated. The contents of pMessage is not modified, so don't
   // use this if you want to be able to fetch thed ID after just having
   // inserted the ID.
   //---------------------------------------------------------------------------()
   {
      if (!pMessage->GetSize())
      {
         LOG_DEBUG("Aborting save since the message is zero bytes.");
         return false;
      }

      if (pMessage->GetState() == Message::Delivered && pMessage->GetFolderID() == 0)
      {
         ErrorManager::Instance()->ReportError(ErrorManager::High, 5213, "PersistentMessage::AddObject", "Aborting save since no folder was specified.");
         return false;
      }

      bool bNewObject = true;
      if (pMessage->GetID())
         bNewObject = false;

      // If recipients exists, we need to save the message as locked
      // since the recipients aren't saved in the database yet.
      bool bRecipientsExists = pMessage->GetRecipients()->GetCount() > 0;

      SQLStatement oStatement;
      oStatement.SetTable("hm_messages");

      if (bNewObject)
         pMessage->SetFlagRecent(true);

      oStatement.AddColumnInt64("messageaccountid", pMessage->GetAccountID());
      oStatement.AddColumn("messagefilename", pMessage->GetPartialFileName());
      oStatement.AddColumn("messagetype", pMessage->GetState());
      oStatement.AddColumn("messagefrom", pMessage->GetFromAddress());
      oStatement.AddColumn("messagesize", pMessage->GetSize());
      oStatement.AddColumn("messageflags", pMessage->GetFlags());
      oStatement.AddColumnInt64("messagefolderid", pMessage->GetFolderID());
    
      LOG_DEBUG("Saving message: " + pMessage->GetPartialFileName());

      // We need to retrieve a new unique ID for this folder. Lock it.
      FolderManipulationLock folderLock((int) pMessage->GetAccountID(), (int) pMessage->GetFolderID());
      
      if (pMessage->GetState() == Message::Delivered)
      {
         // If we're placing messages in a mailbox, we must synchronize the access to it.
         // The message UID's must be inserted in a strictly ascending fashion.
         folderLock.Lock();   
      }
   
      /*
         Check if this message is moved into a mailbox. If it is, we need to assign 
         an UID to the message.
      */
      if (pMessage->GetFolderID() > 0 && pMessage->GetUID() == 0 )
      {
         // Retrieve the last Unique ID for this folder.
         unsigned currentUID = PersistentIMAPFolder::GetUniqueMessageID(pMessage->GetAccountID(), pMessage->GetFolderID());

         if (currentUID == 0)
         {
            String errorMessage;
            errorMessage.Format(_T("Failed to generate UID for message. Account ID: %I64d, Folder ID: %I64d"), pMessage->GetAccountID(), pMessage->GetFolderID());
            ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5205, "PersistentMessage::AddObject", errorMessage);

            return false;
         }

         // Set back the new UID to the message.
         pMessage->SetUID(currentUID);

         oStatement.AddColumnInt64("messageuid", pMessage->GetUID());

      }
      else
      {
         // Save the already existing UID. This happens for example if we update an existing
         // message or restore a backup.
         oStatement.AddColumnInt64("messageuid", pMessage->GetUID());
      }


      if (bNewObject)
      {
         
         // Save current time as create time
         String sCreateTime = pMessage->GetCreateTime();
         if (sCreateTime.IsEmpty())
         {
            sCreateTime = Time::GetCurrentDateTime();
            pMessage->SetCreateTime(sCreateTime);
         }

         oStatement.SetStatementType(SQLStatement::STInsert);
         oStatement.SetIdentityColumn("messageid");

         oStatement.AddColumn("messagelocked", bRecipientsExists ? 1 : 0);
         oStatement.AddColumn("messagecreatetime", sCreateTime);
         oStatement.AddColumn("messagecurnooftries", 0);
         oStatement.AddColumn("messagenexttrytime",  "1901-01-01");
      }
      else
      {
         oStatement.SetStatementType(SQLStatement::STUpdate);

         String sWhere;
         sWhere.Format(_T("messageid = %I64d"), pMessage->GetID());

         oStatement.SetWhereClause(sWhere);

      }

      __int64 iDBID = 0;
      bool bRetVal = Application::Instance()->GetDBManager()->Execute(oStatement, bNewObject ? &iDBID : 0);
      if (bRetVal && bNewObject)
      {
         pMessage->SetID(iDBID);
      }

      return bRetVal;
   }

   bool
   PersistentMessage::SetNextTryTime(__int64 iMessageID, bool bUpdateNoOfTries, long lNoOfMinutes)
   {
      LOG_DEBUG("PersistentMessage::SetNextTryTime()");

      String sUpdateSQL = Formatter::Format("update hm_messages set messagenexttrytime = {0} ", SQLStatement::GetCurrentTimestampPlusMinutes(lNoOfMinutes));

      if (bUpdateNoOfTries)
         sUpdateSQL += " , messagecurnooftries = messagecurnooftries + 1 ";
   
      String sWhereClause = _T("where messageid = @MESSAGEID");

      sUpdateSQL += sWhereClause;

      SQLCommand command(sUpdateSQL);
      command.AddParameter("@MESSAGEID", iMessageID);

      bool bResult = Application::Instance()->GetDBManager()->Execute(command);

      LOG_DEBUG("PersistentMessage::~SetNextTryTime()");

      return bResult;
   }

   bool
   PersistentMessage::MoveFileToPublicFolder(const String &sourceLocation, shared_ptr<Message> pMessage)
   {
      String dataDirectory = IniFileSettings::Instance()->GetDataDirectory();
      String publicFolder = FileUtilities::Combine(dataDirectory, IMAPConfiguration::GetPublicFolderDiskName());

      String destinationFileName = GetFileName(pMessage, PublicFolder);
      String destinationPath = FileUtilities::GetFilePath(destinationFileName);

      // Before we move the file to the new path, make sure that the directory exists.
      // We start by checking if it already exists. If not, attempt to create. We used
      // to create each folder before. Checking first will save some disk access.
      if (!FileUtilities::Exists(destinationPath))
         FileUtilities::CreateDirectoryRecursive(destinationPath);

      // Move the old file to the new path.
      if (!FileUtilities::Move(sourceLocation, destinationFileName))
         return false;

      return true;
   }

   bool
   PersistentMessage::MoveFileToUserFolder(const String &sourceLocation, shared_ptr<Message> pMessage, shared_ptr<const Account> destinationAccount)
   {
      String dataDirectory = IniFileSettings::Instance()->GetDataDirectory();

      String domainName = StringParser::ExtractDomain(destinationAccount->GetAddress());
      String mailboxName  = StringParser::ExtractAddress(destinationAccount->GetAddress());
         
      String destinationFileName = GetFileName(destinationAccount->GetAddress(), pMessage, AccountFolder);
      String destinationPath = FileUtilities::GetFilePath(destinationFileName);

      // Before we move the file to the new path, make sure that the directory exists.
      // We start by checking if it already exists. If not, attempt to create. We used
      // to create each folder before. Checking first will save some disk access.
      if (!FileUtilities::Exists(destinationPath))
         FileUtilities::CreateDirectoryRecursive(destinationPath);

      // Move the old file to the new path.
      if (!FileUtilities::Move(sourceLocation, destinationFileName))
         return false;

      return true;
   }

   void
   PersistentMessage::EnsureFileExistance(shared_ptr<const Account> account, shared_ptr<Message> pMessage)
   {
      String sFileName = GetFileName(account, pMessage);
      if (FileUtilities::Exists(sFileName))
         return;

      // File doesn't exist. We need to create it, so that we can deliver
      // something useful to the client. We start of by creating the directory
      // in which the message should be put. If the dir doesn't exist, we'll
      // have slight problems creating a file in it.
      String sPath = FileUtilities::GetFilePath(sFileName);
      FileUtilities::CreateDirectoryRecursive(sPath);


      // The file does not exists. May have been deleted
      // by anti virus software.
      String sMessageUndeliverable = Configuration::Instance()->GetServerMessages()->GetMessage("MESSAGE_UNDELIVERABLE");
      String sMessageBody = Configuration::Instance()->GetServerMessages()->GetMessage("MESSAGE_FILE_MISSING");

      // Replace macros
      sMessageBody.Replace(_T("%MACRO_FILE%"), sFileName);

      String sErrorMessage;
      sErrorMessage.Format(_T("From: Postmaster\r\n")
                           _T("Subject: %s\r\n")
                           _T("Date: %s\r\n")
                           _T("\r\n")
                           _T("%s")
                           _T("\r\n"),
                           sMessageUndeliverable,
                           Time::GetCurrentMimeDate(),
                           sMessageBody,
                           sFileName);

      

      FileUtilities::WriteToFile(sFileName, sErrorMessage, false);

      // Update the database with the new size of the file.
      pMessage->SetSize(FileUtilities::FileSize(sFileName));

      // Save the new size.
      SaveObject(pMessage);

      // Log the error.
      ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5026, "PersistentMessage::_WriteDataToMessageFile", "Message retrieval failed because message file " + sFileName + " did not exist.");
   }

   bool
   PersistentMessage::AllMessageFilesAreInDataFolder()
   {
      String sDataDir = IniFileSettings::Instance()->GetDataDirectory();

      int iLen = sDataDir.GetLength();
      
      String leftFilenameDataDir = SQLStatement::GetLeftFunction("messagefilename", iLen);
      String leftFilenameFirstChar = SQLStatement::GetLeftFunction("messagefilename", 1);


      SQLCommand command(Formatter::Format("select count(*) as msgcount from hm_messages where {0} <> @DATADIR and {1} <> @BRACE", leftFilenameDataDir, leftFilenameFirstChar));
      command.AddParameter("@DATADIR", sDataDir);
      command.AddParameter("@BRACE", "{");

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      long lMsgCount = pRS->GetLongValue("msgcount");

      if (lMsgCount == 0)
         return true;
      else
         return false;
   }

   bool
   PersistentMessage::AllMessageFilesArePartialNames()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Returns true if all message files in the database only have their partial
   // named stored (i.e. {abc} rather than C:\datadir\{abc}
   //---------------------------------------------------------------------------()
   {
      String leftFilenameFirstChar = SQLStatement::GetLeftFunction("messagefilename", 1);

      SQLCommand command(Formatter::Format("select count(*) as msgcount from hm_messages where {0} <> @BRACE", leftFilenameFirstChar));
      command.AddParameter("@BRACE", "{");

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      long lMsgCount = pRS->GetLongValue("msgcount");

      if (lMsgCount == 0)
         return true;
      else
         return false;
   }

   __int64
   PersistentMessage::GetTotalMessageSize()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Returns the total size of all messages, calculated in megabytes.
   //---------------------------------------------------------------------------()
   {
      SQLCommand command("select sum(messagesize) / 1024 / 1024 as mailboxsize from hm_messages");
      
      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      // Different data types on MySQL and MSSQL...

      __int64 iSize = 0;
      switch (IniFileSettings::Instance()->GetDatabaseType())
      {
      case DatabaseSettings::TypeMYSQLServer:
         iSize = (__int64) pRS->GetDoubleValue("mailboxsize");;
         break;
      case DatabaseSettings::TypeMSSQLServer:
         iSize = (__int64) pRS->GetInt64Value("mailboxsize");;
         break;
      case DatabaseSettings::TypePGServer:
         iSize = (__int64) pRS->GetInt64Value("mailboxsize");;
         break;

      case DatabaseSettings::TypeUnknown:
         assert(0);
      }

      return iSize;
   }

   int
   PersistentMessage::GetTotalMessageCount()
   {
      SQLCommand command("select count(*) as c from hm_messages");

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      int result = pRS->GetLongValue("c");

      return result;
   }

   int
   PersistentMessage::GetTotalMessageCountDelivered()
   {
      SQLCommand command ("select count(*) as c from hm_messages where messagetype = @MESSAGETYPE");
      command.AddParameter("@MESSAGETYPE", Message::Delivered);
      
      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      int result = pRS->GetLongValue("c");

      return result;
   }

   bool
   PersistentMessage::DeleteByAccountID(__int64 iAccountID)
   {
      // delete the file messages
      SQLCommand selectCommand ("select messagefilename from hm_messages where messageaccountid = @ACCOUNTID");
      selectCommand.AddParameter("@ACCOUNTID", iAccountID);

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(selectCommand);
      if (!pRS)
         return false;

      SQLCommand deleteCommand ("delete from hm_messages where messageaccountid =  @ACCOUNTID");
      deleteCommand.AddParameter("@ACCOUNTID", iAccountID);

      bool bDeleteOK = Application::Instance()->GetDBManager()->Execute(deleteCommand);
      if (!bDeleteOK)
         return false;

      while (!pRS->IsEOF())
      {
         String sFileName = pRS->GetStringValue("messagefilename");;

         if (!FileUtilities::DeleteFile(sFileName))
         {
            String sErrorMessage;
            sErrorMessage.Format(_T("Failed to delete file %s while deleting messages in account %I64d"), sFileName, iAccountID);

            ErrorManager::Instance()->ReportError(ErrorManager::Medium, 5024, "PersistentAccount::DeleteMessages", sErrorMessage);
         }

         pRS->MoveNext();
      }

      return true;
   }

   AnsiString
   PersistentMessage::LoadHeader(const String &fileName)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads the entire message from the disk.
   //---------------------------------------------------------------------------()
   {
      return LoadHeader(fileName, true);
   }

   AnsiString
   PersistentMessage::LoadHeader(const String &fileName, bool reportError)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads the entire message from the disk.
   //---------------------------------------------------------------------------()
   {
      const int iReadBufferSize = 50000;

      String sHeaderData; 

      HANDLE handleFile;

      handleFile = CreateFile(fileName, 
         GENERIC_READ, 
         FILE_SHARE_READ, 
         NULL, // LPSECURITY_ATTRIBUTES
         OPEN_EXISTING, // -- open or create.
         FILE_ATTRIBUTE_NORMAL, // attributes
         NULL // file template
         );

      if (handleFile == INVALID_HANDLE_VALUE || handleFile < 0) 
      {
         if (reportError)
         {
            ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4403, "Message::GetHeader", "Could not read the message header, since the file was not available. File: " + fileName);
         }

         return sHeaderData;
      }

      int iHeaderEnd = -1;

      BYTE buf[iReadBufferSize + 1];

      unsigned long nbytes = 0;
      BOOL bMoreData = TRUE;
      int nBytesSent = 0;

      while (bMoreData)
      {
         ReadFile(handleFile,buf,iReadBufferSize, &nbytes, NULL);

         if (nbytes) 
         {
            sHeaderData += AnsiString((char*)buf, nbytes);
         }
         else
            bMoreData = FALSE;

         // Check if we have read the entire header.
         iHeaderEnd = sHeaderData.Find(_T("\r\n\r\n"));

         if (iHeaderEnd >= 0)
            bMoreData = FALSE;

      }

      CloseHandle(handleFile);

      if (iHeaderEnd == -1)
         return sHeaderData;

      iHeaderEnd += 2;

      return sHeaderData.Left(iHeaderEnd);
   }

   AnsiString
   PersistentMessage::LoadBody(const String &fileName)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reads the entire message from the disk.
   //---------------------------------------------------------------------------()
   {
      const int iReadBufferSize = 10000;

      HANDLE handleFile = CreateFile(fileName, 
         GENERIC_READ, 
         FILE_SHARE_READ, 
         NULL, // LPSECURITY_ATTRIBUTES
         OPEN_EXISTING, // -- open or create.
         FILE_ATTRIBUTE_NORMAL, // attributes
         NULL // file template
         );

      if (handleFile == INVALID_HANDLE_VALUE || handleFile < 0) 
      {
         ErrorManager::Instance()->ReportError(ErrorManager::Medium, 4403, "Message::GetHeader", "Could not read the message header, since the file was not available. File: " + fileName);
         return "";
      }

      int iHeaderEnd = -1;

      BYTE buf[iReadBufferSize + 1];

      unsigned long nbytes = 0;
      int nBytesSent = 0;
      bool foundHeader = false;

      AnsiString retVal; 

      while (true)
      {
         ReadFile(handleFile,buf,iReadBufferSize, &nbytes, NULL);

         if (!nbytes) 
            break;

         AnsiString readData = AnsiString((char*)buf, nbytes);

         // Check if we have read the entire header.
         if (!foundHeader)
         {
            iHeaderEnd = readData.Find("\r\n\r\n");
            if (iHeaderEnd >= 0)
            {
               int startReadPos = iHeaderEnd+4;
               int remainingLength = nbytes -startReadPos;
               if(remainingLength>0)
               {
                  readData = readData.Mid(startReadPos, remainingLength );
                  foundHeader = true;
               }
            }
         }

         if (foundHeader)
            retVal.append(readData);

      }

      CloseHandle(handleFile);

      return retVal;
   }

   String 
   PersistentMessage::GetFileName(shared_ptr<const Message> message)
   {
      shared_ptr<Account> account;

      return GetFileName(account, message);
   }

   String 
   PersistentMessage::GetFileName(shared_ptr<const Message> message, FileLocation location)
   {
      return GetFileName("", message, location);
   }

   String 
   PersistentMessage::GetFileName(shared_ptr<const Account> account, shared_ptr<const Message> message)
   {
      String accountAddress = account ? account->GetAddress() : "";

      return GetFileName(accountAddress, message);
   }

   String 
   PersistentMessage::GetFileName(shared_ptr<const Account> account, shared_ptr<const Message> message, FileLocation location)
   {
      String accountAddress = account ? account->GetAddress() : "";

      return GetFileName(accountAddress, message, location);
   }

   String 
   PersistentMessage::GetFileName(const String &accountAddress, shared_ptr<const Message> message)
   {
      FileLocation location;

      if (accountAddress.GetLength() > 0 && message->GetAccountID() > 0)
      {
         location = AccountFolder;
      }
      else if (message->GetFolderID() > 0)
      {
         location = PublicFolder;
      }
      else
      {
         location = QueueFolder;
      }

      return GetFileName(accountAddress, message, location);
   }

   String 
   PersistentMessage::GetFileName(const String &accountAddress, shared_ptr<const Message> message, FileLocation location)
   {
      String partialFileName = message->GetPartialFileName();

      if (FileUtilities::IsFullPath(partialFileName))
         return partialFileName;

      String dataDirectory = IniFileSettings::Instance()->GetDataDirectory();

      String fullFileName;

      switch (location)
      {
      case AccountFolder:
         {
            // Message is placed in an account folder.
            String domainName = StringParser::ExtractDomain(accountAddress);
            String domainFolder = FileUtilities::Combine(dataDirectory, domainName);

            String accountFolderName = StringParser::ExtractAddress(accountAddress);
            String accountFolder = FileUtilities::Combine(domainFolder, accountFolderName);

            // The message is placed in a folder containing the two first characters of the guid file name.
            String guidFolder = FileUtilities::Combine(accountFolder, partialFileName.Mid(1,2));

            fullFileName = FileUtilities::Combine(guidFolder, partialFileName);
            break;
         }
      case PublicFolder:
         {
            // Message is placed in public folder.
            String publicFolder = FileUtilities::Combine(dataDirectory, IMAPConfiguration::GetPublicFolderDiskName());

            // The message is placed in a folder containing the two first characters of the guid file name.
            String guidFolder = FileUtilities::Combine(publicFolder, partialFileName.Mid(1,2));

            fullFileName = FileUtilities::Combine(guidFolder, partialFileName);
            break;
         }
      case QueueFolder:
         {
             fullFileName = FileUtilities::Combine(dataDirectory, partialFileName);        
             break;
         }
      }

      return fullFileName;
   }


   bool
   PersistentMessage::GetPartialFilename(const String &fullPath, String &partialPath)
   {
      // The file must be located in the data directory. Make sure this is the case.
      const String dataDirectory = IniFileSettings::Instance()->GetDataDirectory();

      if (!fullPath.StartsWith(dataDirectory))
         return false;

      // Trim away the data directory
      String filePath = fullPath.Mid(dataDirectory.GetLength() + 1);

      // Is the file in the public folder?
      String publicFolderName = IMAPConfiguration::GetPublicFolderDiskName();

      if (filePath.StartsWith(publicFolderName))
      {
         // Trim it away.
         filePath = filePath.Mid(publicFolderName.GetLength() + 1);

         int guidSlashPos = filePath.Find(_T("\\"));
         if (guidSlashPos <= 0)
            return false;

         // Make sure the message is located in a correctly named folder.
         if (guidSlashPos != 2)
            return false;

         String lastLevelName = filePath.Mid(guidSlashPos);

         filePath = filePath.Mid(guidSlashPos+1);

         if (lastLevelName != filePath.Mid(1,2))
            return false;
      }
      else
      {
         // Is the file located in a sub directory? (In a domain folder).
         int domainSlashPos = filePath.Find(_T("\\"));
         if (domainSlashPos >= 0)
         {
            // Yes, we need to trim it away. 
            int accountSlashPos = filePath.Find(_T("\\"), domainSlashPos+1);
            if (accountSlashPos <= 0)
               return false;

            int guidSlashPos = filePath.Find(_T("\\"), accountSlashPos+1);
            if (guidSlashPos <= 0)
               return false;

            // Make sure the message is located in a correctly named folder.
            int lastLevelLength = guidSlashPos - accountSlashPos-1;
            if (lastLevelLength != 2)
               return false;

            String lastLevelName = filePath.Mid(accountSlashPos+1, lastLevelLength);

            filePath = filePath.Mid(guidSlashPos+1);
            
            if (lastLevelName != filePath.Mid(1,2))
               return false;
           
         }
      }

      partialPath = filePath;
      return true;
   }

   bool 
   PersistentMessage::SaveFlags(shared_ptr<Message> message)
   {
      // Create a statement object.
      String statement = "UPDATE hm_messages SET messageflags = @FLAGS WHERE messageid = @MESSAGEID";

      SQLCommand sqlCommand(statement);
      sqlCommand.AddParameter("@FLAGS", message->GetFlags());
      sqlCommand.AddParameter("@MESSAGEID", message->GetID());

      return Application::Instance()->GetDBManager()->Execute(sqlCommand);
   }
}
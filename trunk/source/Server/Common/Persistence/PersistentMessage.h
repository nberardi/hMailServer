// Copyright (c) 2005 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;
   class Domain;
   class Account;
   class IMAPFolder;

   class PersistentMessage 
                     
   {
   public:
	   PersistentMessage();
	   virtual ~PersistentMessage();

      enum FileLocation
      {  
         QueueFolder = 1,
         PublicFolder = 2,
         AccountFolder = 3
      };

      static boost::shared_ptr<Message> CopyToQueue(boost::shared_ptr<const Account> sourceAccount, boost::shared_ptr<Message> sourceMessage);
      static boost::shared_ptr<Message> CopyToIMAPFolder(boost::shared_ptr<const Account> sourceAccount, boost::shared_ptr<Message> sourceMessage, boost::shared_ptr<IMAPFolder> destinationFolder);
      static boost::shared_ptr<Message> CopyFromQueueToInbox(boost::shared_ptr<Message> sourceMessage, boost::shared_ptr<const Account> destinationAccount);

      static bool DeleteObject(boost::shared_ptr<Message> pMessage);
      static bool SaveObject(boost::shared_ptr<Message> pMessage);
      static bool SaveObject(boost::shared_ptr<Message> pMessage, String &errorMessage);
      static bool AddObject(const boost::shared_ptr<Message> pMessage);
      static bool LockObject(__int64 ObjectID);
      static bool LockObject(boost::shared_ptr<Message> pMessage );
      static bool UnlockObject(boost::shared_ptr<Message> pMessage);
      static bool UnlockAll();
      static bool DeleteFile(boost::shared_ptr<const Account> account, boost::shared_ptr<Message> pMessage);

      static bool GetMessageID(const String &fileName, __int64 &messageID, bool &isPartialFilename);
      static bool ReadObject(boost::shared_ptr<DALRecordset> pRS, boost::shared_ptr<Message> pMessage, bool bReadRecipients = true);
      static bool ReadObject(boost::shared_ptr<Message> pMessage, __int64 ObjectID);
      static bool ReadObject(boost::shared_ptr<Message> pMessage, const SQLCommand &command);

      static bool SetNextTryTime(__int64 iMessageID, bool bUpdateNoOfTries, long lNoOfMinutes);
      static void EnsureFileExistance(boost::shared_ptr<const Account> account, boost::shared_ptr<Message> pMessage);
      
      static bool MoveFileToPublicFolder(const String &sourceLocation, boost::shared_ptr<Message> pMessage);
      static bool MoveFileToUserFolder(const String &sourceLocation, boost::shared_ptr<Message>, boost::shared_ptr<const Account> destinationAccount);

      static bool GetAllMessageFilesAreInDataFolder();
      static bool GetAllMessageFilesArePartialNames();

      static int GetTotalMessageCount();
      static int GetTotalMessageCountDelivered();
      
      static __int64 GetTotalMessageSize();
      // Returns the total size of all messages, calculated in megabytes

      static bool DeleteByAccountID(__int64 iAccountID);

      static AnsiString LoadHeader(const String &fileName);
      static AnsiString LoadHeader(const String &fileName, bool reportError);
      static AnsiString LoadBody(const String &fileName);

      static String GetFileName(boost::shared_ptr<const Message> message);
      static String GetFileName(boost::shared_ptr<const Message> message, FileLocation location);
      static String GetFileName(boost::shared_ptr<const Account> account, boost::shared_ptr<const Message> message);
      static String GetFileName(boost::shared_ptr<const Account> account, boost::shared_ptr<const Message> message, FileLocation location);
      static String GetFileName(const String &accountAddress, boost::shared_ptr<const Message> message);
      static String GetFileName(const String &accountAddress, boost::shared_ptr<const Message> message, FileLocation location);

      static bool GetPartialFilename(const String &fullPath, String &partialPath);

      static bool SaveFlags(boost::shared_ptr<Message> message);


      static bool IsPartialPath(const String &path);
   private:
      
      static boost::shared_ptr<Message> _CreateCopy(boost::shared_ptr<Message> sourceMessage, int destinationAccountID);

      static bool _MoveMessageFileToFolder(const String &sourceLocation, boost::shared_ptr<Message> pMessage, boost::shared_ptr<const Account> destinationAccount);

      // Recipient functions begin
      static bool _ReadRecipients(boost::shared_ptr<Message> pMessage);
      static bool _SaveRecipients(boost::shared_ptr<Message> pMessage);
      // Recipient functions end
   };

   typedef boost::shared_ptr<Message> MessageSP;
}

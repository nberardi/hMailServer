// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "Collection.h"

#include "../BO/Message.h"
#include "../Persistence/PersistentMessage.h"

namespace HM
{

   typedef std::vector<boost::shared_ptr<Message> > MessagesVector;
   typedef std::vector<boost::shared_ptr<Message> >::iterator MessagesIterator;

   class Messages : public Collection<Message, PersistentMessage>
   {
   public:
	   Messages(__int64 iAccountID, __int64 iFolderID);
	   virtual ~Messages();

      void Save();
      void UndeleteAll();

      long GetSize() const;
      __int64 GetFirstUnseenUID() const;
      long GetNoOfSeen() const;
      long GetNoOfRecent() const;
      
      std::vector<boost::shared_ptr<Message>> GetCopy();
      std::vector<int> Expunge();
      std::vector<int> Expunge(bool messagesMarkedForDeletion, const std::set<int> &uids, const boost::function<void()> &func);
      std::vector<int> DeleteMessages();

      boost::shared_ptr<Message> GetItemByUID(unsigned int uid);
      boost::shared_ptr<Message> GetItemByUID(unsigned int uid, unsigned int &foundIndex);

      void Refresh();

      bool DeleteMessageByDBID(__int64 ID);

      void AddToCollection(boost::shared_ptr<DALRecordset> pRS);
      
      void Remove(__int64 iDBID);

      void SetFlagRecentOnMessages(bool bRecent);
      void AddItem(boost::shared_ptr<Message> pObject);

      __int64 GetAccountID() {return m_iAccountID; }
      __int64 GetFolderID() {return m_iFolderID; }

   protected:
      virtual String GetCollectionName() const {return "Messages"; }
      virtual bool PreSaveObject(boost::shared_ptr<Message> pMessage, XNode *node);
   private:

      unsigned int _lastRefreshedUID;

      __int64 m_iAccountID;
      __int64 m_iFolderID;
   };
}

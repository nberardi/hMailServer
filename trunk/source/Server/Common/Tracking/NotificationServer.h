// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class NotificationClient;
   class ChangeNotification;
   class NotificationClientSubscription;

   class NotificationServer
   {
   public:
      NotificationServer();

      void SendNotification(boost::shared_ptr<ChangeNotification> pChangeNotification);
      void SendNotification(boost::shared_ptr<NotificationClient> source, boost::shared_ptr<ChangeNotification> pChangeNotification);

      __int64 SubscribeMessageChanges(__int64 accountID, __int64 folderID, boost::shared_ptr<NotificationClient> pChangeClient);
      void UnsubscribeMessageChanges(__int64 accountID, __int64 folderID, __int64 subscriptionKey);

      __int64 SubscribeFolderListChanges(__int64 accountID, boost::shared_ptr<NotificationClient> pChangeClient);
      void UnsubscribeFolderListChanges(__int64 accountID, __int64 subscriptionKey);

   private:

      set<boost::shared_ptr<NotificationClient> > _GetClientsToNotify(boost::shared_ptr<NotificationClient> source, boost::shared_ptr<ChangeNotification> pChangeNotification);

      std::multimap<std::pair<__int64, __int64>, boost::shared_ptr<NotificationClientSubscription> > _messageChangeSubscribers;
      std::multimap<__int64, boost::shared_ptr<NotificationClientSubscription> > _folderListChangeSubscribers;

      CriticalSection _criticalSection;

      __int64 _subscriptionCounter;
   };
}

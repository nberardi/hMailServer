// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "../Util/Event.h"

namespace HM
{
 
   class SMTPDeliveryManager;
   class ExternalFetchManager;
   class BackupManager;
   class DatabaseConnectionManager;
   class Scheduler;
   class WorkQueue;
   class IOCPServer;
   class ServerMessages;
   class NotificationServer;
   class FolderManager;

   class Application : public Singleton<Application>
   {
   public:

	   Application();
	   virtual ~Application();

      static String GetExecutableName();

      // --- global 
      boost::shared_ptr<DatabaseConnectionManager> GetDBManager() { return m_pDBManager; }

      // --- overridables
      virtual bool InitInstance(String &sErrorMessage);
      virtual bool ExitInstance();

      String GetVersion() const;
      String GetVersionNumber() const {return m_sVersion;}

      String GetStartTime() const {return m_sStartTime; }

      bool OpenDatabase(String &sErrorMessage);
      void CloseDatabase();

      
      String GetLastErrorMessage() {return m_sLastConnectErrorMessage; }; 

      bool StartServers();
      void StopServers();
      void SubmitPendingEmail();

      boost::shared_ptr<SMTPDeliveryManager> GetSMTPDeliveryManager() {return m_pSMTPDeliveryManager;} 
      boost::shared_ptr<ExternalFetchManager> GetExternalFetchManager() {return m_pExternalFetchManager;} 

      boost::shared_ptr<BackupManager> GetBackupManager() {return m_pBackupManager; }

      boost::shared_ptr<WorkQueue> GetRandomWorkQueue();
      boost::shared_ptr<WorkQueue> GetAsyncWorkQueue();
      boost::shared_ptr<IOCPServer> GetIOCPServer() {return m_pIOCPServer; }
      // The random work queue can run any task.

      boost::shared_ptr<NotificationServer> GetNotificationServer();
      boost::shared_ptr<FolderManager> GetFolderManager();

      String Reinitialize();

      int GetUniqueID();

      void SetServerStartedEvent();

      void OnPropertyChanged(boost::shared_ptr<Property> pProperty);

   protected:

      virtual bool OnDatabaseConnected(String &sErrorMessage);

   private:

      void _RegisterSessionTypes();
      void _CreateScheduledTasks();

      String m_sProdName;
      String m_sVersion;
      String m_sStartTime;
      
      String m_sLastConnectErrorMessage;

      boost::shared_ptr<DatabaseConnectionManager> m_pDBManager;
   
      // the servers
      boost::shared_ptr<SMTPDeliveryManager> m_pSMTPDeliveryManager;

      boost::shared_ptr<ExternalFetchManager> m_pExternalFetchManager;
      boost::shared_ptr<BackupManager> m_pBackupManager;
      boost::shared_ptr<Scheduler> m_pScheduler;
      boost::shared_ptr<NotificationServer> m_pNotificationServer;
      boost::shared_ptr<IOCPServer> m_pIOCPServer;
      boost::shared_ptr<FolderManager> _folderManager;

      const String m_sRandomWorkQueue;
      // The random work queue can run any type of task.

      const String m_sServerWorkQueue;
      // The main server queue, that contains one task per server.

      const String m_sAsynchronousTasksQueue;

      long m_iUniqueID;

      Event _serverStartEvent;
   };
}

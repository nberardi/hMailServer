// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "../SQL/DatabaseSettings.h"

namespace HM
{
   class IniFileSettings : public Singleton<IniFileSettings>
   {
   public:

	   IniFileSettings();
	   virtual ~IniFileSettings();

      void LoadSettings();

      bool CheckSettings(String &sErrorMessage);

      static String GetInitializationFile();

      bool GetDatabaseSettingsExists();

      String GetDatabaseServer() const { return m_DatabaseServer; }
      String GetDatabaseName() const { return m_DatabaseName; }
      String GetUsername() const { return m_Username; }
      String GetPassword() const { return m_Password; }
      DatabaseSettings::SQLDBType GetDatabaseType() const { return m_eSQLDBType; }
      long GetDatabasePort() const { return m_lDBPort;}
      bool GetIsInternalDatabase() const {return m_bIsInternalDatabase; }

      void SetDatabaseServer(const String &sNewValue);
      void SetDatabaseName(const String &sNewValue);
      void SetUsername(const String &sNewValue);
      void SetPassword(const String &sNewValue);
      void SetDatabaseType(DatabaseSettings::SQLDBType type);
      void SetDatabasePort(long lNewValue);
      void SetIsInternalDatabase(bool newValue);
      
      void SetAdministratorPassword(const String &sNewPassword);
      String GetAdministratorPassword();
      static String GetLogDirectory();

      String GetProgramDirectory() const { return m_AppDirectory; }
      String GetDataDirectory() const { return m_DataDirectory; }
      String GetTempDirectory() const { return m_sTempDirectory; }
      String GetEventDirectory() const { return m_sEventDirectory; }
      String GetDBScriptDirectory() const { return m_sDBScriptDirectory; }
      String GetDatabaseDirectory() const { return m_sDatabaseDirectory; }
      String GetLanguageDirectory() const;
      String GetCertificateAuthorityDirectory() const;
      String GetDatabaseServerFailoverPartner() const { return m_DatabaseServerFailoverPartner; }

      void SetProgramDirectory(const String &sNewVal);
      void SetDataDirectory(const String &sNewVal);
      void SetTempDirectory(const String &sNewVal);
      void SetEventDirectory(const String &sNewVal);
      void SetDatabaseDirectory(const String &sNewVal);
      void SetLogDirectory(const String &sLogDirectory);

      
      std::vector<String> GetValidLanguages() const {return m_vecValidLanguages; }

      String GetUserInterfaceLanguage();
      void SetUserInterfaceLanguage(String sLanguage);

      int GetNumberOfDatabaseConnections() const;
      int GetNumberOfDatabaseConnectionAttempts() const;
      int GetDBConnectionAttemptsDelay() const;
      
      bool GetAddXAuthUserHeader() {return m_bAddXAuthUserHeader; }
      int GetMaxNumberOfExternalFetchThreads() {return m_iMaxNoOfExternalFetchThreads ;}
      bool GetGreylistingEnabledDuringRecordExpiration() {return m_bGreylistingEnabledDuringRecordExpiration;}
      int GetGreylistingExpirationInterval() {return m_iGreylistingExpirationInterval; }
      int GetPreferredHashAlgorithm() {return _preferredHashAlgorithm;}
      bool GetDNSBLChecksAfterMailFrom() {return m_bDNSBlChecksAfterMailFrom; }
      
      bool GetUseSSLVerifyPeer() {return _useSSLVerifyPeer;}
      

   private:   

      void _WriteIniSetting(const String &sSection, const String &sKey, const String &sValue);
      void _WriteIniSetting(const String &sSection, const String &sKey, int Value);
      String _ReadIniSettingString(const String &sSection, const String &sKey, const String &sDefault);
      int _ReadIniSettingInteger(const String &sSection, const String &sKey, int iDefault);

      String m_DatabaseServer;
      String m_DatabaseName;
      String m_Username;
      String m_Password;
      String m_DataDirectory;
      String m_AppDirectory;
      String m_LogsDirectory;
      String m_sTempDirectory;
      String m_sEventDirectory;
      String m_sDBScriptDirectory;
      String m_sDatabaseDirectory;
      String m_DatabaseServerFailoverPartner;
      String m_AdministratorPassword;

      std::vector<String> m_vecValidLanguages;

      DatabaseSettings::SQLDBType m_eSQLDBType;
      long m_lDBPort;

      int m_iNoOfDBConnections;
      int m_iNoOfDBConnectionAttempts;
      int m_iNoOfDBConnectionAttemptsDelay;
      bool m_bAddXAuthUserHeader;
      int m_iMaxNoOfExternalFetchThreads;

      bool m_bGreylistingEnabledDuringRecordExpiration;
      bool m_bIsInternalDatabase;
      int m_iGreylistingExpirationInterval;
      
      int _preferredHashAlgorithm;

      static String m_sLogDirectory;
      static String m_sIniFile;

      bool m_bDNSBlChecksAfterMailFrom;
      bool _useSSLVerifyPeer;

   };
}

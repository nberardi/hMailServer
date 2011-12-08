// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class SURBLServers;
   class GreyListingWhiteAddresses;
   class WhiteListAddresses;
   class DNSBlackLists;

   class AntiSpamConfiguration
   {
   public:

      bool Load();

	   AntiSpamConfiguration();
	   virtual ~AntiSpamConfiguration();

      int GetSpamThreshold();

      bool GetCheckHostInHelo();
      void SetCheckHostInHelo(bool bNewVal);

      int GetCheckHostInHeloScore();
      void SetCheckHostInHeloScore(int bNewVal);

      bool GetUseGreyListing();
      void SetUseGreyListing(bool bNewVal);

      bool GetGreylistingTemporarilyDisabled();
      void SetGreylistingTemporarilyDisabled(bool bNewVal);

      int GetGreyListingInitialDelay();
      void SetGreyListingInitialDelay(int iNewVal);

      int GetGreyListingInitialDelete();
      void SetGreyListingInitialDelete(int iNewVal);

      int GetGreyListingFinalDelete();
      void SetGreyListingFinalDelete(int iNewVal);

      bool GetAddHeaderSpam();
      void SetAddHeaderSpam(bool bNewVal);

      bool GetAddHeaderReason();
      void SetAddHeaderReason(bool bNewVal);

      bool GetPrependSubject();
      void SetPrependSubject(bool bNewVal);

      String GetPrependSubjectText();
      void SetPrependSubjectText(const String &sText);

      bool GetUseMXChecks();
      void SetUseMXChecks(bool bNewVal);

      int GetUseMXChecksScore();
      void SetUseMXChecksScore(int bNewVal);

      bool GetUseSPF();
      void SetUseSPF(bool bNewVal);

      int GetUseSPFScore();
      void SetUseSPFScore(int bNewVal);


      int GetSpamMarkThreshold();
      void SetSpamMarkThreshold(int bNewVal);

      int GetSpamDeleteThreshold();
      void SetSpamDeleteThreshold(int bNewVal);

      bool GetSpamAssassinEnabled();
      void SetSpamAssassinEnabled(bool bNewVal);

      int GetSpamAssassinScore();
      void SetSpamAssassinScore(int bNewVal);

      bool GetSpamAssassinMergeScore();
      void SetSpamAssassinMergeScore(bool bNewVal);

      String GetSpamAssassinHost();
      void SetSpamAssassinHost(const String &sNewVal);

      int GetSpamAssassinPort();
      void SetSpamAssassinPort(int bNewVal);

      int GetAntiSpamMaxSizeKB();
      void SetAntiSpamMaxSizeKB(int newVal);

      bool GetDKIMVerificationEnabled();
      void SetDKIMVerificationEnabled(bool newValue);

      int GetDKIMVerificationFailureScore();
      void SetDKIMVerificationFailureScore(int newValue);

      bool GetBypassGreyListingOnSPFSuccess();
      void SetBypassGreyListingOnSPFSuccess(bool newValue);

      bool GetBypassGreyListingOnMailFromMX();
      void SetBypassGreyListingOnMailFromMX(bool newValue);

      void ClearGreyListingTriplets();

      bool XMLStore(XNode *pBackupNode, int Options);
      bool XMLLoad(XNode *pBackupNode, int iRestoreOptions);

      boost::shared_ptr<GreyListingWhiteAddresses> GetGreyListingWhiteAddresses();
      boost::shared_ptr<WhiteListAddresses> GetWhiteListAddresses();
      boost::shared_ptr<DNSBlackLists> GetDNSBlackLists() {return _dnsBlackLists;}
      boost::shared_ptr<SURBLServers> GetSURBLServers() {return _surblServers;}

   private:
      
      boost::shared_ptr<PropertySet> _GetSettings();

      bool m_bGreylistingTemporarilyDisabled;

      boost::shared_ptr<DNSBlackLists> _dnsBlackLists;
      boost::shared_ptr<SURBLServers> _surblServers;

   };
}

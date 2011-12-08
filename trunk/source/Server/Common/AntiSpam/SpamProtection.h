// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;
   class MessageData;

   class SpamTestRunner;
   class SpamTestResult;

   class SpamProtection : public Singleton<SpamProtection>
   {
   public:
      SpamProtection(void);
      ~SpamProtection(void);

      void Load();

      set<boost::shared_ptr<SpamTestResult> > RunPreTransmissionTests(const String &sFromAddress, const IPAddress & iOriginatingIP, const IPAddress &iConnectingIP, const String &sHeloHost);
      set<boost::shared_ptr<SpamTestResult> > RunPostTransmissionTests(const String &sFromAddress, const IPAddress & iOriginatingIP, const IPAddress &iConnectingIP, boost::shared_ptr<Message> pMessage);

      static boost::shared_ptr<MessageData> TagMessageAsSpam(boost::shared_ptr<Message> pMessage, set<boost::shared_ptr<SpamTestResult> > setResult);
      static bool GreyListingAllowSend(const String &sSenderAddress, const String &sRecipientAddress, const IPAddress & iRemoteIP);

      static int CalculateTotalSpamScore(set<boost::shared_ptr<SpamTestResult> > result);

      static bool IsWhiteListed(const String &sFromAddress, const IPAddress & iIPAddress);

      bool PerformGreyListing(boost::shared_ptr<Message> message, const set<boost::shared_ptr<SpamTestResult> > &spamTestResults, const String &toAddress, const IPAddress &ipaddress);
   private:
      
      
      boost::shared_ptr<SpamTestRunner> m_pSpamTestRunner;
      
   };

}
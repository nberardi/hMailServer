// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;

   class AWStats
   {
   public:
      AWStats(void);
      ~AWStats(void);

      static void LogDeliveryFailure(const String &sSendersIP, const String &sFromAddress, const String &sToAddress, int iErrorCode);
      static void LogDeliverySuccess(const String &sSendersIP, shared_ptr<Message> pMessage, const String &sRecipient);

      static void SetEnabled(bool bNewVal);
      static bool GetEnabled();

   private:

      static void _Log(const String &sSender, const String &sRecipient, const String &sRemoteHost, int iErrorCode, int iBytesReceived);

      static bool m_bEnabled;
   };
}
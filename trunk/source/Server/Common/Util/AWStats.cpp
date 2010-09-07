// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include ".\awstats.h"
#include "Time.h"
#include "../BO/Message.h"
#include "../BO/MessageRecipients.h"
#include "../BO/MessageRecipient.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   bool AWStats::m_bEnabled = false;

   AWStats::AWStats(void)
   {
   }

   AWStats::~AWStats(void)
   {
   }

   void 
   AWStats::LogDeliveryFailure(const String &sSendersIP, const String &sFromAddress, const String &sToAddress, int iErrorCode)
   {
      if (!m_bEnabled)
         return;

      LOG_DEBUG(_T("AWStats::LogDeliveryFailure"));

      _Log(sFromAddress, sToAddress, sSendersIP, iErrorCode, 0);
   }


   void
   AWStats::LogDeliverySuccess(const String &sSendersIP, shared_ptr<Message> pMessage, const String &sRecipient)
   {
      if (!m_bEnabled)
         return;

      LOG_DEBUG(_T("AWStats::LogDeliverySuccess"));

      _Log(pMessage->GetFromAddress(), sRecipient, sSendersIP, 250, pMessage->GetSize());
   }

   void 
   AWStats::_Log(const String &sSender, const String &sRecipient, const String &sRemoteHost, int iErrorCode, int iBytesReceived)
   {
      if (!m_bEnabled)
         return;

      // Following format is used:
      // %time2 %email %email_r %host %host_r %method %url %code %bytesd"
      
      String sTime = Time::GetCurrentDateTime();

      String sModifiedSender = sSender;
      sModifiedSender.Replace(_T("<"), _T(""));
      sModifiedSender.Replace(_T(">"), _T(""));
      sModifiedSender.Replace(_T(" "), _T(""));
      sModifiedSender.Replace(_T("\t"), _T(""));

      String sModifiedRecipient = sRecipient;
      sModifiedRecipient.Replace(_T("<"), _T(""));
      sModifiedRecipient.Replace(_T(">"), _T(""));
      sModifiedRecipient.Replace(_T(" "), _T(""));
      sModifiedRecipient.Replace(_T("\t"), _T(""));

      String sLogLine;
      sLogLine.Format(_T("%s\t%s\t%s\t%s\t%s\tSMTP\t?\t%d\t%d\r\n"), 
                        sTime, sModifiedSender, sModifiedRecipient, sRemoteHost, _T("127.0.0.1"), iErrorCode, iBytesReceived );

      Logger::Instance()->LogAWStats(sLogLine);
   }

   void 
   AWStats::SetEnabled(bool bNewVal)
   {
      m_bEnabled = bNewVal;
   }

   bool 
   AWStats::GetEnabled()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Returns true if the awstats log is enabled. false otherwise.
   //---------------------------------------------------------------------------()
   {
      return m_bEnabled;
   }
}
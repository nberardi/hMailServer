// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include ".\surbl.h"

#include "../../Common/BO/MessageData.h"
#include "../../Common/BO/SURBLServer.h"
#include "../../Common/TCPIP/DNSResolver.h"
#include "../../Common/Util/FileUtilities.h"

#include "../../Common/Util/TLD.h"
#include "../../Common/Util/Stopwatch.h"


#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   SURBL::SURBL(void)
   {
      
   }

   SURBL::~SURBL(void)
   {
   }

   

   bool 
   SURBL::Run(shared_ptr<SURBLServer> pSURBLServer, shared_ptr<MessageData> pMessageData)
   {
      Stopwatch stopWatch(true);
      LOG_DEBUG("SURBL::Run");

      // Extract body
      String sBody = pMessageData->GetBody() + pMessageData->GetHTMLBody(); 

      int iCurPos = -1;

      // We stop processing URL's if:
      // - 15 or more URLss have been processed.
      // - More than 10 seconds have passed.
      //
	  // NEED FOR FIX NOTE: URL's are reduced down & we end up with many duplicates so the list should
	  // be consolidated before checking or wasteful & likely miss later unique URL's after 15 limit
	  // ACTUAL EXAMPLE:
	  // "DEBUG"	3288	"2011-10-21 07:15:21.281"	"SURBL:: Found URL: www.e-rewards.com"
	  // "DEBUG"	3288	"2011-10-21 07:15:21.281"	"SURBL:: Lookup: e-rewards.com.multi.surbl.org"
	  // "DEBUG"	3288	"2011-10-21 07:15:21.296"	"SURBL:: Found URL: www.e-rewards.com"
	  // "DEBUG"	3288	"2011-10-21 07:15:21.296"	"SURBL:: Lookup: e-rewards.com.multi.surbl.org"
      // There were 15 of those for the same lookup and URL's later in email were skipped & never checked.

	  // NEED FOR IMPROVEMENT: max URL's & time should be user-adjustable even if just by INI

	  const int maxURLsToProcess = 15;

      for (int i = 0; i < maxURLsToProcess; i++)
      {
         if (stopWatch.GetElapsedSeconds() > 10)
         {
            LOG_DEBUG("Aborting SURBL processing. Too long time elapsed.");
            return true;
         }

         iCurPos = _GetURLStart(sBody, iCurPos);

         if (iCurPos < 0 )
            break;

         // Start of URL
         int iURLEnd = _GetURLEndPos(sBody, iCurPos);
         int iURLLength = iURLEnd - iCurPos ;

         String sURL = sBody.Mid(iCurPos, iURLLength);

         String logMessage;
         logMessage.Format(_T("SURBL:: Found URL: %s"), sURL);
         LOG_DEBUG(logMessage);


         // Clean the URL from linefeeds
         _CleanURL(sURL);

         // Trim away top domain
         if (!_CleanHost(sURL))
            continue;

         String sHostToLookup = sURL + "." + pSURBLServer->GetDNSHost();

         logMessage.Format(_T("SURBL:: Lookup: %s"), sHostToLookup);
         LOG_DEBUG(logMessage);

         std::vector<String> saFoundNames;
         DNSResolver resolver;
         if (!resolver.GetARecords(sHostToLookup, saFoundNames))
         {
            LOG_DEBUG("SURBL::~Run");
            return true;
         }

         if (saFoundNames.size() > 0)
         {
            // Found
            LOG_DEBUG("SURBL::~Run");
            return false;
         }
      }

      LOG_DEBUG("SURBL::~Run");
      return true;

   }

   int 
   SURBL::_GetURLEndPos(const String &sBody, int iURLStart)
   {
      for (int i = iURLStart; i < sBody.GetLength(); i++)
      {
         // Space added as fix to no test on plain-text emails without end slash
         // cr and lf added as well for same reason
         // Might be best to look for 1st non-allowed domain char instead..
         wchar_t c = sBody.GetAt(i);
         if (c == '<' || 
             c == '/' || 
             c == '\\' || 
             c == '>' ||
             c == ' ' ||
             c == '\r' ||
             c == '\n' ||
             c == '"')
             return i;
      }

      return -1;
   }

   int 
   SURBL::_GetURLStart(const String &sBody, int iCurrentPos)
   {
      int iHTTPStart = sBody.Find(_T("http://"), iCurrentPos+1);
      int iHTTPSStart = sBody.Find(_T("https://"), iCurrentPos+1);

      if (iHTTPStart == -1)
      {
         if (iHTTPSStart == -1)
            return -1;

         return iHTTPSStart + 8;
      }

      if (iHTTPSStart == -1)
      {
         if (iHTTPStart == -1 )
            return -1;

         return iHTTPStart + 7;
      }

      if (iHTTPStart < iHTTPSStart)
         return iHTTPStart + 7;
      else
         return iHTTPStart + 8;
   }

   void
   SURBL::_CleanURL(String &url) const
   {
      url.Replace(_T("=\r\n"), _T(""));
      // We need to replace them individually as well just in case..
      url.Replace(_T("=\r"), _T(""));
      url.Replace(_T("=\n"), _T(""));
   }

   bool
   SURBL::_CleanHost(String &sDomain) const
   {
      bool bIsIPAddress = false;
      return TLD::Instance()->GetDomainNameFromHost(sDomain, bIsIPAddress);

   }
}
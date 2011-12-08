// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class MessageData;
   class SURBLServer;

   class SURBL
   {
   public:
      SURBL(void);
      ~SURBL(void);

      bool Run(boost::shared_ptr<SURBLServer> pSURBLServer, boost::shared_ptr<MessageData> pMessageData);

   private:

      void _CleanURL(String &sURL) const;
      bool _CleanHost(String &sDomain) const;
      int _GetURLStart(const String &sBody, int iCurrentPos);
      int _GetURLEndPos(const String &sBody, int iURLStart);

      
   };
}
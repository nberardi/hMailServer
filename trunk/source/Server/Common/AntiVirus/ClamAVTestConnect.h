// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

using boost::asio::ip::tcp;

namespace HM
{
   class ClamAVTestConnect
   {
   public:
      bool TestConnect(const String &hostName, int port, String &message);

   };

}
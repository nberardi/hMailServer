// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

using boost::asio::ip::tcp;

namespace HM
{
   class ClamAVVirusScanner
   {
   public:
      ClamAVVirusScanner(void);
      ~ClamAVVirusScanner(void);

      static bool Scan(const String &sFilename, String &virusName);

   private:

      static void _Connect(boost::asio::io_service &io_service, const String &hostName, int port, tcp::socket &socket);
   };

}
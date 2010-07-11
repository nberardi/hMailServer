// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com


#pragma once

namespace HM
{
   class ClientInfo  
   {
   public:
	   ClientInfo();
	   virtual ~ClientInfo();

      void SetIPAddress(const String &IP) { IPAddress = IP; }
      String GetIPAddress() const { return IPAddress; }

      void SetUsername(const String &sUsernme) { m_sUsername = sUsernme; }
      String GetUsername() const { return m_sUsername; }

      long GetPort() const {return m_lPort; }
      void SetPort(long lNewVal) {m_lPort = lNewVal; }

   private:

      String IPAddress;
      long m_lPort;
      String m_sUsername;
   };
}

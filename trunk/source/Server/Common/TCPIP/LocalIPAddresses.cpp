// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "LocalIPAddresses.h"
#include "../BO/TCPIPPorts.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{

   LocalIPAddresses::LocalIPAddresses()
   {
      
   }

   LocalIPAddresses::~LocalIPAddresses()
   {

   }

   void
   LocalIPAddresses::LoadIPAddresses()
   {
      m_vecLocalPorts.clear();

      std::vector<IPAddress> localAddresses;

      char name[255];

      if( gethostname ( name, sizeof(name)) == 0)
      {
         PHOSTENT hostinfo;
         if((hostinfo = gethostbyname(name)) != NULL)
         {
            int nCount = 0;
            while(hostinfo->h_addr_list[nCount])
            {
               char *ip = inet_ntoa(*(struct in_addr *)hostinfo->h_addr_list[nCount]);
               
               IPAddress address;

               if (address.TryParse(ip))
                  localAddresses.push_back(address);

               nCount++;
            }
         }
      }

      boost::shared_ptr<TCPIPPorts> pTCPIPPorts = Configuration::Instance()->GetTCPIPPorts();

      const vector<boost::shared_ptr<TCPIPPort> > vecTCPIPPorts = pTCPIPPorts->GetVector();

      vector<boost::shared_ptr<TCPIPPort> >::const_iterator iter = vecTCPIPPorts.begin();
      vector<boost::shared_ptr<TCPIPPort> >::const_iterator iterEnd = vecTCPIPPorts.end();
      for (; iter != iterEnd; iter++)
      {
         boost::shared_ptr<TCPIPPort> pTCPIPPort = (*iter);

         if (pTCPIPPort->GetAddress().IsAny())
         {
            int portNumber = pTCPIPPort->GetPortNumber();
            std::vector<IPAddress>::iterator iter = localAddresses.begin(); 
            std::vector<IPAddress>::iterator iterEnd = localAddresses.end();

            for (; iter != iterEnd; iter++)
            {
               IPAddress address = (*iter);

               m_vecLocalPorts.push_back(std::make_pair(address, portNumber));

               m_vecLocalPorts.push_back(std::make_pair(IPAddress(), portNumber));
            }
         }
         else
         {
            m_vecLocalPorts.push_back(std::make_pair(pTCPIPPort->GetAddress(), pTCPIPPort->GetPortNumber()));
         }
      }

      
   }

   bool 
   LocalIPAddresses::IsLocalIPAddress(const IPAddress &address)
   {
      std::vector<std::pair<IPAddress, int> >::iterator iter = m_vecLocalPorts.begin();
      std::vector<std::pair<IPAddress, int> >::iterator iterEnd = m_vecLocalPorts.end();

      for (; iter != iterEnd; iter++)
      {
         IPAddress usedAddress = (*iter).first;

         if (usedAddress == address)
            return true;
      }

      return false;
   }

   bool 
   LocalIPAddresses::IsLocalPort(const IPAddress &address, int port)
   {
      std::vector<std::pair<IPAddress, int> >::iterator iter = m_vecLocalPorts.begin();
      std::vector<std::pair<IPAddress, int> >::iterator iterEnd = m_vecLocalPorts.end();

      bool loopbackAddress = IsWithinLoopbackRange(address);

      for (; iter != iterEnd; iter++)
      {
         IPAddress usedAddress = (*iter).first;
         unsigned long usedPort = (*iter).second;
       
         if (loopbackAddress)
         {
            if (usedAddress.IsAny() && usedPort == port)
               return true;
         }
         else
         {
            if (usedAddress == address && usedPort == port)
               return true;
         }

      }

      return false;
   }
   
   bool
   LocalIPAddresses::IsWithinLoopbackRange(const IPAddress &address)
   {
      if (address.GetType() == IPAddress::IPV4)
      {
         unsigned __int64 longAddress = address.GetAddress1();
      
         // 127.0.0.1 - 127.255.255.255
         if (longAddress >= 2130706433 && longAddress <= 2147483647)
            return true;
         else
            return false;
      }
      else if (address.GetType() == IPAddress::IPV6)
      {
         if (address.GetAddress1() == 0 && address.GetAddress2() == 1)
            return true;
         else
            return false;
      }

      return true;
      

      /*

         */
   }

   // TESTER
   void LocalIPAddressesTester::Test()
   {
      
   }

}

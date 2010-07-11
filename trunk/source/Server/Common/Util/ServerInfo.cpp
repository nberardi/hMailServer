// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "ServerInfo.h"

namespace HM
{
   ServerInfo::ServerInfo(bool fixed, const String &hostName, int port, const String&userName, const String &passWord, bool useSSL) :
      _fixed (fixed),
      _hostName(hostName),
      _port(port),
      _userName(userName),
      _passWord(passWord),
      _useSSL(useSSL)
   {

   }

   ServerInfo::~ServerInfo()
   {

   }

   bool
   ServerInfo::GetFixed()
   {
      return _fixed;
   }

   String 
   ServerInfo::GetHostName()
   {
      return _hostName;
   }

   void 
   ServerInfo::SetHostName(const String &hostName)
   {
      _hostName = hostName;
   }

   int 
   ServerInfo::GetPort()
   {
      return _port;
   }

   String 
   ServerInfo::GetUsername()
   {
      return _userName;
   }

   String 
   ServerInfo::GetPassword()
   {
      return _passWord;
   }

   bool 
   ServerInfo::GetUseSSL()
   {
      return _useSSL;
   }
}

// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include "ServerMessage.h"

namespace HM
{
   ServerMessage::ServerMessage(void)
   {

   }

   ServerMessage::~ServerMessage(void)
   {
   }

   bool 
   ServerMessage::XMLStore(XNode *pParentNode)
   {

      return true;
   }

   bool 
   ServerMessage::XMLLoad(XNode *pNode)
   {

      return true;
   }
}
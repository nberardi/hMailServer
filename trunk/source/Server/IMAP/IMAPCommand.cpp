// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "IMAPCommand.h"
#include "IMAPConnection.h"
#include "../Common/BO/IMAPFolder.h"
#include "../Common/Persistence/PersistentMessage.h"

namespace HM
{
   IMAPCommand::IMAPCommand()
   {

   }

   IMAPCommand::~IMAPCommand()
   {

   }

   String
   IMAPCommandArgument::Literal(unsigned int Index)
   {
      if (Index >= m_vecLiterals.size())
         return "";
      else 
         return m_vecLiterals[Index];
   }

}

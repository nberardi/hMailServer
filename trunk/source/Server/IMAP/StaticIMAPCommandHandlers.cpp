// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "StaticIMAPCommandHandlers.h"

#include "IMAPCommandAuthenticate.h"
#include "IMAPCommandLogin.h"
#include "IMAPCommandCheck.h"
#include "IMAPCommandSelect.h"
#include "IMAPCommandClose.h"
#include "IMAPCommandCreate.h"
#include "IMAPCommandDelete.h"
#include "IMAPCommandExamine.h"
#include "IMAPCommandExpunge.h"
#include "IMAPCommandSubscribe.h"
#include "IMAPCommandUnsubscribe.h"
#include "IMAPCommandStatus.h"
#include "IMAPCommandRename.h"
#include "IMAPCommandList.h"
#include "IMAPCommandLsub.h"
#include "IMAPCommandCopy.h"
#include "IMAPCommandFetch.h"
#include "IMAPCommandCapability.h"
#include "IMAPCommandStore.h"
#include "IMAPCommandLogout.h"
#include "IMAPCommandNamespace.h"
#include "IMAPCommandMyRights.h"
#include "IMAPCommandGetAcl.h"
#include "IMAPCommandDeleteAcl.h"
#include "IMAPCommandSetAcl.h"
#include "IMAPCommandListRights.h"


// IMAP QUOTA EXTENSION
#include "IMAPCommandGetQuota.h"
#include "IMAPCommandGetQuotaRoot.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   std::map<IMAPConnection::eIMAPCommandType, boost::shared_ptr<IMAPCommand> > StaticIMAPCommandHandlers::mapCommandHandlers;

   StaticIMAPCommandHandlers::StaticIMAPCommandHandlers()
   {

   }

   StaticIMAPCommandHandlers::~StaticIMAPCommandHandlers()
   {

   }

   void
   StaticIMAPCommandHandlers::Init()
   {
      mapCommandHandlers[IMAPConnection::IMAP_LOGIN] = boost::shared_ptr<IMAPCommandLOGIN>(new IMAPCommandLOGIN());
      mapCommandHandlers[IMAPConnection::IMAP_CHECK] = boost::shared_ptr<IMAPCommandCHECK>(new IMAPCommandCHECK());
      mapCommandHandlers[IMAPConnection::IMAP_SELECT] = boost::shared_ptr<IMAPCommandSELECT>(new IMAPCommandSELECT());
      mapCommandHandlers[IMAPConnection::IMAP_CLOSE] = boost::shared_ptr<IMAPCommandCLOSE>(new IMAPCommandCLOSE());
      mapCommandHandlers[IMAPConnection::IMAP_CREATE] = boost::shared_ptr<IMAPCommandCREATE>(new IMAPCommandCREATE());
      mapCommandHandlers[IMAPConnection::IMAP_DELETE] = boost::shared_ptr<IMAPCommandDELETE>(new IMAPCommandDELETE());
      mapCommandHandlers[IMAPConnection::IMAP_EXAMINE] = boost::shared_ptr<IMAPCommandEXAMINE>(new IMAPCommandEXAMINE());
      mapCommandHandlers[IMAPConnection::IMAP_EXPUNGE] = boost::shared_ptr<IMAPCommandEXPUNGE>(new IMAPCommandEXPUNGE());
      mapCommandHandlers[IMAPConnection::IMAP_UNSUBSCRIBE] = boost::shared_ptr<IMAPCommandUNSUBSCRIBE>(new IMAPCommandUNSUBSCRIBE());
      mapCommandHandlers[IMAPConnection::IMAP_SUBSCRIBE] = boost::shared_ptr<IMAPCommandSUBSCRIBE>(new IMAPCommandSUBSCRIBE());
      mapCommandHandlers[IMAPConnection::IMAP_STATUS] = boost::shared_ptr<IMAPCommandSTATUS>(new IMAPCommandSTATUS());
      mapCommandHandlers[IMAPConnection::IMAP_RENAME] = boost::shared_ptr<IMAPCommandRENAME>(new IMAPCommandRENAME());
      mapCommandHandlers[IMAPConnection::IMAP_LIST] = boost::shared_ptr<IMAPCommandLIST>(new IMAPCommandLIST());
      mapCommandHandlers[IMAPConnection::IMAP_LSUB] = boost::shared_ptr<IMAPCommandLSUB>(new IMAPCommandLSUB());
      mapCommandHandlers[IMAPConnection::IMAP_COPY] = boost::shared_ptr<IMAPCommandCOPY>(new IMAPCommandCOPY());
      mapCommandHandlers[IMAPConnection::IMAP_FETCH] = boost::shared_ptr<IMAPCommandFETCH>(new IMAPCommandFETCH());
      mapCommandHandlers[IMAPConnection::IMAP_CAPABILITY] = boost::shared_ptr<IMAPCommandCapability>(new IMAPCommandCapability());
      mapCommandHandlers[IMAPConnection::IMAP_STORE] = boost::shared_ptr<IMAPCommandStore>(new IMAPCommandStore());
      mapCommandHandlers[IMAPConnection::IMAP_AUTHENTICATE] = boost::shared_ptr<IMAPCommandAUTHENTICATE>(new IMAPCommandAUTHENTICATE());
      mapCommandHandlers[IMAPConnection::IMAP_NOOP] = boost::shared_ptr<IMAPCommandNOOP>(new IMAPCommandNOOP());
      mapCommandHandlers[IMAPConnection::IMAP_LOGOUT] = boost::shared_ptr<IMAPCommandLOGOUT>(new IMAPCommandLOGOUT());
      mapCommandHandlers[IMAPConnection::IMAP_UNKNOWN] = boost::shared_ptr<IMAPCommandUNKNOWN>(new IMAPCommandUNKNOWN());
      mapCommandHandlers[IMAPConnection::IMAP_GETQUOTAROOT] = boost::shared_ptr<IMAPCommandGetQuotaRoot>(new IMAPCommandGetQuotaRoot());
      mapCommandHandlers[IMAPConnection::IMAP_GETQUOTA] = boost::shared_ptr<IMAPCommandGetQuota>(new IMAPCommandGetQuota());
      mapCommandHandlers[IMAPConnection::IMAP_NAMESPACE] = boost::shared_ptr<IMAPCommandNamespace>(new IMAPCommandNamespace());
      mapCommandHandlers[IMAPConnection::IMAP_MYRIGHTS] = boost::shared_ptr<IMAPCommandMyRights>(new IMAPCommandMyRights());
      mapCommandHandlers[IMAPConnection::IMAP_GETACL] = boost::shared_ptr<IMAPCommandGetAcl>(new IMAPCommandGetAcl());
      mapCommandHandlers[IMAPConnection::IMAP_DELETEACL] = boost::shared_ptr<IMAPCommandDeleteAcl>(new IMAPCommandDeleteAcl());
      mapCommandHandlers[IMAPConnection::IMAP_SETACL] = boost::shared_ptr<IMAPCommandSetAcl>(new IMAPCommandSetAcl());
      mapCommandHandlers[IMAPConnection::IMAP_LISTRIGHTS] = boost::shared_ptr<IMAPCommandListRights>(new IMAPCommandListRights());
      
   }

   void
   StaticIMAPCommandHandlers::DeInit()
   {
      mapCommandHandlers.clear();
   }

   // Tiny commands

   IMAPResult
   IMAPCommandUNKNOWN::ExecuteCommand(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument)
   {
      pConnection->SendResponseString(pArgument->Tag(), "BAD", "Unknown or NULL command");

      return IMAPResult();
   }

   IMAPResult
   IMAPCommandNOOP::ExecuteCommand(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument)
   {
      pConnection->SendAsciiData(pArgument->Tag() + " OK NOOP completed\r\n");   

      return IMAPResult();
   
   }

}

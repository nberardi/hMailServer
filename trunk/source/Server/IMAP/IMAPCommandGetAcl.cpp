// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "IMAPCommandGetAcl.h"
#include "IMAPConnection.h"
#include "IMAPSimpleCommandParser.h"
#include "IMAPACLHelper.h"
#include "IMAPConfiguration.h"


#include "../Common/Application/ACLManager.h"
#include "../Common/BO/Account.h"
#include "../Common/BO/IMAPFolders.h"
#include "../Common/BO/IMAPFolder.h"
#include "../Common/BO/ACLPermissions.h"
#include "../Common/BO/ACLPermission.h"
#include "../Common/Cache/CacheContainer.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{

   IMAPResult
   IMAPCommandGetAcl::ExecuteCommand(boost::shared_ptr<HM::IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument)
   {
      if (!pConnection->IsAuthenticated())
         return IMAPResult(IMAPResult::ResultNo, "Authenticate first");

      if (!Configuration::Instance()->GetIMAPConfiguration()->GetUseIMAPACL())
         return IMAPResult(IMAPResult::ResultBad, "ACL is not enabled.");

      boost::shared_ptr<IMAPSimpleCommandParser> pParser = boost::shared_ptr<IMAPSimpleCommandParser>(new IMAPSimpleCommandParser());
      pParser->Parse(pArgument);

      if (pParser->WordCount() != 2)
         return IMAPResult(IMAPResult::ResultBad, "MYRIGHTS command requires 1 parameter.");

      String sOriginalFolderName;
      String sFolderName;

      if (pParser->Word(1)->Clammerized())
      {
         sOriginalFolderName = pArgument->Literal(0);
         sOriginalFolderName = sFolderName;
      }
      else
      {
         sOriginalFolderName = pParser->Word(1)->Value();
         
         sFolderName = sOriginalFolderName;
         IMAPFolder::UnescapeFolderString(sFolderName);
      }
      
      boost::shared_ptr<IMAPFolder> pFolder = pConnection->GetFolderByFullPath(sFolderName);
      if (!pFolder)
         return IMAPResult(IMAPResult::ResultBad, "Folder could not be found.");

      String sResponse = IMAPACLHelper::CreateACLList(pFolder, sOriginalFolderName);
      sResponse += pArgument->Tag() + _T(" OK GetAcl complete\r\n");

      pConnection->SendAsciiData(sResponse);   

      return IMAPResult();
   }
}
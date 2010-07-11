// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "IMAPCommandClose.h"
#include "IMAPConnection.h"

#include "../Common/BO/ACLPermission.h"
#include "../Common/BO/IMAPFolder.h"
namespace HM
{
   IMAPResult
   IMAPCommandCLOSE::ExecuteCommand(shared_ptr<HM::IMAPConnection> pConnection, shared_ptr<IMAPCommandArgument> pArgument)
   {
      if (!pConnection->IsAuthenticated())
         return IMAPResult(IMAPResult::ResultNo, "Authenticate first");
      
      // Iterate through mail boxes and delete messages marked for deletion.
      shared_ptr<IMAPFolder> pCurFolder = pConnection->GetCurrentFolder();   

      if (!pCurFolder)
         return IMAPResult(IMAPResult::ResultBad, "No folder selected.");

      // Check if user has permission to expunge. If so, do that.
      if (!pConnection->GetCurrentFolderReadOnly() &&
          pConnection->CheckPermission(pConnection->GetCurrentFolder(), ACLPermission::PermissionExpunge))
      {
         pCurFolder->Expunge();
      }
      
      pConnection->CloseCurrentFolder();

      String sResponse = pArgument->Tag() + " OK CLOSE completed\r\n";
      pConnection->SendAsciiData(sResponse);  

      return IMAPResult();

   }
}
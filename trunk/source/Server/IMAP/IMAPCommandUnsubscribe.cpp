// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "IMAPCommandUnsubscribe.h"
#include "IMAPConnection.h"
#include "IMAPSimpleCommandParser.h"
#include "../Common/BO/IMAPFolders.h"
#include "../Common/Persistence/PersistentIMAPFolder.h"
#include "../Common/BO/IMAPFolder.h"

namespace HM
{
   IMAPResult
   IMAPCommandUNSUBSCRIBE::ExecuteCommand(shared_ptr<HM::IMAPConnection> pConnection, shared_ptr<IMAPCommandArgument> pArgument)
   {
      if (!pConnection->IsAuthenticated())
         return IMAPResult(IMAPResult::ResultNo, "Authenticate first");

      // Parse the command
      shared_ptr<IMAPSimpleCommandParser> pParser = shared_ptr<IMAPSimpleCommandParser>(new IMAPSimpleCommandParser());

      pParser->Parse(pArgument);
      if (pParser->ParamCount() != 1)
         return IMAPResult(IMAPResult::ResultBad, "Command requires 1 parameter.");

      // Fetch the folder name. 
      String sFolderName = pParser->GetParamValue(pArgument, 0);

      shared_ptr<IMAPFolder> pFolder = pConnection->GetFolderByFullPath(sFolderName);

      IMAPResult result = ConfirmPossibleToUnsubscribe(pFolder);
      if (result.GetResult() != IMAPResult::ResultOK)
         return result;

      if (pFolder)
      {
         pFolder->SetIsSubscribed(false);
         PersistentIMAPFolder::SaveObject(pFolder);
      }
         
      String sResponse = pArgument->Tag() + " OK Unsubscribe completed\r\n";
      pConnection->SendAsciiData(sResponse);   

      return IMAPResult();
   }

   IMAPResult
   IMAPCommandUNSUBSCRIBE::ConfirmPossibleToUnsubscribe(shared_ptr<IMAPFolder> pFolder)
   {
      if (!pFolder)
         return IMAPResult(IMAPResult::ResultNo, "That mailbox does not exist.");

      if (pFolder->GetAccountID() == 0)
         return IMAPResult(IMAPResult::ResultNo, "It is not possible to unsubscribe from public folders.");

      return IMAPResult();
   }
}
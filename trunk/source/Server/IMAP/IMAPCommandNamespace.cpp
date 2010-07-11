// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "IMAPCommandNamespace.h"
#include "IMAPConnection.h"
#include "IMAPSimpleCommandParser.h"

#include "IMAPConfiguration.h"

namespace HM
{
   IMAPResult
   IMAPCommandNamespace::ExecuteCommand(shared_ptr<HM::IMAPConnection> pConnection, shared_ptr<IMAPCommandArgument> pArgument)
   {
      if (!pConnection->IsAuthenticated())
         return IMAPResult(IMAPResult::ResultNo, "Authenticate first");

      shared_ptr<IMAPSimpleCommandParser> pParser = shared_ptr<IMAPSimpleCommandParser>(new IMAPSimpleCommandParser());
      pParser->Parse(pArgument);

      if (pParser->WordCount() < 1)
         return IMAPResult(IMAPResult::ResultBad, "NAMESPACE command requires exactly 0 parameter.");

      String sPublicFolderName = Configuration::Instance()->GetIMAPConfiguration()->GetIMAPPublicFolderName();
      String hierarchyDelimiter = Configuration::Instance()->GetIMAPConfiguration()->GetHierarchyDelimiter();
      hierarchyDelimiter.Replace(_T("\\"), _T("\\\\"));

      String sPersonalNamespace = "((\"\" \"" + hierarchyDelimiter + "\"))";
      String sOtherUsersNamespace = "NIL";
      String sSharedNamespaces = "((\"" + sPublicFolderName + "\" \"" + hierarchyDelimiter + "\"))";
      String sResponse;
      
      sResponse.Format(_T("* NAMESPACE %s %s %s\r\n"), sPersonalNamespace, sOtherUsersNamespace, sSharedNamespaces);
      sResponse += pArgument->Tag() + _T(" OK namespace command complete\r\n");

      pConnection->SendAsciiData(sResponse);   

      return IMAPResult();
   }
}
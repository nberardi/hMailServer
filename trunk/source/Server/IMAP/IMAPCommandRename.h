// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once


#include "IMAPCommand.h"

namespace HM
{
   class IMAPFolder;

   class IMAPCommandRENAME : public IMAPCommand
   {
      virtual IMAPResult ExecuteCommand(boost::shared_ptr<HM::IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument);

   private:
      
      IMAPResult ConfirmPossibleToRename(boost::shared_ptr<HM::IMAPConnection> pConnection, boost::shared_ptr<IMAPFolder> pFolderToRename, const std::vector<String> &vecOldPath, const std::vector<String> &vecNewPath);

      boost::shared_ptr<IMAPFolder> GetParentFolder(boost::shared_ptr<HM::IMAPConnection> pConnection, const std::vector<String> &vecFolderPath);
   };

}


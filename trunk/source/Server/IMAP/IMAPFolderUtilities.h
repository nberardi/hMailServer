// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class IMAPFolders;
   class IMAPFolder;

   class IMAPFolderUtilities
   {
   private:
	   IMAPFolderUtilities();
	   virtual ~IMAPFolderUtilities();

   public:

      static bool IsPublicFolder(const std::vector<String> &vecFolderPath);

      static boost::shared_ptr<IMAPFolder> GetTopMostExistingFolder(boost::shared_ptr<IMAPFolders> pContainer, const std::vector<String> &vecFolderPath);
   };
}

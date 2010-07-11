// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once
#include "ZZip.h"
#include "ZUnZip.h"

namespace HM
{
   class Compression
   {
   public:
      Compression(String sResultFile, String sBaseDir, bool bCompress);
      ~Compression(void);

      bool AddDirectory(String sDirectory);
      bool AddFile(String sFile);
      bool Close();

      bool Uncompress();
      bool UncompressFile(const String &sFilename);

   private:

      String m_sResultFile;
      String m_sBaseDir;

      HZIP m_hZip;

      bool _open;
   };
}
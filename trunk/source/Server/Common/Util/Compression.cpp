// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "Compression.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   Compression::Compression(String sResultFile, String sBaseDir, bool bCompress) :
      m_sResultFile (sResultFile),
      m_sBaseDir (sBaseDir),
      _open(true)
   {

      if (bCompress)
         m_hZip = CreateZip(m_sResultFile.GetBuffer(0), 0);
      else
      {
         ::CreateDirectory(m_sBaseDir, 0);

         m_hZip = OpenZip(m_sResultFile.GetBuffer(0), 0);

         SetUnzipBaseDir(m_hZip, m_sBaseDir);
      }
      
   }

   Compression::~Compression(void)
   {
      Close();
   }

   bool
   Compression::AddDirectory(String sDirectory)
   {
      String sDirName = sDirectory;
     
      // Remove base dir.
      sDirName.Replace(m_sBaseDir, _T(""));
      
      if (!sDirName.IsEmpty())
         ZRESULT zr = ZipAddFolder(m_hZip, sDirName);

      if (sDirectory.Right(1) != _T("\\"))
         sDirectory += _T("\\");

      String sWildCard = sDirectory + _T("*.*");

      // Locate first match
      WIN32_FIND_DATA ffData;
      HANDLE hFileFound = FindFirstFile(sWildCard, &ffData);

      if (hFileFound == INVALID_HANDLE_VALUE)
         return FALSE;

      while (hFileFound && FindNextFile(hFileFound, &ffData))
      {
         String sFullPath = sDirectory + ffData.cFileName;

         if (ffData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) 
         {
            if( (_tcscmp(ffData.cFileName, _T(".")) != 0) &&
               (_tcscmp(ffData.cFileName, _T("..")) != 0) ) 
            {
               if( !AddDirectory(sFullPath) )
                  return false;
            }

         }
         else
         { 
            if (!AddFile(sFullPath))
               return false;
         }
      }

      FindClose(hFileFound);

      return true;
   }

   bool
   Compression::AddFile(String sFile)
   {
      String sFilename = sFile;
      sFilename.Replace(m_sBaseDir, _T(""));

      ZRESULT zr = ZipAdd(m_hZip, sFilename, sFile.GetBuffer(0));

      if (zr == ZR_OK)
         return true;
      else
         return false;
   }

   bool
   Compression::Close()
   {
      if (!_open)
         return true;

      CloseZip(m_hZip);  
      _open = false;
      return true;
   }

   bool
   Compression::Uncompress()
   {
      ZIPENTRY ze; 
      GetZipItem(m_hZip,-1,&ze); 

      int iNoOfItems=ze.index;

      for (int i=0; i<iNoOfItems; i++)
      { 
         GetZipItem(m_hZip,i,&ze);
         if (UnzipItem(m_hZip,i,ze.name) != ZR_OK)
            return false;
      }

      return true;
   }

   bool
   Compression::UncompressFile(const String &sFilename)
   {
      ZIPENTRY ze; 
      GetZipItem(m_hZip,-1,&ze); 

      int iNoOfItems=ze.index;

      for (int i=0; i<iNoOfItems; i++)
      { 
         GetZipItem(m_hZip,i,&ze);

         if (ze.name == sFilename)
         {
            if (UnzipItem(m_hZip,i,ze.name) != ZR_OK)
               return false;

            return true;
         }
      }

      return false;
   }
}
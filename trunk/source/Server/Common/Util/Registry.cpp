// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "Registry.h"



namespace HM
{
   Registry::Registry(void)
   {
   }

   Registry::~Registry(void)
   {
   }

   bool
   Registry::GetStringValue(HKEY hive, String key, String valueName, String &value)
   {
     /* HKEY   hkey; 
      DWORD  dwDisposition; 
      LONG result = RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software"),  
         0, NULL, 0, KEY_READ, NULL, &hkey, &dwDisposition); 
*/

      DWORD maxSize = 8096;

      HKEY   hkey;

      if(RegCreateKeyExW(HKEY_LOCAL_MACHINE, key, 0, NULL, 0, KEY_READ, NULL, &hkey, 0) != ERROR_SUCCESS)
      {
         int err = GetLastError();
         return false;
      }

      DWORD dwType = REG_SZ;
      bool success = 
         RegQueryValueEx(hkey, valueName.GetBuffer(), NULL, &dwType, (PBYTE) value.GetBuffer(maxSize), &maxSize) == ERROR_SUCCESS;

      RegCloseKey(hkey);

      value.ReleaseBuffer();

      if (dwType != REG_SZ || success == false)
         return false;

      return true;
   }



}
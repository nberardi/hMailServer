/////////////////////////////////////////////////////////////////////////////// 
// 
//  SSPI Authentication Sample
// 
//  This program demonstrates how to use SSPI to authenticate user credentials.
// 
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
//  TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
// 
//  Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
/////////////////////////////////////////////////////////////////////////////// 
//
// The code below is from the Microsoft knowledgebase item below:
// How To Validate User Credentials on Microsoft Operating Systems
// http://support.microsoft.com/default.aspx?scid=kb;EN-US;180548
// 
//
// MICROSOFT LIMITED PUBLIC LICENSE
// 
// This license governs use of code marked as “sample” available on this 
// Web Site without a License Agreement , as provided under the Section above
// titled “ NOTICE SPECIFIC TO SOFTWARE AVAILABLE ON THIS WEB SITE ”. If you
// use such code (the “software”), you accept this license. If you do not
// accept the license, do not use the software.
// 
// 1. Definitions
// 
// The terms “reproduce,” “reproduction,” “derivative works,” and “distribution”
// have the same meaning here as under U.S. copyright law.
// 
// A “contribution” is the original software, or any additions or changes to the 
// software.
// 
// A “contributor” is any person that distributes its contribution under 
// this license.
// 
// “Licensed patents” are a contributor’s patent claims that read directly
// on its contribution.
// 
// 2. Grant of Rights
// 
// (A) Copyright Grant- Subject to the terms of this license, including the 
// license conditions and limitations in section 3, each contributor grants
// you a non-exclusive, worldwide, royalty-free copyright license to reproduce
// its contribution, prepare derivative works of its contribution, and distribute 
// its contribution or any derivative works that you create.
// 
// (B) Patent Grant- Subject to the terms of this license, including the 
// license conditions and limitations in section 3, each contributor grants 
// you a non-exclusive, worldwide, royalty-free license under its licensed patents
// to make, have made, use, sell, offer for sale, import, and/or otherwise dispose
// of its contribution in the software or derivative works of the contribution 
// in the software.
// 
// 3. Conditions and Limitations
// 
// (A) No Trademark License- This license does not grant you rights to use any 
// contributors’ name, logo, or trademarks.
// 
// (B) If you bring a patent claim against any contributor over patents that you 
// claim are infringed by the software, your patent license from such contributor
// to the software ends automatically.
// 
// (C) If you distribute any portion of the software, you must retain all copyright,
// patent, trademark, and attribution notices that are present in the software.
// 
// (D) If you distribute any portion of the software in source code form, you may
// do so only under this license by including a complete copy of this license with
// your distribution. If you distribute any portion of the software in compiled or 
// object code form, you may only do so under a license that complies with this license.
// 
// (E) The software is licensed “as-is.” You bear the risk of using it. The contributors
// give no express warranties, guarantees or conditions. You may have additional
// consumer rights under your local laws which this license cannot change. To the extent 
// permitted under your local laws, the contributors exclude the implied warranties of 
// merchantability, fitness for a particular purpose and non-infringement.
// 
// (F) Platform Limitation- The licenses granted in sections 2(A) & 2(B) extend only to
// the software or derivative works that you create that run on a Microsoft Windows 
// operating system product.

#include "stdafx.h"
#include "SSPIValidation.h"
#define SECURITY_WIN32
#include <sspi.h>



// Older versions of WinError.h does not have SEC_I_COMPLETE_NEEDED #define.
// So, in such SDK environment setup, we will include issperr.h which has the
// definition for SEC_I_COMPLETE_NEEDED. Include issperr.h only if
// SEC_I_COMPLETE_NEEDED is not defined.
#ifndef SEC_I_COMPLETE_NEEDED
#include <issperr.h>
#endif

namespace HM
{


   typedef struct _AUTH_SEQ {
      BOOL fInitialized;
      BOOL fHaveCredHandle;
      BOOL fHaveCtxtHandle;
      CredHandle hcred;
      struct _SecHandle hctxt;
   } AUTH_SEQ, *PAUTH_SEQ;


   // Function pointers
   ACCEPT_SECURITY_CONTEXT_FN       _AcceptSecurityContext     = NULL;
   ACQUIRE_CREDENTIALS_HANDLE_FN    _AcquireCredentialsHandle  = NULL;
   COMPLETE_AUTH_TOKEN_FN           _CompleteAuthToken         = NULL;
   DELETE_SECURITY_CONTEXT_FN       _DeleteSecurityContext     = NULL;
   FREE_CONTEXT_BUFFER_FN           _FreeContextBuffer         = NULL;
   FREE_CREDENTIALS_HANDLE_FN       _FreeCredentialsHandle     = NULL;
   INITIALIZE_SECURITY_CONTEXT_FN   _InitializeSecurityContext = NULL;
   QUERY_SECURITY_PACKAGE_INFO_FN   _QuerySecurityPackageInfo  = NULL;


   ///////////////////////


   SSPIValidation::SSPIValidation()
   {

   }

   SSPIValidation::~SSPIValidation()
   {

   }

//////////////////////////////////////////////////////// 


   void UnloadSecurityDll(HMODULE hModule) {

      if (hModule)
         FreeLibrary(hModule);

      _AcceptSecurityContext      = NULL;
      _AcquireCredentialsHandle   = NULL;
      _CompleteAuthToken          = NULL;
      _DeleteSecurityContext      = NULL;
      _FreeContextBuffer          = NULL;
      _FreeCredentialsHandle      = NULL;
      _InitializeSecurityContext  = NULL;
      _QuerySecurityPackageInfo   = NULL;
   }


   /////////////////////////////////////////////////////////////////////////////// 


   HMODULE LoadSecurityDll() {

      HMODULE hModule;
      BOOL    fAllFunctionsLoaded = FALSE; 
      TCHAR   lpszDLL[MAX_PATH];
      OSVERSIONINFO VerInfo;

      // 
      //  Find out which security DLL to use, depending on
      //  whether we are on NT or Win95 or 2000 or XP or Windows Server 2003
      //  We have to use security.dll on Windows NT 4.0.
      //  All other operating systems, we have to use Secur32.dll
      // 
      VerInfo.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
      if (!GetVersionEx (&VerInfo))   // If this fails, something has gone wrong
      {
         return FALSE;
      }

      if (VerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
         VerInfo.dwMajorVersion == 4 &&
         VerInfo.dwMinorVersion == 0)
      {
         lstrcpy (lpszDLL, _T("security.dll"));
      }
      else
      {
         lstrcpy (lpszDLL, _T("secur32.dll"));
      }


      hModule = LoadLibrary(lpszDLL);
      if (!hModule)
         return NULL;

      __try {

         _AcceptSecurityContext = (ACCEPT_SECURITY_CONTEXT_FN) 
               GetProcAddress(hModule, "AcceptSecurityContext");
         if (!_AcceptSecurityContext)
            __leave;

   #ifdef UNICODE
         _AcquireCredentialsHandle = (ACQUIRE_CREDENTIALS_HANDLE_FN)
               GetProcAddress(hModule, "AcquireCredentialsHandleW");
   #else
         _AcquireCredentialsHandle = (ACQUIRE_CREDENTIALS_HANDLE_FN)
               GetProcAddress(hModule, "AcquireCredentialsHandleA");
   #endif
         if (!_AcquireCredentialsHandle)
            __leave;

         // CompleteAuthToken is not present on Windows 9x Secur32.dll
         // Do not check for the availablity of the function if it is NULL;
         _CompleteAuthToken = (COMPLETE_AUTH_TOKEN_FN) 
               GetProcAddress(hModule, "CompleteAuthToken");

         _DeleteSecurityContext = (DELETE_SECURITY_CONTEXT_FN) 
               GetProcAddress(hModule, "DeleteSecurityContext");
         if (!_DeleteSecurityContext)
            __leave;

         _FreeContextBuffer = (FREE_CONTEXT_BUFFER_FN) 
               GetProcAddress(hModule, "FreeContextBuffer");
         if (!_FreeContextBuffer)
            __leave;

         _FreeCredentialsHandle = (FREE_CREDENTIALS_HANDLE_FN) 
               GetProcAddress(hModule, "FreeCredentialsHandle");
         if (!_FreeCredentialsHandle)
            __leave;

   #ifdef UNICODE
         _InitializeSecurityContext = (INITIALIZE_SECURITY_CONTEXT_FN)
               GetProcAddress(hModule, "InitializeSecurityContextW");
   #else
         _InitializeSecurityContext = (INITIALIZE_SECURITY_CONTEXT_FN) 
               GetProcAddress(hModule, "InitializeSecurityContextA");
   #endif
         if (!_InitializeSecurityContext)
            __leave;

   #ifdef UNICODE
         _QuerySecurityPackageInfo = (QUERY_SECURITY_PACKAGE_INFO_FN)
               GetProcAddress(hModule, "QuerySecurityPackageInfoW");
   #else
         _QuerySecurityPackageInfo = (QUERY_SECURITY_PACKAGE_INFO_FN)
               GetProcAddress(hModule, "QuerySecurityPackageInfoA");
   #endif
         if (!_QuerySecurityPackageInfo)
            __leave;

         fAllFunctionsLoaded = TRUE;

      } __finally {

         if (!fAllFunctionsLoaded) {
            UnloadSecurityDll(hModule);
            hModule = NULL;
         }

      }
   
      return hModule;
   }


   /////////////////////////////////////////////////////////////////////////////// 


   BOOL GenClientContext(PAUTH_SEQ pAS, PSEC_WINNT_AUTH_IDENTITY pAuthIdentity,
         PVOID pIn, DWORD cbIn, PVOID pOut, PDWORD pcbOut, PBOOL pfDone) {

   /*++

    Routine Description:

      Optionally takes an input buffer coming from the server and returns
      a buffer of information to send back to the server.  Also returns
      an indication of whether or not the context is complete.

    Return Value:

      Returns TRUE if successful; otherwise FALSE.

   --*/ 

      SECURITY_STATUS ss;
      TimeStamp       tsExpiry;
      SecBufferDesc   sbdOut;
      SecBuffer       sbOut;
      SecBufferDesc   sbdIn;
      SecBuffer       sbIn;
      ULONG           fContextAttr;

      if (!pAS->fInitialized) {
      
         ss = _AcquireCredentialsHandle(NULL, _T("NTLM"), 
               SECPKG_CRED_OUTBOUND, NULL, pAuthIdentity, NULL, NULL,
               &pAS->hcred, &tsExpiry);
         if (ss < 0) 
         {
            return FALSE;
         }

         pAS->fHaveCredHandle = TRUE;
      }

      // Prepare output buffer
      sbdOut.ulVersion = 0;
      sbdOut.cBuffers = 1;
      sbdOut.pBuffers = &sbOut;

      sbOut.cbBuffer = *pcbOut;
      sbOut.BufferType = SECBUFFER_TOKEN;
      sbOut.pvBuffer = pOut;

      // Prepare input buffer
      if (pAS->fInitialized)  {
         sbdIn.ulVersion = 0;
         sbdIn.cBuffers = 1;
         sbdIn.pBuffers = &sbIn;

         sbIn.cbBuffer = cbIn;
         sbIn.BufferType = SECBUFFER_TOKEN;
         sbIn.pvBuffer = pIn;
      }

      ss = _InitializeSecurityContext(&pAS->hcred, 
            pAS->fInitialized ? &pAS->hctxt : NULL, NULL, 0, 0, 
            SECURITY_NATIVE_DREP, pAS->fInitialized ? &sbdIn : NULL,
            0, &pAS->hctxt, &sbdOut, &fContextAttr, &tsExpiry);
      if (ss < 0)  
      { 
         return FALSE;
      }

      pAS->fHaveCtxtHandle = TRUE;

      // If necessary, complete token
      if (ss == SEC_I_COMPLETE_NEEDED || ss == SEC_I_COMPLETE_AND_CONTINUE) {

         if (_CompleteAuthToken) {
            ss = _CompleteAuthToken(&pAS->hctxt, &sbdOut);
            if (ss < 0)  
            {
               return FALSE;
            }
         }
         else 
         {
            return FALSE;
         }
      }

      *pcbOut = sbOut.cbBuffer;

      if (!pAS->fInitialized)
         pAS->fInitialized = TRUE;

      *pfDone = !(ss == SEC_I_CONTINUE_NEEDED 
            || ss == SEC_I_COMPLETE_AND_CONTINUE );

      return TRUE;
   }


   /////////////////////////////////////////////////////////////////////////////// 


   BOOL GenServerContext(PAUTH_SEQ pAS, PVOID pIn, DWORD cbIn, PVOID pOut,
         PDWORD pcbOut, PBOOL pfDone) {

   /*++

    Routine Description:

       Takes an input buffer coming from the client and returns a buffer
       to be sent to the client.  Also returns an indication of whether or
       not the context is complete.

    Return Value:

       Returns TRUE if successful; otherwise FALSE.

   --*/ 

      SECURITY_STATUS ss;
      TimeStamp       tsExpiry;
      SecBufferDesc   sbdOut;
      SecBuffer       sbOut;
      SecBufferDesc   sbdIn;
      SecBuffer       sbIn;
      ULONG           fContextAttr;

      if (!pAS->fInitialized)  {
      
         ss = _AcquireCredentialsHandle(NULL, _T("NTLM"), 
               SECPKG_CRED_INBOUND, NULL, NULL, NULL, NULL, &pAS->hcred, 
               &tsExpiry);
         if (ss < 0) 
         {
            return FALSE;
         }

         pAS->fHaveCredHandle = TRUE;
      }

      // Prepare output buffer
      sbdOut.ulVersion = 0;
      sbdOut.cBuffers = 1;
      sbdOut.pBuffers = &sbOut;

      sbOut.cbBuffer = *pcbOut;
      sbOut.BufferType = SECBUFFER_TOKEN;
      sbOut.pvBuffer = pOut;

      // Prepare input buffer
      sbdIn.ulVersion = 0;
      sbdIn.cBuffers = 1;
      sbdIn.pBuffers = &sbIn;

      sbIn.cbBuffer = cbIn;
      sbIn.BufferType = SECBUFFER_TOKEN;
      sbIn.pvBuffer = pIn;

      ss = _AcceptSecurityContext(&pAS->hcred, 
            pAS->fInitialized ? &pAS->hctxt : NULL, &sbdIn, 0, 
            SECURITY_NATIVE_DREP, &pAS->hctxt, &sbdOut, &fContextAttr, 
            &tsExpiry);
      if (ss < 0)  
      {
         return FALSE;
      }

      pAS->fHaveCtxtHandle = TRUE;

      // If necessary, complete token
      if (ss == SEC_I_COMPLETE_NEEDED || ss == SEC_I_COMPLETE_AND_CONTINUE) {
      
         if (_CompleteAuthToken) {
            ss = _CompleteAuthToken(&pAS->hctxt, &sbdOut);
            if (ss < 0)  
            {
               return FALSE;
            }
         }
         else 
         {
            return FALSE;
         }
      }

      *pcbOut = sbOut.cbBuffer;

      if (!pAS->fInitialized)
         pAS->fInitialized = TRUE;

      *pfDone = !(ss = SEC_I_CONTINUE_NEEDED 
            || ss == SEC_I_COMPLETE_AND_CONTINUE);

      return TRUE;
   }


   /////////////////////////////////////////////////////////////////////////////// 


   BOOL WINAPI SSPLogonUser(LPCTSTR szDomain, LPCTSTR szUser, LPCTSTR szPassword) {

      AUTH_SEQ    asServer   = {0};
      AUTH_SEQ    asClient   = {0};
      BOOL        fDone      = FALSE;
      BOOL        fResult    = FALSE;
      DWORD       cbOut      = 0;
      DWORD       cbIn       = 0;
      DWORD       cbMaxToken = 0;
      PVOID       pClientBuf = NULL;
      PVOID       pServerBuf = NULL;
      PSecPkgInfo pSPI       = NULL;
      HMODULE     hModule    = NULL;

      SEC_WINNT_AUTH_IDENTITY ai;

      __try {

         hModule = LoadSecurityDll();
         if (!hModule)
            __leave;

         // Get max token size
         _QuerySecurityPackageInfo(_T("NTLM"), &pSPI);
         cbMaxToken = pSPI->cbMaxToken;
         _FreeContextBuffer(pSPI);

         // Allocate buffers for client and server messages
         pClientBuf = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cbMaxToken);
         pServerBuf = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cbMaxToken);

         // Initialize auth identity structure
         ZeroMemory(&ai, sizeof(ai));
   #if defined(UNICODE) || defined(_UNICODE)
         ai.Domain = (unsigned short*)szDomain;
         ai.DomainLength = lstrlen(szDomain);
         ai.User = (unsigned short*)szUser;
         ai.UserLength = lstrlen(szUser);
         ai.Password = (unsigned short*)szPassword;
         ai.PasswordLength = lstrlen(szPassword);
         ai.Flags = SEC_WINNT_AUTH_IDENTITY_UNICODE;
   #else      
         ai.Domain = (unsigned char *)szDomain;
         ai.DomainLength = lstrlen(szDomain);
         ai.User = (unsigned char *)szUser;
         ai.UserLength = lstrlen(szUser);
         ai.Password = (unsigned char *)szPassword;
         ai.PasswordLength = lstrlen(szPassword);
         ai.Flags = SEC_WINNT_AUTH_IDENTITY_ANSI;
   #endif

         // Prepare client message (negotiate) .
         cbOut = cbMaxToken;
         if (!GenClientContext(&asClient, &ai, NULL, 0, pClientBuf, &cbOut, &fDone))
            __leave;

         // Prepare server message (challenge) .
         cbIn = cbOut;
         cbOut = cbMaxToken;
         if (!GenServerContext(&asServer, pClientBuf, cbIn, pServerBuf, &cbOut, 
               &fDone))
            __leave;
            // Most likely failure: AcceptServerContext fails with SEC_E_LOGON_DENIED
            // in the case of bad szUser or szPassword.
            // Unexpected Result: Logon will succeed if you pass in a bad szUser and 
            // the guest account is enabled in the specified domain.

         // Prepare client message (authenticate) .
         cbIn = cbOut;
         cbOut = cbMaxToken;
         if (!GenClientContext(&asClient, &ai, pServerBuf, cbIn, pClientBuf, &cbOut,
               &fDone))
            __leave;

         // Prepare server message (authentication) .
         cbIn = cbOut;
         cbOut = cbMaxToken;
         if (!GenServerContext(&asServer, pClientBuf, cbIn, pServerBuf, &cbOut, 
               &fDone))
            __leave;

         fResult = TRUE;

      } __finally {

         // Clean up resources
         if (asClient.fHaveCtxtHandle)
            _DeleteSecurityContext(&asClient.hctxt);

         if (asClient.fHaveCredHandle)
            _FreeCredentialsHandle(&asClient.hcred);

         if (asServer.fHaveCtxtHandle)
            _DeleteSecurityContext(&asServer.hctxt);

         if (asServer.fHaveCredHandle)
            _FreeCredentialsHandle(&asServer.hcred);

         if (hModule)
            UnloadSecurityDll(hModule);

         HeapFree(GetProcessHeap(), 0, pClientBuf);
         HeapFree(GetProcessHeap(), 0, pServerBuf);

      }

      return fResult;
   }

   CriticalSection SSPIValidation::m_oCritSec;

   bool
   SSPIValidation::ValidateUser(const String &sDomain, const String &sUsername, const String &sPassword)
   {
      CriticalSectionScope scope(m_oCritSec);

      if (SSPLogonUser(sDomain, sUsername, sPassword))
         return true;
      else
         return false;
   }
}
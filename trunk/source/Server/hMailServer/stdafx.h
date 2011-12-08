// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

// Set min version of Windows platform to Windows 2003
#define _WIN32_WINNT _WIN32_WINNT_WS03
#define NTDDI_VERSION NTDDI_WS03

#pragma warning( disable : 4180 )

// START: CRT + standard library settings.
	#define _CRT_SECURE_NO_DEPRECATE
	#define _CRT_NON_CONFORMING_SWPRINTFS
// END: Standard library settings

#define STRICT
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

// START: ATL settings
	#define _ATL_FREE_THREADEDLPCWSTR
	#define _ATL_NO_AUTOMATIC_NAMESPACE
	#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

	// turns off ATL's hiding of some common and often safely ignored warning messages
	#define _ATL_ALL_WARNINGS
// END: ATL settings

// Needed for rand_s() function
#define _CRT_RAND_S
#include <stdlib.h>

#include "WinSock2.h"
#include "Windows.h"

// ADO
#import "C:\Program Files\Common Files\system\ado\msado27.tlb" \
   rename("EOF","adoEOF") \
   no_namespace

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>

//
// STL INCLUDES
//
#include <map>
#include <vector>
#include <set> 
#include <queue>
#include <functional>

//
// BOOST INCLUDES
//
#include <boost/shared_ptr.hpp> 
#include <boost/scoped_ptr.hpp> 
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/function.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#define boost_foreach BOOST_FOREACH

#ifdef _DEBUG
   #define _CRTDBG_MAP_ALLOC
   #include <stdlib.h>
   #include <crtdbg.h>
#endif

using namespace std;
using namespace boost;

// Start: Common files
   #include "..\Common\Util\StdString.h"

   #include "..\Common\Util\XMLite.h"
   #include "..\Common\Util\Singleton.h"
   #include "..\Common\Util\CriticalSection.h"
   #include "..\Common\Application\Constants.h"
   #include "..\Common\Application\PropertySet.h"
   #include "..\Common\Application\Configuration.h"
   #include "..\Common\Application\IniFileSettings.h"
   #include "..\Common\Application\Application.h"
   #include "..\Common\Application\Logger.h"
   #include "..\Common\Application\ErrorManager.h"
   #include "..\Common\SQL\SQLParameter.h"
   #include "..\Common\SQL\SQLStatement.h"
   #include "..\Common\SQL\DatabaseConnectionManager.h"
   #include "..\Common\SQL\DALRecordset.h"
   #include "..\Common\SQL\DALRecordsetFactory.h"
   #include "..\Common\SQL\SQLCommand.h"
   #include "..\Common\Util\Parsing\StringParser.h"
   #include "..\Common\Util\FileUtilities.h"
   #include "..\Common\Util\HeapChecker.h"
   #include "..\Common\BO\BusinessObject.h"
   #include "..\COM\COMAuthentication.h"
   #include "..\COM\COMAuthenticator.h"
   #include "..\IMAP\IMAPResult.h"
   #include "..\Common\TCPIP\IPAddress.h"
   #include "../Common/Util/Strings/FormatArgument.h"
   #include "../Common/Util/Strings/Formatter.h"
// End: Common files.

#define COMPILE_NEWAPIS_STUBS
using namespace ATL;
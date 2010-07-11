// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#pragma warning( disable : 4180 )

#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_STL 0
#define _SECURE_SCL_DEPRECATE 0
#define _CRT_NON_CONFORMING_SWPRINTFS

// Defines whether Checked Iterators are enabled. If defined as 1, unsafe iterator
// use causes a runtime error. If defined as 0, checked iterators are disabled.
#define _SECURE_SCL 1

// If defined as 1, an out of range iterator use causes an exception at runtime. 
// If defined as 0, the program is terminated by calling invalid_parameter. 
// The default value for _SECURE_SCL_THROWS is 0, meaning the program will be 
// terminated by default. Requires _SECURE_SCL to also be defined.
#define _SECURE_SCL_THROWS 1

#ifndef STRICT
#define STRICT
#endif

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0400		// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0500	// Change this to the appropriate value to target Windows 2000 or later.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0400	// Change this to the appropriate value to target IE 5.0 or later.
#endif

#define _ATL_FREE_THREADEDLPCWSTR
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off ATL's hiding of some common and often safely ignored warning messages
#define _ATL_ALL_WARNINGS

#include "WinSock2.h"
#include "Windows.h"

// INCLUDE ADO
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


using namespace std;
using namespace boost;

#define SS_ANSI // Force STD string to use ANSI functions.
#include "..\Common\Util\StdString.h"

// Typedef here so that we don't need to do it inside StdString.
namespace HM 
{ 
   typedef CStdStr<wchar_t> String; 
   typedef CStdStr<char> AnsiString; 
}

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

#define COMPILE_NEWAPIS_STUBS

using namespace ATL;
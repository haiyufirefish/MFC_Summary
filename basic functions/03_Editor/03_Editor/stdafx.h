
// stdafx.h: include file for standard system include files,
// Or often used but not often changed
// Project-specific include files
#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            //  Windows header exclude useless files
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // Some CString constructors will be explicit

// Turn off MFC's hiding of some common but often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC expansion


#include <afxdisp.h>        // MFC automation class



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC ¶Ô Internet Explorer 4 public control support
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>          
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     /









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif




// 04_Timeout.h : 04_Timeout 
//
#pragma once

#ifndef __AFXWIN_H__
	#error "stdafx.h PCH "
#endif

#include "resource.h"     


// CMy04_TimeoutApp:
//
//

class CMy04_TimeoutApp : public CWinAppEx
{
public:
	CMy04_TimeoutApp();


public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTestDemo();
};

extern CMy04_TimeoutApp theApp;


//
#pragma once

#ifndef __AFXWIN_H__
	#error "pch"
#endif

#include "resource.h"      





class CMy02_DialogApp : public CWinAppEx
{
public:
	CMy02_DialogApp();



public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02_DialogApp theApp;

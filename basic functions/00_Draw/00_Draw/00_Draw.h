
// 00_Draw.h : 02_Draw 
//
#pragma once

#ifndef __AFXWIN_H__
	#error "Include "stdafx.h" before including this file to generate a PCH file"
#endif

#include "resource.h"       // include resoure


// CMy02_DrawApp:
//

class CMy02_DrawApp : public CWinAppEx
{
public:
	CMy02_DrawApp();


// overirde
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// implementation: about menu
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02_DrawApp theApp;


// 03_Editor.h : 03_Editor main header
//
#pragma once

#ifndef __AFXWIN_H__
	#error "stdafx.h PCH"
#endif

#include "resource.h"      


// CMy03_EditorApp:
//

class CMy03_EditorApp : public CWinAppEx
{
public:
	CMy03_EditorApp();

//override
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// impl
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03_EditorApp theApp;

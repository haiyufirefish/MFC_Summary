
// 03_Editor.h : 03_Editor Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy03_EditorApp:
// �йش����ʵ�֣������ 03_Editor.cpp
//

class CMy03_EditorApp : public CWinAppEx
{
public:
	CMy03_EditorApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03_EditorApp theApp;

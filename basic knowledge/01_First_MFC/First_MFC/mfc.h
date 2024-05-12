#pragma once

#include <afxwin.h>

//1£©application class and its derived class CWinApp, 
class MyApp: public CWinApp
{
public:
	// vitual function from base class
	// derived class is just overried
	// entry point
	virtual BOOL InitInstance();
};



//2£©frame work class	CFrameWnd, 
class MyFrame: public CFrameWnd
{
public:
	MyFrame();
	//In CFrameWnd, there is a variable m_pMainWnd CFrame pointer
	//declare macro
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT, CPoint);

	afx_msg void OnPaint();

	afx_msg void OnRButtonDown(UINT, CPoint);

private:
};
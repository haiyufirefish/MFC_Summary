#include "mfc.h"

//only one global application class object
MyApp myApp;

//entry address
BOOL MyApp::InitInstance()
{

	/*
	1. Create a frame class object
	2. Display window
	3. Update window
	4. Save the frame class object pointer
	*/

	//1、create frame
	MyFrame *frame = new MyFrame(); 

	//	2、show windows
	frame->ShowWindow(SW_SHOWNORMAL);

	//	3、update
	frame->UpdateWindow();

	//4、reserve handle   m_pMainWnd CFrame pointer
	m_pMainWnd = frame;

	return TRUE;
}

//register macro
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// diff between ON and Create
MyFrame::MyFrame()
{
	//CWnd member function CWnd::Create
	//CFrameWnd extends CWnd

	Create(NULL, TEXT("MFC"));
}

void MyFrame::OnLButtonDown(UINT, CPoint)
{
	//CWnd::MessageBox
	MessageBox(TEXT("left click"));
}

void MyFrame::OnRButtonDown(UINT, CPoint)
{
	//CWnd::MessageBox
	MessageBox(TEXT("right click"));
}


void MyFrame::OnPaint()
{
// 	QPainter p(this); // qt
// 	p.drawxxxx();

	CPaintDC cdc(this);
	//cdc.TextOutW(100, 100, TEXT("fk,mfc"));

	CRect rect;

	GetClientRect(&rect);

	// set the position
	cdc.DrawText(TEXT("hello MFC"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

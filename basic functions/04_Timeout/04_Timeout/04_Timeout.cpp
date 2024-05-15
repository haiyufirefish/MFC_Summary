
// 04_Timeout.cpp : 
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "04_Timeout.h"
#include "MainFrm.h"

#include "04_TimeoutDoc.h"
#include "04_TimeoutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04_TimeoutApp

BEGIN_MESSAGE_MAP(CMy04_TimeoutApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMy04_TimeoutApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_TEST_DEMO, &CMy04_TimeoutApp::OnTestDemo)
END_MESSAGE_MAP()


// CMy04_TimeoutApp constructor

CMy04_TimeoutApp::CMy04_TimeoutApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED

	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	SetAppID(_T("04_Timeout.AppID.NoVersion"));

}

// CMy04_TimeoutApp object

CMy04_TimeoutApp theApp;


// CMy04_TimeoutApp init

BOOL CMy04_TimeoutApp::InitInstance()
{

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Ole lib
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);



	SetRegistryKey(_T("application generate local program"));
	LoadStdProfileSettings(4);  


	// register document and view
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMy04_TimeoutDoc),
		RUNTIME_CLASS(CMainFrame),       
		RUNTIME_CLASS(CMy04_TimeoutView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// shell info
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CMy04_TimeoutApp::ExitInstance()
{
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}


// CAboutDlg

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// impl
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


void CMy04_TimeoutApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


void CMy04_TimeoutApp::OnTestDemo()
{

	AfxMessageBox(TEXT("APP"));

}

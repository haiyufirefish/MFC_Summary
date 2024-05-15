
// MainFrm.h : CMainFrame 
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: 
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)




public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// impl
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;


protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	//afx_msg void OnTestDemo();
};



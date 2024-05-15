
// 04_TimeoutView.h : CMy04_TimeoutView
//

#pragma once


class CMy04_TimeoutView : public CView
{
protected: 
	CMy04_TimeoutView();
	DECLARE_DYNCREATE(CMy04_TimeoutView)

public:
	CMy04_TimeoutDoc* GetDocument() const;


public:
	virtual void OnDraw(CDC* pDC);  // for draw
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:
	virtual ~CMy04_TimeoutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg void OnTestDemo();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version
inline CMy04_TimeoutDoc* CMy04_TimeoutView::GetDocument() const
   { return reinterpret_cast<CMy04_TimeoutDoc*>(m_pDocument); }
#endif


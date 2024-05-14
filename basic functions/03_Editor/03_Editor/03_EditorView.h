
// 03_EditorView.h : CMy03_EditorView 
//

#pragma once
#include "atltypes.h"


class CMy03_EditorView : public CView
{
protected: 
	CMy03_EditorView();
	DECLARE_DYNCREATE(CMy03_EditorView)

// Ьиад
public:
	CMy03_EditorDoc* GetDocument() const;

// opearation
public:

// override
public:
	virtual void OnDraw(CDC* pDC);  // overirde for draw
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// impl
public:
	virtual ~CMy03_EditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_point;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CString str;
};

#ifndef _DEBUG  // 03_EditorView.cpp Debug version
inline CMy03_EditorDoc* CMy03_EditorView::GetDocument() const
   { return reinterpret_cast<CMy03_EditorDoc*>(m_pDocument); }
#endif


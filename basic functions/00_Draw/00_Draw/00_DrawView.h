
// 02_DrawView.h : CMy02_DrawView implementation
//

#pragma once
#include "atltypes.h"


class CMy02_DrawView : public CView
{
protected: 
	CMy02_DrawView();
	DECLARE_DYNCREATE(CMy02_DrawView)

public:
	CMy02_DrawDoc* GetDocument() const;

public:

public:
	virtual void OnDraw(CDC* pDC);  // redraw
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:
	virtual ~CMy02_DrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// mapping
protected:
	DECLARE_MESSAGE_MAP()

private:
	//CPoint m_point;
	CPoint m_myPoint;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	bool m_isPress;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 
inline CMy02_DrawDoc* CMy02_DrawView::GetDocument() const
   { return reinterpret_cast<CMy02_DrawDoc*>(m_pDocument); }
#endif


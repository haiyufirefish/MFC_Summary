
// 02_DialogView.h : CMy02_DialogView
//

#pragma once


class CMy02_DialogView : public CView
{
protected: 
	CMy02_DialogView();
	DECLARE_DYNCREATE(CMy02_DialogView)


public:
	CMy02_DialogDoc* GetDocument() const;




public:
	virtual void OnDraw(CDC* pDC);  
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);


public:
	virtual ~CMy02_DialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:


protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  
inline CMy02_DialogDoc* CMy02_DialogView::GetDocument() const
   { return reinterpret_cast<CMy02_DialogDoc*>(m_pDocument); }
#endif


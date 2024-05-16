
// 02_DialogView.cpp : CMy02_DialogView impl
//

#include "stdafx.h"
#ifndef SHARED_HANDLERS
#include "02_Dialog.h"
#endif

#include "02_DialogDoc.h"
#include "02_DialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02_DialogView

IMPLEMENT_DYNCREATE(CMy02_DialogView, CView)

BEGIN_MESSAGE_MAP(CMy02_DialogView, CView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()


CMy02_DialogView::CMy02_DialogView(){


}

CMy02_DialogView::~CMy02_DialogView()
{
}

BOOL CMy02_DialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}


void CMy02_DialogView::OnDraw(CDC* /*pDC*/)
{
	CMy02_DialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

}



BOOL CMy02_DialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMy02_DialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMy02_DialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}


#ifdef _DEBUG
void CMy02_DialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMy02_DialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02_DialogDoc* CMy02_DialogView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02_DialogDoc)));
	return (CMy02_DialogDoc*)m_pDocument;
}
#endif //_DEBUG



// 02_DrawView.cpp : CMy02_DrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "00_Draw.h"
#endif

#include "00_DrawDoc.h"
#include "00_DrawView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02_DrawView

IMPLEMENT_DYNCREATE(CMy02_DrawView, CView)

BEGIN_MESSAGE_MAP(CMy02_DrawView, CView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// 

CMy02_DrawView::CMy02_DrawView()
: m_myPoint(0)
, m_isPress(false)
{

}

CMy02_DrawView::~CMy02_DrawView()
{
}

BOOL CMy02_DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	//  CREATESTRUCT cs to modify the window class or style

	return CView::PreCreateWindow(cs);
}

// CMy02_DrawView print

void CMy02_DrawView::OnDraw(CDC* pDC)
{
	CMy02_DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	/*
		a) Define painter
		b) Define the brush (brush) CPen, CBrush
		c) Give the brush to the painter CDC::SelectObject

	*/
	//PS_DASH: Dashed only works when the brush width is 1 or less (in device units).
	// 10; line width
	CPen pen(PS_DASH, 0.7, RGB(124, 155, 13));

	//return to before setting state
	CPen *oldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(10, 10);
	pDC->LineTo(120, 10);

	//recovery
	pDC->SelectObject(oldPen);

	//draw ellipse
	pDC->Ellipse(20, 20, 120, 120);

	//brush
	CBrush brush(RGB(255, 255, 0));
	pDC->SelectObject(&brush);
	pDC->Ellipse(20, 20, 120, 120);


	//Define a bitmap object
	CBitmap bitmap; 
	bitmap.LoadBitmapW(IDB_BITMAP1); //load bitmap

	CBrush brush2(&bitmap);
	pDC->SelectObject(&brush2);
	pDC->Ellipse(120, 20, 240, 240);


	CFont font;
	//1000: font width, 0.1 times
	//TEXT("楷体"): font style
	font.CreatePointFont(1000, TEXT("楷体"));

	//Use fonts, leave the fonts to the painter
	pDC->SelectObject(&font);

	pDC->TextOutW(100, 100, TEXT("HELLO, MIKE"));



}



BOOL CMy02_DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMy02_DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMy02_DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}



#ifdef _DEBUG
void CMy02_DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMy02_DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02_DrawDoc* CMy02_DrawView::GetDocument() const // Non-debug builds are inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02_DrawDoc)));
	return (CMy02_DrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy02_DrawView message handler

void CMy02_DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  Add message handler code and/or call defaults here

	m_myPoint = point; //reserve the coordination

	m_isPress = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMy02_DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
#if 0
	//Create a painter and specify the drawing device
	CClientDC dc(this);

	dc.MoveTo(m_myPoint);
	dc.LineTo(point);
#endif

	m_isPress = false;

	CView::OnLButtonUp(nFlags, point);
}

void CMy02_DrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  Add message handler code and/or call defaults here

	if (m_isPress == true)
	{
		//Create a painter and specify the drawing device
		CClientDC dc(this);

		dc.MoveTo(m_myPoint);
		dc.LineTo(point);

		
		m_myPoint = point;
	}

	CView::OnMouseMove(nFlags, point);
}

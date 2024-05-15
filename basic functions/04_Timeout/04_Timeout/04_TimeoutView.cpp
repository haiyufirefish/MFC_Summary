
// 04_TimeoutView.cpp : CMy04_TimeoutView impl
//

#include "stdafx.h"

#ifndef SHARED_HANDLERS
#include "04_Timeout.h"
#endif

#include "04_TimeoutDoc.h"
#include "04_TimeoutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04_TimeoutView

IMPLEMENT_DYNCREATE(CMy04_TimeoutView, CView)

BEGIN_MESSAGE_MAP(CMy04_TimeoutView, CView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
//	ON_WM_TIMER()
//	ON_COMMAND(ID_TEST_DEMO, &CMy04_TimeoutView::OnTestDemo)
//ON_WM_TIMER()
ON_WM_TIMER()
END_MESSAGE_MAP()


CMy04_TimeoutView::CMy04_TimeoutView()
{

}

CMy04_TimeoutView::~CMy04_TimeoutView()
{
}

BOOL CMy04_TimeoutView::PreCreateWindow(CREATESTRUCT& cs)
{
	

	return CView::PreCreateWindow(cs);
}

// CMy04_TimeoutView draw

void CMy04_TimeoutView::OnDraw(CDC* /*pDC*/)
{
	CMy04_TimeoutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

}



BOOL CMy04_TimeoutView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMy04_TimeoutView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMy04_TimeoutView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}


// CMy04_TimeoutView 

#ifdef _DEBUG
void CMy04_TimeoutView::AssertValid() const
{
	CView::AssertValid();
}

void CMy04_TimeoutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04_TimeoutDoc* CMy04_TimeoutView::GetDocument() const // Non-debug builds are inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04_TimeoutDoc)));
	return (CMy04_TimeoutDoc*)m_pDocument;
}
#endif //_DEBUG



int CMy04_TimeoutView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;



	//set the timer
	//1: timer id
	//500: interval£¬ millsecond
	//NULL: Use the system's default processing function to trigger WM_TIMER every 500 milliseconds.
	SetTimer(1,  100, NULL);
	SetTimer(2,  500, NULL);

	return 0;
}


void CMy04_TimeoutView::OnTimer(UINT_PTR nIDEvent)
{

	if (nIDEvent == 1)
	{
#if 0
		static int i = 0;
		i++;

		CString str;
		str.Format(TEXT("%d"), i);

		if (i == 5)
		{
			KillTimer / 1);
		}


		MessageBox(str);
#endif

		static int w = 0;
		w += 10;

		CString str = TEXT("to be bestbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
		CClientDC dc(this);
		CSize size = dc.GetTextExtent(str);
		if (w > size.cx)
		{
			w = 0;
			Invalidate(); //
		}

		int x = 50;
		int y = 50;
		CRect rect(x, y, x + w, y + size.cy);

		dc.TextOutW(x, y, str);

		dc.SetTextColor(RGB(0, 66, 255));

		dc.DrawText(str, &rect, DT_LEFT);

	}else if (nIDEvent == 2)
	{
		KillTimer(1);
		static int w = 0;
		w += 10;

		CString str = TEXT("to be hhhhh");
		CClientDC dc(this);
		CSize size = dc.GetTextExtent(str);
		//if the width smaller than width, repeat 
		if (w > size.cx)
		{
			w = 0;
			//	refresh window
			Invalidate(); //Qt Update()
		}

		int x = 30;
		int y = 30;
		CRect rect(x, y, x + w, y + size.cy);

		//
		dc.TextOutW(x, y, str);

		dc.SetTextColor(RGB(0, 255, 255));

		dc.DrawText(str, &rect, DT_LEFT);

		
	}

	CView::OnTimer(nIDEvent);
}


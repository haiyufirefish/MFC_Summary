
// 03_EditorView.cpp : CMy03_EditorView impl
//

#include "stdafx.h"

#ifndef SHARED_HANDLERS
#include "03_Editor.h"
#endif

#include "03_EditorDoc.h"
#include "03_EditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03_EditorView

IMPLEMENT_DYNCREATE(CMy03_EditorView, CView)

BEGIN_MESSAGE_MAP(CMy03_EditorView, CView)
	
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy03_EditorView 

CMy03_EditorView::CMy03_EditorView()
: m_point(0)
, str(_T(""))
{

}

CMy03_EditorView::~CMy03_EditorView()
{
}

BOOL CMy03_EditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	

	return CView::PreCreateWindow(cs);
}

// CMy03_EditorView 

void CMy03_EditorView::OnDraw(CDC* /*pDC*/)
{
	CMy03_EditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

}


// CMy03_EditorView 

BOOL CMy03_EditorView::OnPreparePrinting(CPrintInfo* pInfo)
{

	return DoPreparePrinting(pInfo);
}

void CMy03_EditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMy03_EditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}


// CMy03_EditorView 

#ifdef _DEBUG
void CMy03_EditorView::AssertValid() const
{
	CView::AssertValid();
}

void CMy03_EditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03_EditorDoc* CMy03_EditorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03_EditorDoc)));
	return (CMy03_EditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy03_EditorView 

int CMy03_EditorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;


	//get text info
	CClientDC dc(this);

	TEXTMETRIC tm; //text info struct

	dc.GetTextMetrics(&tm);


	//implement fromCWnd
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight); //create inserter

	ShowCaret(); //display




	return 0;
}


void CMy03_EditorView::OnLButtonDown(UINT nFlags, CPoint point)
{

	SetCaretPos(point); 

	m_point = point;

	str = TEXT("");
	str.Empty();


	CView::OnLButtonDown(nFlags, point);
}

void CMy03_EditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC dc(this);

	


	if (nChar == VK_RETURN) //newline
	{
		str.Empty();


		TEXTMETRIC tm; //

		dc.GetTextMetrics(&tm);

		m_point.y = m_point.y + tm.tmHeight;

	}
	else if (nChar == VK_BACK) //backspace
	{
		//get the background
		COLORREF color = dc.GetBkColor();
		/*auto a = dc.GetBkColor();*/

		//set text color
		COLORREF oldColor = dc.SetTextColor(color);

		//white rewrite once
		dc.TextOutW(m_point.x, m_point.y, str);

		//exclue the last 
		str = str.Left(str.GetLength() - 1);
		

		//recover the color
		dc.SetTextColor(oldColor);
	}
	else
	{
		str += (TCHAR)nChar;
	}

	CFont font;
	font.CreatePointFont(160, _T("Arial")); // Change the font size here (160 is 16pt)

	// Select the font into the device context
	CFont* pOldFont = dc.SelectObject(&font);

	CSize size = dc.GetTextExtent(str); 
	int x = m_point.x + size.cx;
	//int x = m_point.x + size.cx;
	int y = m_point.y;

	SetCaretPos(CPoint(x, y));

	dc.TextOutW(m_point.x, m_point.y, str);

	dc.SelectObject(pOldFont);
	CView::OnChar(nChar, nRepCnt, nFlags);
}

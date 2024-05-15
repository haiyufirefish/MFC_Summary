
// 04_TimeoutDoc.cpp : CMy04_TimeoutDoc 
//

#include "stdafx.h"

#ifndef SHARED_HANDLERS
#include "04_Timeout.h"
#endif

#include "04_TimeoutDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy04_TimeoutDoc

IMPLEMENT_DYNCREATE(CMy04_TimeoutDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy04_TimeoutDoc, CDocument)
	//ON_COMMAND(ID_TEST_DEMO, &CMy04_TimeoutDoc::OnTestDemo)
END_MESSAGE_MAP()



CMy04_TimeoutDoc::CMy04_TimeoutDoc()
{

}

CMy04_TimeoutDoc::~CMy04_TimeoutDoc()
{
}

BOOL CMy04_TimeoutDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;



	return TRUE;
}

void CMy04_TimeoutDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
		
	}
}

#ifdef SHARED_HANDLERS

// thunmnaiils
void CMy04_TimeoutDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;

	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

void CMy04_TimeoutDoc::InitializeSearchContent()
{
	CString strSearchContent;
	
	SetSearchContent(strSearchContent);
}

void CMy04_TimeoutDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy04_TimeoutDoc 

#ifdef _DEBUG
void CMy04_TimeoutDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy04_TimeoutDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG






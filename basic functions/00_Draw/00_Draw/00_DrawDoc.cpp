
// 02_DrawDoc.cpp : CMy02_DrawDoc impl
//

#include "stdafx.h"
// SHARED_HANDLERS can be used to implement preview, thumbnail and search filter handles
// Defined in an ATL project and allow document code to be shared with that project.
#ifndef SHARED_HANDLERS
#include "00_Draw.h"
#endif

#include "00_DrawDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy02_DrawDoc

IMPLEMENT_DYNCREATE(CMy02_DrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy02_DrawDoc, CDocument)
END_MESSAGE_MAP()



CMy02_DrawDoc::CMy02_DrawDoc()
{

}

CMy02_DrawDoc::~CMy02_DrawDoc()
{
}

BOOL CMy02_DrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}




// CMy02_DrawDoc serialization

void CMy02_DrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

#ifdef SHARED_HANDLERS

// Thumbnail support
void CMy02_DrawDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to plot document data
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

void CMy02_DrawDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search content from document data.
	// Content parts should be separated by ";"

	//  strSearchContent = _T("point;rectangle;circle;ole object;")£»
	SetSearchContent(strSearchContent);
}

void CMy02_DrawDoc::SetSearchContent(const CString& value)
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

// CMy02_DrawDoc diagnostic

#ifdef _DEBUG
void CMy02_DrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy02_DrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy02_DrawDoc command


// 03_EditorDoc.cpp : CMy03_EditorDoc impl
//

#include "stdafx.h"
// SHARED_HANDLERS can be used to implement preview, thumbnail and search filter handles
// Defined in an ATL project and allow documentation code to be shared with that project.
#ifndef SHARED_HANDLERS
#include "03_Editor.h"
#endif

#include "03_EditorDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy03_EditorDoc

IMPLEMENT_DYNCREATE(CMy03_EditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy03_EditorDoc, CDocument)
END_MESSAGE_MAP()


// CMy03_EditorDoc 

CMy03_EditorDoc::CMy03_EditorDoc()
{

}

CMy03_EditorDoc::~CMy03_EditorDoc()
{
}

BOOL CMy03_EditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	

	return TRUE;
}




// CMy03_EditorDoc 

void CMy03_EditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

#ifdef SHARED_HANDLERS

// thumnails support
void CMy03_EditorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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

// Search handler support
void CMy03_EditorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search content from document data.
	// Content parts should be separated by ";"

	//      strSearchContent = _T("point;rectangle;circle;ole object;")£»
	SetSearchContent(strSearchContent);
}

void CMy03_EditorDoc::SetSearchContent(const CString& value)
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

// CMy03_EditorDoc diagnostic

#ifdef _DEBUG
void CMy03_EditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy03_EditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy03_EditorDoc command


// 03_EditorDoc.h : CMy03_EditorDoc interface 
//


#pragma once


class CMy03_EditorDoc : public CDocument
{
protected: 
	CMy03_EditorDoc();
	DECLARE_DYNCREATE(CMy03_EditorDoc)

public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// impl
public:
	virtual ~CMy03_EditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// generate mapping functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function used to set the search content for the search handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

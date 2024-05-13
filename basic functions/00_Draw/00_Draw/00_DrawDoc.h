
// 02_DrawDoc.h : CMy02_DrawDoc interface of doc
//


#pragma once


class CMy02_DrawDoc : public CDocument
{
protected: // Only created from serialization
	CMy02_DrawDoc();
	DECLARE_DYNCREATE(CMy02_DrawDoc)

// specification
public:

// operation
public:

// override
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// implementation
public:
	virtual ~CMy02_DrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// mapping function
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function used to set the search content for the search handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

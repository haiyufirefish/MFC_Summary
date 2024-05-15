
// 04_TimeoutDoc.h : CMy04_TimeoutDoc
//


#pragma once


class CMy04_TimeoutDoc : public CDocument
{
protected: // 
	CMy04_TimeoutDoc();
	DECLARE_DYNCREATE(CMy04_TimeoutDoc)


public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS


public:
	virtual ~CMy04_TimeoutDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// mapping
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// helper
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
/*	afx_msg void OnTestDemo();*/
};

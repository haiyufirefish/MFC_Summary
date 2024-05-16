
// 02_DialogDoc.h : CMy02_DialogDoc 
//


#pragma once


class CMy02_DialogDoc : public CDocument
{
protected:
	CMy02_DialogDoc();
	DECLARE_DYNCREATE(CMy02_DialogDoc)




public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS


public:
	virtual ~CMy02_DialogDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:


protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	
	void SetSearchContent(const CString& value);
#endif 
};

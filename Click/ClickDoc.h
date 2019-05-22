
// ClickDoc.h : interface of the CClickDoc class
//
#include "CPuncte.h";

#pragma once


class CClickDoc : public CDocument
{
protected: // create from serialization only
	CClickDoc() noexcept;
	DECLARE_DYNCREATE(CClickDoc)

// Attributes
public:
	CObArray m_puncte;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	CPuncte* AddPuncte(CPoint pt);
	int GetPointCount();
	CPuncte* GetPunct(int nIndex);
	void DeleteContents();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CClickDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

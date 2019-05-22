
// ClickDoc.cpp : implementation of the CClickDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Click.h"
#endif

#include "ClickDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CPuncte.h"

// CClickDoc

IMPLEMENT_DYNCREATE(CClickDoc, CDocument)

BEGIN_MESSAGE_MAP(CClickDoc, CDocument)
END_MESSAGE_MAP()


// CClickDoc construction/destruction

CClickDoc::CClickDoc() noexcept
{
	// TODO: add one-time construction code here

}

CClickDoc::~CClickDoc()
{
}

BOOL CClickDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CClickDoc serialization

void CClickDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		m_puncte.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
	}
}

CPuncte* CClickDoc::AddPuncte(CPoint pt)
{
	CPuncte* pct = new CPuncte(pt);
	m_puncte.Add(pct);
	CDocument::SetModifiedFlag();
	return pct;
}

int CClickDoc::GetPointCount()
{
	return m_puncte.GetSize();
}

CPuncte* CClickDoc::GetPunct(int nIndex)
{
	return(CPuncte*)m_puncte[nIndex];
}
void CClickDoc::DeleteContents()
{
	int pctCount = m_puncte.GetSize();
	int pctPos;
	if (pctCount) {
		for (pctPos = 0; pctPos < pctCount; pctPos++)
			delete m_puncte[pctPos];
		m_puncte.RemoveAll();
	}
	CDocument::DeleteContents();
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CClickDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void CClickDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CClickDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CClickDoc diagnostics

#ifdef _DEBUG
void CClickDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CClickDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CClickDoc commands

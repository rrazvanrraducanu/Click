
// ClickView.cpp : implementation of the CClickView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Click.h"
#endif

#include "ClickDoc.h"
#include "ClickView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CPuncte.h"


// CClickView

IMPLEMENT_DYNCREATE(CClickView, CView)

BEGIN_MESSAGE_MAP(CClickView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CClickView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CClickView construction/destruction

CClickView::CClickView() noexcept
{
	// TODO: add construction code here

}

CClickView::~CClickView()
{
}

BOOL CClickView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CClickView drawing

void CClickView::OnDraw(CDC* pDC)
{
	CClickDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	int pctCount = pDoc->GetPointCount();
	if (pctCount) {
		int pctPos;
		CPuncte* pct;
		for (pctPos = 0; pctPos < pctCount; pctPos++) {
			pct = pDoc->GetPunct(pctPos);
			pct->Draw(pDC);
		}
	}
}


// CClickView printing


void CClickView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CClickView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CClickView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CClickView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CClickView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CClickView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CClickView diagnostics

#ifdef _DEBUG
void CClickView::AssertValid() const
{
	CView::AssertValid();
}

void CClickView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClickDoc* CClickView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClickDoc)));
	return (CClickDoc*)m_pDocument;
}
#endif //_DEBUG


// CClickView message handlers


void CClickView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPuncte* pPuncte =
		GetDocument()->AddPuncte(point);
	pPuncte->Draw(&dc);
	CView::OnLButtonDown(nFlags, point);
	CView::OnLButtonDown(nFlags, point);
}

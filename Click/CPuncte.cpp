#include "pch.h"
#include "CPuncte.h"

//IMPLEMENT_SERIAL(CPuncte, CObject, 1);

CPuncte::CPuncte(CPoint pt)
//:m_pt(pt)
{
	m_pt = pt;
}

void CPuncte::Draw(CDC* pDC)
{
	pDC->TextOut(m_pt.x, m_pt.y, _T("Click!"));
}
void CPuncte::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
		ar << m_pt;
	else
		ar >> m_pt;
}
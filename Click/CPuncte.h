#pragma once
#include <afx.h>
class CPuncte : public CObject
{
	//DECLARE_SERIAL(CPuncte);
public:
	CPuncte(CPoint pt);
	void Draw(CDC* pDC);
	void Serialize(CArchive& ar);
private:
	CPoint m_pt;
	
};


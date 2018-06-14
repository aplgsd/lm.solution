#pragma once

#include <Windows.h>

class CShape:public CObject
{
public:
	CShape();
	CShape(CPoint ptStart,CPoint ptEnd);
	virtual void Draw(CDC* pDC)=0;
	void SetPos(CPoint ptStart,CPoint ptEnd);

	//void Serialize(CArchive& ar);

	~CShape(void);
protected:
	CPoint m_ptStart;
	CPoint m_ptEnd;
};

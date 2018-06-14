#include "stdafx.h"
#include "Ellipse.h"
#include <iostream>

using namespace std;

IMPLEMENT_SERIAL(CEllipse, CShape, 1)

CEllipse::CEllipse()
{

}

CEllipse::CEllipse(CPoint ptStart,CPoint ptEnd)
:CShape( ptStart, ptEnd)
{
}

void CEllipse::Draw(CDC* pDC)
{
	pDC->Ellipse(m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y);
}

CEllipse::~CEllipse(void)
{
}

#pragma once

#include "Shape.h"

class CEllipse:public CShape
{
public:
	CEllipse(int left,int top,int right,int bottom);
	void Draw();

	~CEllipse(void);
};

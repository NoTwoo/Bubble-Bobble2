#pragma once
#include "CObject.h"

class CPannel : public COject
{
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};
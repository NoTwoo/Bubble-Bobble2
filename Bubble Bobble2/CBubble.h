#pragma once

#include "CObject.h"

class CBubble : public CObject
{
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release() {};

private:
	BYTE m_XImgCnt;
};
#pragma once
#include "CObject.h"

class CObstacle: public CObject
{
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release();

};
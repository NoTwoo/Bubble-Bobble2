#pragma once
#include "CItem.h"

class CFood : public CItem
{
public:
	virtual void Initiallize() {};
	virtual void Update();
	virtual void Render();
	virtual void Release() {};

public:
	const bool& GetIsDrawingPoint() { return m_DrawPoint; }
	void DrawPoint() { m_DrawPoint = true; m_Fall = false; m_Time = GetTickCount(); }
public:
	CFood(const ObjType a_ObjType) { m_ObjType = a_ObjType; }
public:
	virtual void CheckCollision();

private:
	bool m_DrawPoint{ false };
};
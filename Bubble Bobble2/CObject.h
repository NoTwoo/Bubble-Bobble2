#pragma once
#include "enum.h"
#include "macro.h"
class COject
{
public:
	virtual void Initiallize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	const POINT& GetPos() const;
	const RECT& GetRect() const;
	void SetPos(const POINT a_pos);
	void SetRect(const RECT a_rect);

protected:
	ObjType m_ObjType;
	POINT m_pos;
	RECT m_rect;
};
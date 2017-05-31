#pragma once

#include "enum.h"
#include "macro.h"

class CObject
{
public:
	virtual void Initiallize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	const ObjType& GetObjType() const { return m_ObjType; };
	const POINT& GetPos() const { return m_pos; };
	const RECT& GetRect() const { return m_rect; };

public:
	void SetObjType(const ObjType a_ObjType) { m_ObjType = a_ObjType; };
	void SetPos(const POINT a_pos) { m_pos = a_pos; };
	void SetRect(const RECT a_rect) { m_rect = a_rect; };

public:
	//virtual ~CObject() = 0;

protected:
	ObjType m_ObjType;
	POINT m_pos;
	RECT m_rect;
protected:
	DWORD m_Time;
};
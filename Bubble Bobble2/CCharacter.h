#pragma once
#include "CObject.h"
#include <list>
class CCharacter : public CObject
{
public:
	virtual void Move() = 0;
	virtual void MoveRender() = 0;
	virtual void Jump() = 0;
	virtual void JumpRender() = 0;
	virtual const bool CheckCollision(const DIRECTION) = 0;

public:
	//virtual ~CCharacter() = 0;

protected:
	WORD m_Speed;
	BYTE m_MoveImgCnt;
	BYTE m_Direction;
protected:
	DWORD m_JumpTimer;
	BYTE m_JumpImgCnt;
	bool m_IsJumpOn;
	bool m_Drop;

protected:
	std::list<CObject*> m_Obj;
	WORD m_ImgWidth, m_ImgHeight;
};
#pragma once
#include "CObject.h"

class CCharacter : public CObject
{
public:
	virtual void Move() = 0;
	virtual void Attack() = 0;
	virtual void CheckCollision() = 0;

public:
	//virtual ~CCharacter() = 0;

protected:
	WORD m_Speed;
	BYTE m_XCnt, m_YCnt;
};
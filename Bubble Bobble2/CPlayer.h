#pragma once

#include "CCharacter.h"

class CPlayer : public CCharacter
{

public:
	void MoveRender();
	void BubbleRender();

public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release();

public:
	virtual void CheckCollision();
	virtual void Move();
	virtual void Attack();

private:
	BYTE m_AttCnt;
	bool m_IsAttOn;

private:
	DWORD m_BubbleTimer;
public:
	//virtual ~CPlayer();
};
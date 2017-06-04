#pragma once

#include "CCharacter.h"

class CPlayer : public CCharacter
{

public:
	virtual void MoveRender();
	void ShootBubbleRender();
	virtual void JumpRender();

public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	virtual const bool GetDelete() { return false; };

public:
	virtual const bool CheckCollision(const DIRECTION);
	void CheckCollision();
	void CheckPopBubble();
	void CheckDelete();
	virtual void Move();
	void Attack();
	virtual void Jump();

private:
	BYTE m_AttImgCnt;
	bool m_IsAttOn;

private:
	DWORD m_BubbleTimer;
	WORD m_BubbleImgWidth, m_BubbleImgHeight;
public:
	//virtual ~CPlayer();
};
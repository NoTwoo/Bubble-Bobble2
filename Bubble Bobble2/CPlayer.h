#pragma once

#include "CCharacter.h"

class CPlayer : public CCharacter
{

public:
	virtual void MoveRender();
	void ShootBubbleRender();
	virtual void JumpRender();
	void StuckRender();
	void PopRender();
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release();

public:
	virtual void CheckCollision();
	void CheckPopBubble();
	void CheckDelete();
	virtual void Move();
	void Attack();
	virtual void Jump();


private:
	BYTE m_AttImgCnt{};
	BYTE m_StuckImgCnt{};
	BYTE m_PopImgCnt{};
	MOVE_ACTION m_MoveAction;

private:
	DWORD m_BubbleTimer{};
	DWORD m_StuckTimer{};
	WORD m_BubbleImgWidth{}, m_BubbleImgHeight{};

private:
	bool m_IsStuck{ false };
	bool m_IsAttOn{ false };
	bool m_Pop{ false };
private:
	std::list<CObject*> m_Obj;
public:
	//virtual ~CPlayer();
};
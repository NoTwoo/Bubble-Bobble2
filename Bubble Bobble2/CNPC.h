#pragma once
#include "CCharacter.h"

class CNPC : public CCharacter
{
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release();
public:
	virtual void Move() {};
	virtual void MoveRender();
	virtual void Jump() {};
	virtual void JumpRender();
	virtual const bool CheckCollision(const ACTION) { return false; };
	virtual void CheckCollision();

public:
	CNPC(const ObjType a_ObjType);

private:
	CString m_RightMoveJumpStr{}, m_LeftMoveJumpStr{};
	BYTE m_JumpSpeed;
	BYTE m_NumOfImg;
	BYTE m_NumOfMoveImg;
private:
	DWORD m_ActionTime{};
public:
	//virtual ~CNPC() {};
};
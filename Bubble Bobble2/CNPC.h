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
	virtual void JumpRender() {};
	virtual const bool CheckCollision(const DIRECTION) { return false; };
public:
	virtual const bool GetDelete() { return false; }
public:
	CNPC(const ObjType a_Type);

private:
	CString m_MoveJumpStr, m_PopStr;
public:
	//virtual ~CNPC() {};
};
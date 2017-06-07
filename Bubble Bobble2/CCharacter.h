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
	virtual void CheckCollision() = 0;


public:
	//virtual ~CCharacter() = 0;

protected:
	WORD m_Speed{};
	BYTE m_MoveImgCnt{};
	BYTE m_Action{};
protected:
	DWORD m_JumpTimer{};
	BYTE m_JumpImgCnt{};
	bool m_IsJumpOn{ false };
	bool m_Drop{ false };
	WORD m_ImgWidth{}, m_ImgHeight{};
};
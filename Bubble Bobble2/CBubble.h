#pragma once

#include "CObject.h"

class CBubble : public CObject
{
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release() {};
public:
	void SetPop() { m_Pop = true; }
	virtual const bool& GetDelete();

public:
	const POINT& GetOldPos() { return m_OldPos; }

public:
	void CheckCollision();
public:
	CBubble() {};
	CBubble(const BYTE& a_Action) : m_Action(a_Action) {};
private:
	BYTE m_XImgCnt;
	BYTE m_PopImgCnt;
	BYTE m_StuckImgCnt;
private:
	BYTE m_Action;
	WORD m_BubbleImgWidth, m_BubbleImgHeight;
	WORD m_StuckImgWitdth, m_StuckImgHeight;
private:
	bool m_Pop{ false };
	bool m_Catch{ false };
	bool m_Flow{ true };

	POINT m_OldPos{};
	CString m_StuckStr;

private:
	MOVE_ACTION m_MoveAction;
};
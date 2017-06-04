#pragma once

#include "CObject.h"

class CBubble : public CObject
{
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release() {};
	virtual const bool GetDelete();
public:
	void SetPop() { m_Pop = true; }
public:
	CBubble() {};
	CBubble(const BYTE& a_Direction) : m_Direction(a_Direction) {};
private:
	BYTE m_XImgCnt;
	BYTE m_PopImgCnt;
private:
	BYTE m_Direction;
	WORD m_BubbleImgWidth, m_BubbleImgHeight;
private:
	bool m_Pop;
};
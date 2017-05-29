#pragma once

#include "CCharacter.h"

class CPlayer : public CCharacter
{
public:
	virtual void Initiallize();
	virtual void Update();
	virtual void Render();
	virtual void Release();

public:
	virtual void CheckCollision();
	virtual void Move();
	virtual void Attack();

public:
	//virtual ~CPlayer();
};
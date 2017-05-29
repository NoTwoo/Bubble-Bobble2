#pragma once
#include "CCharacter.h"

class CNPC : public CCharacter
{
public:
	virtual void Initiallize() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void Release() {};

public:
	//virtual ~CNPC() {};
};
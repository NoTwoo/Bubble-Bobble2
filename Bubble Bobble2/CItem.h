#pragma once
#include "CObject.h"
class CItem : public CObject
{
public:
	virtual void Initiallize() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void Release() {};

public:
	//virtual ~CItem() {};
};
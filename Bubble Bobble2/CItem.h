#pragma once
#include "CObject.h"
class CItem : public CObject
{
public:
	virtual void Initiallize() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void Release() {};
	virtual const bool GetDelete() { return false; };
public:
	//virtual ~CItem() {};
};
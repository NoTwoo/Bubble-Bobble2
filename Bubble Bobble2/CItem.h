#pragma once
#include "CObject.h"
class CItem : public CObject
{
public:
	virtual void Initiallize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	virtual void CheckCollision() = 0;

public:
	void SetItemType(const ITEM_TYPE a_ItemType) { m_ItemType = a_ItemType; }
protected:
	bool m_Fall{ true };
	ITEM_TYPE m_ItemType;
public:
	//virtual ~CItem() {};
};
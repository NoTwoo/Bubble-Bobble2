#pragma once
#include"CScene.h"

class CGameOver : public CScene
{
public:
	virtual void Initialize() {};
	virtual SCENE_ID Update();
	virtual void Render();
	virtual void Release() {};
	virtual void CheckDelete() {};

public:
	virtual ~CGameOver() {};

};
#pragma once
#include "CScene.h"

class CMenu : public CScene
{
public:
	virtual void Initialize();
	virtual SCENE_ID Update();
	virtual void Render();
	virtual void Release();

public:
	virtual ~CMenu();
};
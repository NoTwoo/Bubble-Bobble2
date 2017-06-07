#pragma once

#include"CScene.h"

class CStage1 : public CScene
{
public:
	virtual void Initialize();
	virtual SCENE_ID Update();
	virtual void Render();
	virtual void Release();
	virtual void CheckDelete();
public:
	void ObstacleInitialize();
	void NPCInitialize();

public:
	virtual ~CStage1();

};
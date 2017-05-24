#pragma once

#include"CScene.h"

class CStage1 : public CScene
{
public:
	virtual void Initialize() {};
	virtual SCENE_ID Update() { return MENU; }
	virtual void Render() {};
	virtual void Release() {};
};
#pragma once

#include <Windows.h>
#include "CScene.h"
class CEnding : public CScene
{
private:
	HWND m_hVideo;
public:
	virtual void Initialize();
	virtual SCENE_ID Update();
	virtual void Render() {};
	virtual void Release();
public:
	CEnding() {};
	virtual ~CEnding();
};




#pragma once

#include <Windows.h>
#include "CScene.h"
class CIntro : public CScene
{
private:
	HWND m_hVideo;
public:
	virtual void Initialize();
	virtual SCENE_ID Update();
	virtual void Render() {};
	virtual void Release();
public:
	CIntro() {};
	virtual ~CIntro();
};




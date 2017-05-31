#pragma once
#include "CScene.h"

class CMenu : public CScene
{

public:
	void ChangeMenuImg();
public:
	virtual void Initialize();
	virtual SCENE_ID Update();
	virtual void Render();
	virtual void Release();

public:
	CMenu();
	virtual ~CMenu();


private:
	//MENUTYPE m_MenuType;
	UINT m_MenuType;
	POINT m_mouse;
	RECT m_MenuRect[NUM_OF_MENU - 1];
};
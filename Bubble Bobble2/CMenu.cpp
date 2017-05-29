#include "global.h"

void CMenu::Initialize()
{

}

SCENE_ID CMenu::Update()
{
	return NOTHING;
}

void CMenu::Render()
{
	BITMAPMANAGER->GetImage()["BackImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);
	GAMEMANAGER->Render();
}

void CMenu::Release()
{

}


CMenu::~CMenu(){ this->Release(); }
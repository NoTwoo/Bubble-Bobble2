#include "global.h"

SCENE_ID CHelp::Update()
{
	if (GetAsyncKeyState(VK_ESCAPE)) return SCENE_ID::MENU;
	return SCENE_ID::NOTHING;

}

void CHelp::Render()
{
	BITMAPMANAGER->GetImage()["HelpImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);
	GAMEMANAGER->Render();
}
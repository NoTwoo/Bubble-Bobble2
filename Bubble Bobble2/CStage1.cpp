#include "global.h"

void CStage1::Initialize()
{
	GAMEMANAGER->GetPlayer().Initiallize();
	SOUNDMANAGER->playsound(SOUNDKIND::SD_1);

}

SCENE_ID CStage1::Update()
{
	GAMEMANAGER->GetPlayer().Update();
	return NOTHING;
}

void CStage1::Render()
{
	BITMAPMANAGER->GetImage()["Stage1BackImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);
	GAMEMANAGER->GetPlayer().Render();
	GAMEMANAGER->Render();
}

void CStage1::Release()
{

}


CStage1::~CStage1() { this->Release(); }
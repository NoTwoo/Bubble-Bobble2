#include "global.h"

void CStage1::ObstacleInitialize()
{
	CFactory<CObstacle> Fact;

	CString name = "MidBlueObstacle";
	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(name, RECT{ 200, 550,
		200 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(name, RECT{ 700, 550,
		700 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(name, RECT{ 200, 330,
		200 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(name, RECT{ 700, 330,
		700 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	name = "ShortBlueObstacle";
	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(name, RECT{ 100, 440,
		100 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		440 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(name, RECT{ 900, 440,
		900 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		440 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	name = "LongBlueObstacle";
	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(name, RECT{ 400, 220,
		400 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

}

void CStage1::NPCInitialize()
{
	CFactory<CNPC> Fact;

	SCENEMANAGER->GetStage1List().push_back(Fact.CreateObj(STAGE1_NPC, POINT{ 500,495 }));
}

void CStage1::Initialize()
{
	GAMEMANAGER->GetPlayer().Initiallize();
	SOUNDMANAGER->playsound(SOUNDKIND::STAGE1BGM);
	this->ObstacleInitialize();
	this->NPCInitialize();
}

SCENE_ID CStage1::Update()
{
	GAMEMANAGER->GetPlayer().Update();
	for (auto d : SCENEMANAGER->GetStage1List()) d->Update();
	return NOTHING;
}

void CStage1::Render()
{
	BITMAPMANAGER->GetImage()["Stage1BackImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);
	for (auto d : SCENEMANAGER->GetStage1List()) d->Render();
	GAMEMANAGER->GetPlayer().Render();
	GAMEMANAGER->Render();
}

void CStage1::Release()
{

}


CStage1::~CStage1() { this->Release(); }
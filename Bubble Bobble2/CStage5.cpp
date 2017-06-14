#include "global.h"

void CStage5::ObstacleInitialize()
{
	CFactory<CObstacle> Fact;

	// RECT{LEFT,TOP,RIGHT,BOTTOM}
	CString name = "MidBlueObstacle";

	// 力老 关 啊款单
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 500, 550,
		500 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	name = "ShortBlueObstacle";

	// 力老 关 力老 哭率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 200, 550,
		200 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));



	// 力老 关 力老 坷弗率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 925, 550,
		925 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));


	name = "LongBlueObstacle";

	// 啊款单

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 400, 440,
		400 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		440 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 400, 330,
		400 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 400, 220,
		400 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	// Rear Obstacle Left
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{ 0,START_OF_TOP,
		END_OF_LEFT, GAMEMANAGER->GetRect().bottom - 20 }));
	// Rear Obstacle Right
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{ END_OF_RIGHT, START_OF_TOP,
		GAMEMANAGER->GetRect().right + END_OF_LEFT, GAMEMANAGER->GetRect().bottom - 15 }));

	// Rear Obstacle Top
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{ 0,START_OF_TOP,
		GAMEMANAGER->GetRect().right - 5, END_OF_TOP }));

	// Rear Obstacle Bottom
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{ 0,665,
		GAMEMANAGER->GetRect().right - 5, END_OF_BOTTOM }));

}



void CStage5::NPCInitialize()
{
	CFactory<CNPC> Fact;

	for (int i = 0; i < NUM_OF_STAGE5_MONSTER_NUM; ++i)
		SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(NPC, POINT{ NPC_START_X, NPC_START_Y }));
}

void CStage5::Initialize()
{
	GAMEMANAGER->GetPlayer()->Initiallize();
	SOUNDMANAGER->playsound(SOUNDKIND::STAGE5BGM);
	this->ObstacleInitialize();
	this->NPCInitialize();
}

void CStage5::CheckDelete()
{
	list<CObject*>::iterator itor = SCENEMANAGER->GetStageList().begin();

	while (itor != SCENEMANAGER->GetStageList().end()) {
		if ((*itor)->GetDelete()) {
			itor = SCENEMANAGER->GetStageList().erase(itor);
		}
		else ++itor;
	}

}

SCENE_ID CStage5::Update()
{

	/*
	if (GAMEMANAGER->IsGameOver()) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		return GAME_OVER;
	}
	*/
	if (SCENEMANAGER->GetNPCNum() == 0) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		GAMEMANAGER->InitGameOver(); GAMEMANAGER->Init();
		return BOSS;
	}

	GAMEMANAGER->GetPlayer()->Update();
	for (auto d : SCENEMANAGER->GetStageList()) d->Update();
	this->CheckDelete();
	return NOTHING;
}

void CStage5::Render()
{
	BITMAPMANAGER->GetImage()["Stage5BackImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);

	SCENEMANAGER->PointRender();

	for (auto d : SCENEMANAGER->GetStageList()) d->Render();

	GAMEMANAGER->GetPlayer()->Render();
	GAMEMANAGER->Render();
}

void CStage5::Release()
{

}


CStage5::~CStage5() { this->Release(); }
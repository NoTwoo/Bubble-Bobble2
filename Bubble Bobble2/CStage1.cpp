#include "global.h"

void CStage1::ObstacleInitialize()
{
	CFactory<CObstacle> Fact;

	CString name = "MidBlueObstacle";
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 200, 550,
		200 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 700, 550,
		700 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 200, 330,
		200 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 700, 330,
		700 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	name = "ShortBlueObstacle";
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 100, 440,
		100 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		440 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 900, 440,
		900 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		440 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	name = "LongBlueObstacle";
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 400, 220,
		400 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	// Rear Obstacle Left
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{ 0,START_OF_TOP,
		END_OF_LEFT, GAMEMANAGER->GetRect().bottom - 20 }));
	// Rear Obstacle Right
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{ END_OF_RIGHT, START_OF_TOP,
		GAMEMANAGER->GetRect().right + END_OF_LEFT, GAMEMANAGER->GetRect().bottom - 15}));

	// Rear Obstacle Top
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{ 0,START_OF_TOP,
		GAMEMANAGER->GetRect().right - 5, END_OF_TOP }));

	// Rear Obstacle Bottom
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(RECT{0,665,
		GAMEMANAGER->GetRect().right - 5, END_OF_BOTTOM }));

}

void CStage1::NPCInitialize()
{
	CFactory<CNPC> Fact;

	//for(int i=0; i < NUM_OF_STAGE1_MONSTER_NUM; ++i)
	//SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(NPC, POINT{ NPC_START_X, NPC_START_Y }));
}

void CStage1::Initialize()
{
	GAMEMANAGER->GetPlayer()->Initiallize();
	SOUNDMANAGER->playsound(SOUNDKIND::STAGE1BGM);
	this->ObstacleInitialize();
	this->NPCInitialize();
}

void CStage1::CheckDelete()
{
	list<CObject*>::iterator itor = SCENEMANAGER->GetStageList().begin();

	while (itor != SCENEMANAGER->GetStageList().end()) {
		if ((*itor)->GetDelete()) {
			itor = SCENEMANAGER->GetStageList().erase(itor);
		}
		else ++itor;
	}

}

SCENE_ID CStage1::Update()
{
	if (GAMEMANAGER->IsGameOver()) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		return GAME_OVER;
	}
	if (SCENEMANAGER->GetNPCNum() == 0) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		return MENU;
	}

	GAMEMANAGER->GetPlayer()->Update();
	for (auto d : SCENEMANAGER->GetStageList()) d->Update();
	this->CheckDelete();
	return NOTHING;
}

void CStage1::Render()
{
	BITMAPMANAGER->GetImage()["Stage1BackImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);
	SCENEMANAGER->PointRender();
	for (auto d : SCENEMANAGER->GetStageList()) d->Render();
	GAMEMANAGER->GetPlayer()->Render();
	GAMEMANAGER->Render();
}

void CStage1::Release()
{

}


CStage1::~CStage1() { this->Release(); }
#include "global.h"

void CStage4::ObstacleInitialize()
{
	CFactory<CObstacle> Fact;

	// RECT{LEFT,TOP,RIGHT,BOTTOM}
	CString name = "MidBlueObstacle";


	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 150, 330,
		150 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));


	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 800, 330,
		800 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));


	name = "ShortBlueObstacle";

	// 力老 关 力老 哭率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 200, 550,
		200 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));



	// 力老 关 力老 坷弗率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 825, 550,
		825 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	// 力老 困 力老 哭率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 100, 220,
		100 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	// 力老 困 力老 坷弗率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 925, 220,
		925 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));


	name = "LongBlueObstacle";

	// 啊款单

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 400, 440,
		400 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		440 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	


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



void CStage4::NPCInitialize()
{
	CFactory<CNPC> Fact;

	for (int i = 0; i < NUM_OF_STAGE4_MONSTER_NUM; ++i)
		SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(NPC, POINT{ NPC_START_X, NPC_START_Y }));
}

void CStage4::Initialize()
{
	GAMEMANAGER->GetPlayer()->Initiallize();
	SOUNDMANAGER->playsound(SOUNDKIND::STAGE4BGM);
	this->ObstacleInitialize();
	this->NPCInitialize();
}

void CStage4::CheckDelete()
{
	list<CObject*>::iterator itor = SCENEMANAGER->GetStageList().begin();

	while (itor != SCENEMANAGER->GetStageList().end()) {
		if ((*itor)->GetDelete()) {
			itor = SCENEMANAGER->GetStageList().erase(itor);
		}
		else ++itor;
	}

}

SCENE_ID CStage4::Update()
{

	if (GAMEMANAGER->IsGameOver()) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		return GAME_OVER;
	}

	if (SCENEMANAGER->GetNPCNum() == 0) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		GAMEMANAGER->InitGameOver(); GAMEMANAGER->Init();
		return STAGE5;
	}

	GAMEMANAGER->GetPlayer()->Update();
	for (auto d : SCENEMANAGER->GetStageList()) d->Update();
	this->CheckDelete();
	return NOTHING;
}

void CStage4::Render()
{
	BITMAPMANAGER->GetImage()["Stage4BackImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);

	SCENEMANAGER->PointRender();

	for (auto d : SCENEMANAGER->GetStageList()) d->Render();

	GAMEMANAGER->GetPlayer()->Render();
	GAMEMANAGER->Render();
}

void CStage4::Release()
{

}


CStage4::~CStage4() { this->Release(); }
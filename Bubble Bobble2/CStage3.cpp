#include "global.h"

void CStage3::ObstacleInitialize()
{
	CFactory<CObstacle> Fact;

	// RECT{LEFT,TOP,RIGHT,BOTTOM}
	CString name = "MidBlueObstacle";

	// 力老 关 啊款单


	// 力老 困 啊款单
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 450, 220,
		450 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 450, 330,
		450 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		330 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));
	name = "ShortBlueObstacle";

	// 力老 关 力老 哭率1 
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 130, 550,
		130 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));
	// 力老 关 力老 哭率2
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 530, 550,
		530 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	// 力老 关 力老 坷弗率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 925, 550,
		925 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		550 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	// 力老 困 力老 哭率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 130, 220,
		130 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	// 力老 困 力老 坷弗率
	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 925, 220,
		925 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		220 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));


	name = "LongBlueObstacle";

	// 啊款单

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 23, 440,
		23 + BITMAPMANAGER->GetImage()[name]->GetWidth(),
		440 + BITMAPMANAGER->GetImage()[name]->GetHeight() }));

	SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(name, RECT{ 767, 440,
		767+ BITMAPMANAGER->GetImage()[name]->GetWidth(),
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



void CStage3::NPCInitialize()
{
	CFactory<CNPC> Fact;

	for (int i = 0; i < NUM_OF_STAGE3_MONSTER_NUM; ++i)
		SCENEMANAGER->GetStageList().push_back(Fact.CreateObj(NPC, POINT{ NPC_START_X, NPC_START_Y }));
}

void CStage3::Initialize()
{
	GAMEMANAGER->GetPlayer()->Initiallize();
	SOUNDMANAGER->playsound(SOUNDKIND::STAGE3BGM);
	this->ObstacleInitialize();
	this->NPCInitialize();
}

void CStage3::CheckDelete()
{
	list<CObject*>::iterator itor = SCENEMANAGER->GetStageList().begin();

	while (itor != SCENEMANAGER->GetStageList().end()) {
		if ((*itor)->GetDelete()) {
			itor = SCENEMANAGER->GetStageList().erase(itor);
		}
		else ++itor;
	}

}

SCENE_ID CStage3::Update()
{

	if (GAMEMANAGER->IsGameOver()) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		return GAME_OVER;
	}

	if (SCENEMANAGER->GetNPCNum() == 0 || (GetAsyncKeyState(VK_LCONTROL) & 0x0001)) {
		GAMEMANAGER->DeletePlayer();
		SCENEMANAGER->GetStageList().clear();
		GAMEMANAGER->InitGameOver(); GAMEMANAGER->Init();
		return STAGE4;
	}

	GAMEMANAGER->GetPlayer()->Update();
	for (auto d : SCENEMANAGER->GetStageList()) d->Update();
	this->CheckDelete();
	return NOTHING;
}

void CStage3::Render()
{
	BITMAPMANAGER->GetImage()["Stage3BackImg"]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);

	SCENEMANAGER->PointRender();

	for (auto d : SCENEMANAGER->GetStageList()) d->Render();

	GAMEMANAGER->GetPlayer()->Render();
	GAMEMANAGER->Render();
}

void CStage3::Release()
{

}


CStage3::~CStage3() { this->Release(); }
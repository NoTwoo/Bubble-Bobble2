#include "global.h"

CSceneManager* CSceneManager::m_instance = nullptr;

CSceneManager::CSceneManager() : m_Scene(nullptr) {}
CSceneManager::~CSceneManager() { this->Release(); }

void  CSceneManager::SetState(const SCENE_ID& a_SceneId)
{
	this->Release();

	switch (a_SceneId){
	case SCENE_ID::INTRO:
		m_Scene = new CIntro; m_SceneID = SCENE_ID::INTRO; break;
	 case SCENE_ID::MENU:
		 m_Scene = new CMenu; m_SceneID = SCENE_ID::MENU; GAMEMANAGER->InitGameOver(); GAMEMANAGER->Init(); break;
	case SCENE_ID::STAGE1:
		m_Scene = new CStage1; m_SceneID = SCENE_ID::STAGE1;  m_NPC_NUM = NUM_OF_STAGE1_MONSTER_NUM; break;
	case SCENE_ID::MENU_HELP:
		m_Scene = new CHelp; m_SceneID = SCENE_ID::MENU_HELP; break;
	case SCENE_ID::GAME_OVER:
		m_Scene = new CGameOver; m_SceneID = SCENE_ID::GAME_OVER; break;
	case SCENE_ID::GAME_EXIT: GAMEMANAGER->GameExit(); return;
	}
	m_Scene->Initialize();

}

void CSceneManager::Update()
{
	SCENE_ID SceneId = SCENE_ID::NOTHING;
	SceneId = m_Scene->Update();

	if (SceneId > SCENE_ID::NOTHING){
		this->SetState(SceneId);
		return;
	}

}

void CSceneManager::PointRender()
{
	TextOut(GAMEMANAGER->GetMemDC(), 
		END_OF_RIGHT / 2, START_OF_TOP / 2, 
		GAMEMANAGER->GetPoint(), 
		GAMEMANAGER->GetPoint().GetLength());
}
void CSceneManager::Render() { if (m_Scene)  m_Scene->Render(); }

void CSceneManager::Release() { SAFE_DELETE(m_Scene); }
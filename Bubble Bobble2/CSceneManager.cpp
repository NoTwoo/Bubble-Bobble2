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
		 m_Scene = new CMenu; m_SceneID = SCENE_ID::MENU; break;
	case SCENE_ID::STAGE1:
		m_Scene = new CStage1; m_SceneID = SCENE_ID::STAGE1; break;
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


void CSceneManager::Render() {  if(m_Scene) m_Scene->Render();  }

void CSceneManager::Release() { SAFE_DELETE(m_Scene); }
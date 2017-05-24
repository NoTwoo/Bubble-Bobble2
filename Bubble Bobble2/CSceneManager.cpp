#include "global.h"

CSceneManager* CSceneManager::m_instance = nullptr;

CSceneManager::CSceneManager() : m_Scene(nullptr) {}
CSceneManager::~CSceneManager() { this->Release(); }

void  CSceneManager::SetState(const SCENE_ID& a_SceneId)
{
	this->Release();

	switch (a_SceneId){
	case INTRO:
		m_Scene = new CIntro;
		break;

	case STAGE1:
		m_Scene = new CStage1;
		break;
	}

	m_Scene->Initialize();

}

void CSceneManager::Update()
{
	SCENE_ID SceneId = NOTHING;
	SceneId = m_Scene->Update();

	if (SceneId > NOTHING){
		this->SetState(SceneId);
		return;
	}
}


void CSceneManager::Render(){ m_Scene->Render(); }

void CSceneManager::Release() { SAFE_DELETE(m_Scene); }
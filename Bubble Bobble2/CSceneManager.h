#pragma once

#include "CScene.h"

class CSceneManager
{
public:
	static CSceneManager* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new CSceneManager;

		return m_instance;
	}
public:
	void SetState(const SCENE_ID&);
	void Update();
	void Render();
	void Release();

public:
	void PointRender();
	void DecreaseNPCNum() { --m_NPC_NUM; }
	const BYTE& GetNPCNum() { return m_NPC_NUM; }
public:
	std::list<CObject*>& GetStageList() { return m_StageList; }
	const SCENE_ID& GetStage() { return m_SceneID; }
private:
	CSceneManager();
	~CSceneManager();
	CSceneManager(const CSceneManager&) = delete;
	void operator=(const CSceneManager&) = delete;

	static CSceneManager* m_instance;

private:
	CScene* m_Scene;
	SCENE_ID m_SceneID;

private:
	BYTE m_NPC_NUM;
private:
	std::list<CObject*> m_StageList;
};
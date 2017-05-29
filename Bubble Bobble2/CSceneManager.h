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


private:
	CSceneManager();
	~CSceneManager();
	CSceneManager(const CSceneManager&) = delete;
	void operator=(const CSceneManager&) = delete;

	static CSceneManager* m_instance;

private:
	CScene* m_Scene;
	SCENE_ID m_SceneID;
};
#pragma once

class CSceneManager
{
public:
	static CSceneManager* GetInstance() {}
public:
	void Initiallize();
	void Update();
	void Render();
	void Release();
private:
	CSceneManager() {};
	CSceneManager(const CSceneManager&) = delete;
	void operator=(const CSceneManager&) = delete;

	static CSceneManager* m_instance;
};
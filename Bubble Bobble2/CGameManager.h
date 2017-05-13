#pragma once

class CGameManager
{
public:
	static CGameManager* GetInstance();

public:
	void Initiallize() {};
	void Update() {};
	void Render() {};
	void Release() {};
private:
	CGameManager() {};
	CGameManager(const CGameManager&) = delete;
	void operator=(const CGameManager&) = delete;

	static CGameManager* m_instance;
};
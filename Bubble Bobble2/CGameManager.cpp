#include "global.h"

CGameManager* CGameManager::m_instance = nullptr;

CGameManager* CGameManager::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new CGameManager();
	return m_instance;
}
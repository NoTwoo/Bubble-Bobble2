#include "global.h"

CGameManager* CGameManager::m_instance = nullptr;

void  CGameManager::Initiallize(const HWND& a_hWnd)
{ 
	m_hWnd = a_hWnd; 
	BITMAPMANAGER->Initiallize();
	SCENEMANAGER->SetState(INTRO);
}

void CGameManager::Update(){ SCENEMANAGER->Update(); }
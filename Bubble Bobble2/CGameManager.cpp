#include "global.h"

#pragma comment(linker , "/entry:WinMainCRTStartup /subsystem:console")

CGameManager* CGameManager::m_instance = nullptr;

void  CGameManager::Initiallize(const HWND& a_hWnd)
{ 
	m_hWnd = a_hWnd; 
	m_hDC = GetDC(m_hWnd);
	m_hBit = CreateCompatibleBitmap(m_hDC, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	m_hMemDC = CreateCompatibleDC(m_hDC);

	GetClientRect(m_hWnd, &m_Rect);
	m_Rect.left = 10, m_Rect.right = m_Rect.right - 20, m_Rect.top = 40, m_Rect.bottom = m_Rect.bottom - 25;

	BITMAPMANAGER->Initiallize();
	SOUNDMANAGER->Initialize();
	SCENEMANAGER->SetState(INTRO);
}

void CGameManager::Update() { SCENEMANAGER->Update(); SCENEMANAGER->Render();
}

void CGameManager::Render()
{
	m_hOldBit = (HBITMAP)SelectObject(m_hMemDC, m_hBit);
	BitBlt(m_hDC, 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, m_hMemDC, 0, 0, SRCCOPY);
}
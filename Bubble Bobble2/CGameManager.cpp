#include "global.h"

#pragma comment(linker , "/entry:WinMainCRTStartup /subsystem:console")

CGameManager* CGameManager::m_instance = nullptr;

void  CGameManager::Initiallize(const HWND& a_hWnd)
{ 
	m_hWnd = a_hWnd; 
	m_hDC = GetDC(m_hWnd);
	m_hBit = CreateCompatibleBitmap(m_hDC, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	m_hMemDC = CreateCompatibleDC(m_hDC);

	SetBkColor(m_hMemDC, RGB(0, 0, 0));
	SetTextColor(m_hMemDC, RGB(255, 0, 0));
	m_PointStr.Format("Score: %d", m_Point);

	GetClientRect(m_hWnd, &m_Rect);
	m_Rect.left = 10, m_Rect.right = m_Rect.right - 20, m_Rect.top = 40, m_Rect.bottom = m_Rect.bottom - 25;
	BITMAPMANAGER->Initiallize();
	SOUNDMANAGER->Initialize();
	SCENEMANAGER->SetState(INTRO);

	srand((unsigned)time(NULL));

	m_Player = new CPlayer;

}

void CGameManager::Update() { SCENEMANAGER->Update(); SCENEMANAGER->Render();
}

void CGameManager::Render()
{
	m_hOldBit = (HBITMAP)SelectObject(m_hMemDC, m_hBit);
	BitBlt(m_hDC, 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, m_hMemDC, 0, 0, SRCCOPY);
}
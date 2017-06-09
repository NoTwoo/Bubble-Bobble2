#pragma once

#include "CPlayer.h"

class CGameManager
{
public:
	static CGameManager* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new CGameManager;

		return m_instance;
	}

public:
	void Initiallize(const HWND& a_hWnd);
	void Update();
	void Render();
	void Release() {};
public:
	const HDC& GetMemDC() { return m_hMemDC; }
	const HWND& GethWnd() { return m_hWnd; }
	const RECT& GetRect() { return m_Rect; }
	CPlayer* GetPlayer() { return m_Player; }
public:
	void SethWnd(HWND m_hWnd) { this->m_hWnd = m_hWnd; }

public:
	void AddPoint(DWORD a_Point) { m_Point += a_Point;  m_PointStr.Format("Score: %d", m_Point); }
	const CString& GetPoint() { return m_PointStr; }
public:
	void InitGameOver() { if (m_IsGameOver) { m_IsGameOver = false; this->Init(); } }
	void Init() { if (!m_Player) m_Player = new CPlayer; if(m_IsGameOver) m_Point = 0; m_PointStr.Format("Score: %d", m_Point);}
	const bool& IsGameOver() { return m_IsGameOver; }
	void GameOver() { if (!m_IsGameOver) m_IsGameOver = true; }
	void DeletePlayer() { SAFE_DELETE(m_Player); }
	void GameExit() { PostQuitMessage(0); }
private:
	HDC m_hDC, m_hMemDC;
	HBITMAP m_hBit, m_hOldBit;
	HWND m_hWnd;
	RECT m_Rect;
private:
	CGameManager() {};
	CGameManager(const CGameManager&) = delete;
	void operator=(const CGameManager&) = delete;

	static CGameManager* m_instance;

private:
	CPlayer* m_Player;
	DWORD m_Point{};
	CString m_PointStr;

private:
	bool m_IsGameOver{ false };
};
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
	///Get
	const HDC& GetMemDC() { return m_hMemDC; }
	const HWND& GethWnd() { return m_hWnd; }
	const RECT& GetRect() { return m_Rect; }
	CPlayer& GetPlayer() { return m_Player; }
public:
	void SethWnd(HWND m_hWnd) { this->m_hWnd = m_hWnd; }
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
	CPlayer m_Player;
};
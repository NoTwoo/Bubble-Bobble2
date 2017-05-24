#pragma once

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
	void Render() {};
	void Release() {};
public:
	///Get
	const HDC& GetMemDC() { return m_hMemDC; }
	const HWND& GethWnd() { return m_hWnd; }
	void SethWnd(HWND m_hWnd) { this->m_hWnd = m_hWnd; }
private:
	HDC m_hDC, m_hMemDC;
	HWND m_hWnd;

private:
	CGameManager() {};
	CGameManager(const CGameManager&) = delete;
	void operator=(const CGameManager&) = delete;

	static CGameManager* m_instance;
};
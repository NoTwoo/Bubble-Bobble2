#pragma once

class CBitmapManager
{
public:
	static CDBManager* GetInstance() {}
public:
	void Initiallize();
	void Update();
	void Render();
	void Release();
private:
	CBitmapManager() {};
	CBitmapManager(const CBitmapManager&) = delete;
	void operator=(const CBitmapManager&) = delete;

	static CBitmapManager* m_instance;
};
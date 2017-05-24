#pragma once

class CDBManager
{
public:
	static CDBManager* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new CDBManager;

		return m_instance;
	}
public:
	void Initiallize();
	void Update();
	void Render();
	void Release();
private:
	CDBManager() {};
	CDBManager(const CDBManager&) = delete;
	void operator=(const CDBManager&) = delete;

	static CDBManager* m_instance;
};
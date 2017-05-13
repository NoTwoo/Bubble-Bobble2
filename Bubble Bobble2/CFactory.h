#pragma once
class CFactory
{
public:
	static CFactory* GetInstance() {}
public:
	void Initiallize();
	void Update();
	void Render();
	void Release();
private:
	CFactory() {};
	CFactory(const CFactory&) = delete;
	void operator=(const CFactory&) = delete;

	static CFactory* m_instance;
};
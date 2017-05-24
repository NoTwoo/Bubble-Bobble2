#pragma once

class CObject;

template <typename T>
class CFactory
{
public:
	static CObject* CreateObj(void)
	{
		CObject* pObj = new T;
		pObj->Initialize();
		return pObj;
	}

	static CObject* CreateObj(float _fx, float _fy)
	{
		CObject* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fx, _fy);
		return pObj;
	}

public:
	CFactory(void);
	~CFactory(void);
};

/*
class CFactory
{
public:
	static CFactory* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new CFactory;

		return m_instance;
	}
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
*/
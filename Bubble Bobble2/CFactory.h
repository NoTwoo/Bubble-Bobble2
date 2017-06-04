#pragma once

class CObject;

template <typename T>
class CFactory
{
public:
	static CObject* CreateObj(void)
	{
		CObject* pObj = new T;
		pObj->Initiallize();
		return pObj;
	}
	// Obstacle
	static CObject* CreateObj(CString a_name, const RECT a_rect)
	{
		CObject* pObj = new T;
		pObj->Initiallize();
		pObj->SetName(a_name);
		pObj->SetRect(a_rect);
		pObj->SetPos(POINT{ a_rect.left, a_rect.top });
		return pObj;
	}
	// Bubble
	static CObject* CreateObj(const BYTE a_Direction, const RECT a_rect)
	{
		CObject* pObj = new T{ a_Direction };
		pObj->Initiallize();
		pObj->SetRect(a_rect);
		pObj->SetPos(POINT{ a_rect.left, a_rect.top });
		return pObj;
	}
	// NPC
	static CObject* CreateObj(const ObjType a_Type, const POINT a_pos)
	{
		CObject* pObj = new T{ a_Type };
		pObj->SetPos(POINT{ a_pos.x, a_pos.y });
		pObj->Initiallize();
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
	CFactory(void) {};
	~CFactory(void) {};
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
#pragma once

#include <atlimage.h>
#include <map>
#include<string>
#include <atlstr.h>
class CBitmapManager
{
public:
	static CBitmapManager* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new CBitmapManager;

		return m_instance;
	}
public:
	void LoadMenuImg();
	void LoadBackImg();
	void LoadBubbleImg();
	void LoadPlayerImg();
	void LoadNPCImg();
	void LoadItemImg();
	void LoadEffectImg();
public:
	void Initiallize();
	void Update();
	void Render();
	void Release();
public:
	std::map<CString, CImage*>& GetImage();
private:
	std::map<CString, CImage*> m_map;

private:
	CBitmapManager() {};
	~CBitmapManager();
	CBitmapManager(const CBitmapManager&) = delete;
	void operator=(const CBitmapManager&) = delete;

	static CBitmapManager* m_instance;
};
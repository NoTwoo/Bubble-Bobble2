#include "global.h"

CBitmapManager* CBitmapManager::m_instance = nullptr;

void CBitmapManager::Initiallize()
{
	for (int i = 0; i < NUM_OF_STAGE; ++i) {
		CImage*  tempImg = new CImage;
		CString str;
		CString Key;
		Key.Format("Stage%dBackImg", i + 1);
		str.Format("Resources\\Images\\Stage\\Stage%dBackImg.png",i + 1);
		tempImg->Load(str);
		m_map.insert(make_pair(Key,tempImg));
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Stage\\BlueObstacle.png");
		m_map.insert(make_pair("BlueObstacle", tempImg));
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Player\\PlayerMove.png");
		m_map.insert(make_pair("PlayerMove", tempImg));

	}

	{
		for (int i = 0; i < NUM_OF_MENU; ++i) {
			CImage* tempImg = new CImage;
			CString str;
			CString Key;
			Key.Format("Menu%dImg", i + 1);
			str.Format("Resources\\Images\\Menu\\Menu%dImg.png", i + 1);
			tempImg->Load(str);
			m_map.insert(make_pair(Key, tempImg));

		}
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Player\\Attack\\BubbleMoveImg.png");
		m_map.insert(make_pair("BubbleMoveImg", tempImg));


	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Player\\Attack\\PlayerShootBubbleImg.png");
		m_map.insert(make_pair("PlayerShootBubbleImg", tempImg));


	}

}
void CBitmapManager::Update()
{
}

void CBitmapManager::Render()
{
}

void CBitmapManager::Release() { for (auto d : m_map) delete d.second; }

CBitmapManager::~CBitmapManager() { this->Release(); }

std::map<CString, CImage*>& CBitmapManager::GetImage(){ return m_map; }
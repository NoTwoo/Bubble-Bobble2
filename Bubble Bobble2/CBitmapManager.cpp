#include "global.h"

CBitmapManager* CBitmapManager::m_instance = nullptr;

void CBitmapManager::Initiallize()
{
	for (int i = 0; i < NUM_OF_STAGE; ++i) {
		CImage*  tempImg = new CImage;
		CString str;
		CString Key;
		Key.Format("Stage%dBackImg", i + 1);
		str.Format("Resources\\Images\\Stage\\BackGround\\Stage%dBackImg.png",i + 1);
		tempImg->Load(str);
		m_map.insert(make_pair(Key,tempImg));
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Stage\\Obstacle\\LongBlueObstacle.png");
		m_map.insert(make_pair("LongBlueObstacle", tempImg));
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Stage\\Obstacle\\MidBlueObstacle.png");
		m_map.insert(make_pair("MidBlueObstacle", tempImg));
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Stage\\Obstacle\\ShortBlueObstacle.png");
		m_map.insert(make_pair("ShortBlueObstacle", tempImg));
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
		tempImg->Load("Resources\\Images\\Player\\Attack\\BubblePopImg.png");
		m_map.insert(make_pair("BubblePopImg", tempImg));


	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Player\\Attack\\PlayerShootBubbleToRightImg.png");
		m_map.insert(make_pair("PlayerShootBubbleToRightImg", tempImg));

	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Player\\Attack\\PlayerShootBubbleToLeftImg.png");
		m_map.insert(make_pair("PlayerShootBubbleToLeftImg", tempImg));

	}



	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Player\\MoveAndJump\\PlayerMoveAndJumpToRightImg.png");
		m_map.insert(make_pair("PlayerMoveAndJumpToRightImg", tempImg));
	}
	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Player\\MoveAndJump\\PlayerMoveAndJumpToLeftImg.png");
		m_map.insert(make_pair("PlayerMoveAndJumpToLeftImg", tempImg));
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Stage\\NPC\\Stage1NPCMoveAndJumpImg.png");
		m_map.insert(make_pair("Stage1NPCMoveAndJumpImg", tempImg));
	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Stage\\NPC\\Stage1NPCPopImg.png");
		m_map.insert(make_pair("Stage1NPCPopImg", tempImg));
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
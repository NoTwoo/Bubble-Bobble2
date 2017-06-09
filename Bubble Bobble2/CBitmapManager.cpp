#include "global.h"

CBitmapManager* CBitmapManager::m_instance = nullptr;


void CBitmapManager::LoadMenuImg()
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

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Menu\\HelpImg.png");
		m_map.insert(make_pair("HelpImg", tempImg));

	}

	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\GameOver\\GameOverImg.png");
		m_map.insert(make_pair("GameOverImg", tempImg));
	}
}

void CBitmapManager::LoadBackImg()
{
	for (int i = 0; i < NUM_OF_STAGE; ++i) {
		CImage*  tempImg = new CImage;
		CString str;
		CString Key;
		Key.Format("Stage%dBackImg", i + 1);
		str.Format("Resources\\Images\\Stage\\BackGround\\Stage%dBackImg.png", i + 1);
		tempImg->Load(str);
		m_map.insert(make_pair(Key, tempImg));
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

}

void CBitmapManager::LoadBubbleImg()
{
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

}

void CBitmapManager::LoadPlayerImg()
{

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
		tempImg->Load("Resources\\Images\\Player\\Stuck\\PlayerStuckImg.png");
		m_map.insert(make_pair("PlayerStuckImg", tempImg));

	}

}

void CBitmapManager::LoadNPCImg()
{
	
	for (int i = 0; i < NUM_OF_STAGE; ++i) {
		CImage*  tempImg = new CImage;
		CString str;
		CString Key;
		Key.Format("Stage%dNPCRightMoveAndJumpImg", i + 1);
		str.Format("Resources\\Images\\Stage\\NPC\\Stage%dNPCRightMoveAndJumpImg.png", i + 1);
		tempImg->Load(str);
		m_map.insert(make_pair(Key, tempImg));
	}
	
	for (int i = 0; i < NUM_OF_STAGE; ++i) {
		CImage*  tempImg = new CImage;
		CString str;
		CString Key;
		Key.Format("Stage%dNPCLeftMoveAndJumpImg", i + 1);
		str.Format("Resources\\Images\\Stage\\NPC\\Stage%dNPCLeftMoveAndJumpImg.png", i + 1);
		tempImg->Load(str);
		m_map.insert(make_pair(Key, tempImg));
	}

	for (int i = 0; i < NUM_OF_STAGE; ++i) {
		CImage*  tempImg = new CImage;
		CString str;
		CString Key;
		Key.Format("Stage%dNPCStuckImg", i + 1);
		str.Format("Resources\\Images\\Stage\\NPC\\Stage%dNPCStuckImg.png", i + 1);
		tempImg->Load(str);
		m_map.insert(make_pair(Key, tempImg));
	}

}

void CBitmapManager::LoadItemImg()
{
	for (int i = 0; i < NUM_OF_FOOD_IMG; ++i) {
		CImage*  tempImg = new CImage;
		CString str;
		CString Key;
		Key.Format("FoodItem%dImg", i + 1);
		str.Format("Resources\\Images\\Stage\\Item\\FoodItem%dImg.png", i + 1);
		tempImg->Load(str);
		m_map.insert(make_pair(Key, tempImg));
	}

}

void CBitmapManager::LoadEffectImg()
{
	{
		CImage* tempImg = new CImage;
		tempImg->Load("Resources\\Images\\Stage\\Point\\PointImg.png");
		m_map.insert(make_pair("PointImg", tempImg));
	}
}

void CBitmapManager::Initiallize()
{
	this->LoadMenuImg();
	this->LoadBackImg();
	this->LoadBubbleImg();
	this->LoadPlayerImg();
	this->LoadNPCImg();
	this->LoadItemImg();
	this->LoadEffectImg();
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
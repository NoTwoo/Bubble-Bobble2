#include "global.h"

void CBubble::Initiallize()
{

	m_XImgCnt = 0;
	m_ObjType = PLAYER_BUBBLE;
	m_Time = GetTickCount();

}


void CBubble::Update()
{
	if (m_Time + 100 < GetTickCount()) 
		if (m_XImgCnt < NUM_OF_PLAYER_BUBBLE_MOVE_IMG) {
			m_XImgCnt++;
			m_pos.x += SPEED;
			m_Time = GetTickCount(); 
		}

}

void CBubble::Render()
{
	BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetWidth() / NUM_OF_PLAYER_BUBBLE_MOVE_IMG,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetHeight(),
		(BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetWidth() / NUM_OF_PLAYER_BUBBLE_MOVE_IMG) * m_XImgCnt,
		0,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetWidth() / NUM_OF_PLAYER_BUBBLE_MOVE_IMG,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetHeight(), RGB(0, 0, 0));

}
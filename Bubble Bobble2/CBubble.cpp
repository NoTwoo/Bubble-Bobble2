#include "global.h"

void CBubble::Initiallize()
{

	m_XImgCnt = 0;
	m_PopImgCnt = 0;
	m_ObjType = BUBBLE;
	m_Time = GetTickCount();
	m_Pop = false;

	m_BubbleImgWidth = BITMAPMANAGER->GetImage()["BubbleMoveImg"]->GetWidth() / NUM_OF_PLAYER_BUBBLE_MOVE_IMG;
	m_BubbleImgHeight = BITMAPMANAGER->GetImage()["BubbleMoveImg"]->GetHeight();
}


void CBubble::Update()
{
	if (m_Time + 100 < GetTickCount()) {
		if (!m_Pop) {
			if (m_XImgCnt != NUM_OF_PLAYER_BUBBLE_MOVE_IMG - 1) {
				m_XImgCnt++;
				if (m_Direction == DIRECTION::RIGHT) {
					if ((m_pos.x + m_BubbleImgWidth + SPEED) < GAMEMANAGER->GetRect().right) m_pos.x += SPEED;
				}
				else {
					if ((m_pos.x - SPEED) > GAMEMANAGER->GetRect().left) m_pos.x -= SPEED;
				}
			}
			else {
				if (m_pos.y > 500 - SPEED) m_pos.y -= SPEED;
			}
			m_Time = GetTickCount();

			m_rect.left = m_pos.x;
			m_rect.right = m_rect.left + m_BubbleImgWidth;
			m_rect.top = m_pos.y;
			m_rect.bottom = m_rect.top + m_BubbleImgHeight;
		}
		else ++m_PopImgCnt;
	}

}

void CBubble::Render()
{
	if(!m_Pop)
	BITMAPMANAGER->GetImage()["BubbleMoveImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		m_BubbleImgWidth,
		m_BubbleImgHeight,
		m_BubbleImgWidth * m_XImgCnt,
		0,
		m_BubbleImgWidth,
		m_BubbleImgHeight, RGB(147, 187, 236));
	else
		BITMAPMANAGER->GetImage()["BubblePopImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetWidth() / NUM_OF_BUBBLE_POP_IMG,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetHeight(),
			(BITMAPMANAGER->GetImage()["BubblePopImg"]->GetWidth() / NUM_OF_BUBBLE_POP_IMG) * m_PopImgCnt,
			0,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetWidth() / NUM_OF_BUBBLE_POP_IMG,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetHeight(), RGB(147, 187, 236));
}


const bool CBubble::GetDelete()
{
	if (m_PopImgCnt > NUM_OF_BUBBLE_POP_IMG) return true;
	
	return false;

}
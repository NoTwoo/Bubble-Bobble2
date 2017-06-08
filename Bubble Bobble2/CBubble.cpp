#include "global.h"

void CBubble::Initiallize()
{

	m_XImgCnt = 0;
	m_PopImgCnt = 0;
	m_StuckImgCnt = 0;
	m_ObjType = BUBBLE;
	m_Time = GetTickCount();

	m_BubbleImgWidth = BITMAPMANAGER->GetImage()["BubbleMoveImg"]->GetWidth() / NUM_OF_PLAYER_BUBBLE_MOVE_IMG;
	m_BubbleImgHeight = BITMAPMANAGER->GetImage()["BubbleMoveImg"]->GetHeight();

	m_OldPos = m_pos;
	m_MoveAction = UP;

	switch (SCENEMANAGER->GetStage()) {
	case STAGE1: m_StuckStr = "Stage1NPCStuckImg"; break;
	}
}

void CBubble::CheckCollision()
{
	RECT tempRect;
	if (m_Catch) {
		m_rect.left = m_pos.x;
		m_rect.right = (m_rect.left + m_StuckImgWitdth);
		m_rect.top = m_pos.y;
		m_rect.bottom = (m_rect.top + m_StuckImgHeight);
	}

	else {
		m_rect.left = m_pos.x;
		m_rect.right = (m_rect.left + m_BubbleImgWidth);
		m_rect.top = m_pos.y;
		m_rect.bottom = (m_rect.top + m_BubbleImgHeight);
	}
	RECT BubbleTempRect = m_rect;
	//BubbleTempRect.top -= 10;
	for (auto d : SCENEMANAGER->GetStageList()) {

		if (IntersectRect(&tempRect, &BubbleTempRect, &d->GetRect())) {
			if (m_Flow) {
				if (d->GetObjType() == OBSTACLE || d->GetObjType() == REAR_OBSTACLE) {
					::SetRect(&tempRect, 0, 0, tempRect.right - tempRect.left, tempRect.bottom - tempRect.top);
					if (tempRect.right >= tempRect.bottom) {
						if (m_pos.y >= d->GetPos().y) m_Flow = false;
					}
				}

			}
			if (m_Catch) {
				if (d->GetObjType() != NPC) {
					::SetRect(&tempRect, 0, 0, tempRect.right - tempRect.left, tempRect.bottom - tempRect.top);

					if (tempRect.right <= tempRect.bottom) // 충돌한게 높이가 크다면(==옆에서충돌)
					{
						if (m_pos.x < d->GetPos().x) { m_MoveAction = LEFT; m_pos.x -= SPEED; }
						else m_MoveAction = RIGHT;
					}

					else  // 위아래에서 충돌했을 경우,
					{
						if (m_pos.y >= d->GetPos().y) // 박스의 밑으로 충돌
						{
							if (d->GetPos().y != START_OF_TOP) {
								if (m_Action == ACTION::MOVE_RIGHT) m_MoveAction = RIGHT;
								else m_MoveAction = LEFT;
							}
							else m_MoveAction = DOWN;

						}
						else  // 박스의 위로 충돌
						{
							m_MoveAction = UP;
						}
					}
				}
			}
			if (d->GetObjType() == NPC && m_OldPos.y == m_pos.y && m_Flow) {
				CNPC* pNPC = reinterpret_cast<CNPC*>(d);
				if (!m_Catch && pNPC->GetPos().y == pNPC->GetPos().y) {
					m_Catch = true;
					m_XImgCnt = NUM_OF_PLAYER_BUBBLE_MOVE_IMG - 1;
					m_StuckImgWitdth = BITMAPMANAGER->GetImage()[m_StuckStr]->GetWidth() / NUM_OF_MONSTER_STUCK_IMG;
					m_StuckImgHeight = BITMAPMANAGER->GetImage()[m_StuckStr]->GetHeight();
					pNPC->DeleteMe();
					return;
				}
			}
		}
	}

}

void CBubble::Update()
{
	CheckCollision();

	if (m_Time + 100 < GetTickCount()) {
		if (!m_Pop && !m_Catch) {
			if (m_XImgCnt != NUM_OF_PLAYER_BUBBLE_MOVE_IMG - 1) {
				m_XImgCnt++;
				if (m_Action == ACTION::MOVE_RIGHT) {
					if ((m_pos.x + m_BubbleImgWidth + SPEED) < GAMEMANAGER->GetRect().right) m_pos.x += SPEED;
				}
				else {
					if ((m_pos.x - SPEED) > GAMEMANAGER->GetRect().left) m_pos.x -= SPEED;
				}
			}
			else {
				if (m_Flow) m_pos.y -= SPEED;
			}
		}
		if(m_Pop) ++m_PopImgCnt;

		if (m_Catch) {
			switch (m_MoveAction) {
			case LEFT: m_pos.x -= SPEED; break;
			case RIGHT: m_pos.x += SPEED; break;
			case UP: m_pos.y -= SPEED; break;
			case DOWN: m_pos.y += SPEED; break;
			}
			++m_StuckImgCnt; m_StuckImgCnt %= NUM_OF_MONSTER_STUCK_IMG;
			m_Time = GetTickCount();
		}

		m_Time = GetTickCount();
	}

}

void CBubble::Render()
{
	if(!m_Pop && !m_Catch)
	BITMAPMANAGER->GetImage()["BubbleMoveImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		m_BubbleImgWidth,
		m_BubbleImgHeight,
		m_BubbleImgWidth * m_XImgCnt,
		0,
		m_BubbleImgWidth,
		m_BubbleImgHeight, RGB(147, 187, 236));
	else if(m_Pop)
		BITMAPMANAGER->GetImage()["BubblePopImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetWidth() / NUM_OF_BUBBLE_POP_IMG,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetHeight(),
			(BITMAPMANAGER->GetImage()["BubblePopImg"]->GetWidth() / NUM_OF_BUBBLE_POP_IMG) * m_PopImgCnt,
			0,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetWidth() / NUM_OF_BUBBLE_POP_IMG,
			BITMAPMANAGER->GetImage()["BubblePopImg"]->GetHeight(), RGB(147, 187, 236));

	else if(m_Catch)
		BITMAPMANAGER->GetImage()[m_StuckStr]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_StuckImgWitdth,
			m_StuckImgHeight,
			m_StuckImgWitdth * m_StuckImgCnt,
			0,
			m_StuckImgWitdth,
			m_StuckImgHeight, RGB(147, 187, 236));
}


const bool& CBubble::GetDelete()
{

	if (m_PopImgCnt > NUM_OF_BUBBLE_POP_IMG) {
		if (m_Catch) {
			CFactory<CFood> fact;
			SCENEMANAGER->GetStageList().push_back(fact.CreateObj(ITEM, BANANA, "FoodItem1Img", m_rect));
			SCENEMANAGER->DecreaseNPCNum();
		}
		return true;
	}
	return false;

}
#include "global.h"

CNPC::CNPC(const ObjType a_ObjType)
{ 
	m_ObjType = a_ObjType;
	switch (SCENEMANAGER->GetStage()) {
	case STAGE1: m_name = "Stage1"; m_NumOfImg = NUM_OF_STAGE1_MONSTER_MOVE_JUMP_IMG;
		m_NumOfMoveImg = NUM_OF_STAGE1_MONSTER_MOVE_IMG; break;
	case STAGE2: m_name = "Stage1"; m_NumOfImg = NUM_OF_STAGE1_MONSTER_MOVE_JUMP_IMG;
		m_NumOfMoveImg = NUM_OF_STAGE1_MONSTER_MOVE_IMG; break;
	}

}

void CNPC::Initiallize()
{
	m_RightMoveJumpStr = m_name; m_RightMoveJumpStr.Append("NPCRightMoveAndJumpImg");
	m_LeftMoveJumpStr = m_name; m_LeftMoveJumpStr.Append("NPCLeftMoveAndJumpImg");

	m_ImgWidth = BITMAPMANAGER->GetImage()[m_RightMoveJumpStr]->GetWidth() / m_NumOfImg;
	m_ImgHeight = BITMAPMANAGER->GetImage()[m_RightMoveJumpStr]->GetHeight();

	m_rect.left = m_pos.x; m_rect.top = m_pos.y;
	m_rect.right = m_rect.left + m_ImgWidth;
	m_rect.bottom = m_rect.top + m_ImgHeight;

	m_Action = ACTION::MOVE_RIGHT;

	m_ActionTime = GetTickCount();
	m_Time = GetTickCount();
	m_Speed = NPC_SPEED;
	m_JumpSpeed = NPC_JUMP_SPEED;
}

void CNPC::CheckCollision()
{
	if (!m_IsJumpOn &&  m_pos.y < GAMEMANAGER->GetRect().bottom - m_ImgHeight)
		m_Drop = true;

	if (!m_IsJumpOn && m_Drop && m_pos.y < (GAMEMANAGER->GetRect().bottom - m_ImgHeight)) {
		m_pos.y += 1;
	}
	if (m_pos.x < END_OF_LEFT || m_pos.x > END_OF_RIGHT || m_pos.y < START_OF_TOP) {
		m_pos.x = NPC_START_X; m_pos.y = NPC_START_Y;
	}

	RECT tempRect;
	m_rect.left = m_pos.x;
	m_rect.right = (m_rect.left + m_ImgWidth);
	m_rect.top = m_pos.y;
	m_rect.bottom = (m_rect.top + m_ImgHeight) - 10;

	
	for (auto d : SCENEMANAGER->GetStageList()) {
		if (d != this && d->GetObjType() != ITEM) {
			RECT CopyRect;
			CopyRect = m_rect;
			if (d->GetObjType() == REAR_OBSTACLE) CopyRect.bottom += 10;
				if (IntersectRect(&tempRect, &CopyRect, &d->GetRect())) {

				::SetRect(&tempRect, 0, 0, tempRect.right - tempRect.left, tempRect.bottom - tempRect.top);


				if (tempRect.right <= tempRect.bottom) // 충돌한게 높이가 크다면(==옆에서충돌)
				{
					if (m_pos.x < d->GetPos().x)	// 박스 왼쪽으로 충돌
						m_pos.x -= tempRect.right;
					else	// 박스 오른쪽으로 충돌
						m_pos.x += tempRect.right;
				}

				else  // 위아래에서 충돌했을 경우,
				{
					if (m_pos.y >= d->GetPos().y) // 박스의 밑으로 충돌
					{
						m_pos.y += tempRect.bottom;
					}
					else  // 박스의 위로 충돌
					{
						m_pos.y -= tempRect.bottom;
						m_Drop = false;
					}
				}
			}
		}
	}
}

void CNPC::Update()
{
	this->CheckCollision();

	if (m_ActionTime + 2000 < GetTickCount()) {
		switch (rand() % 4) {
		case ACTION::MOVE_LEFT: 
			m_Action = ACTION::MOVE_LEFT; if (m_IsJumpOn) m_IsJumpOn = false;
			m_MoveImgCnt = m_NumOfImg - 1; break;
		case ACTION::MOVE_RIGHT:
			m_Action = ACTION::MOVE_RIGHT; if (m_IsJumpOn) m_IsJumpOn = false; m_MoveImgCnt = 0; break;
		case ACTION::JUMP_LEFT: m_Action = ACTION::JUMP_LEFT; m_JumpImgCnt = 11; break;
		case ACTION::JUMP_RIGHT:
			m_Action = ACTION::JUMP_RIGHT; m_JumpImgCnt = m_NumOfMoveImg; break;
		}
		m_ActionTime = GetTickCount();
	}

	if (m_Time + 200 < GetTickCount()) {
		switch (m_Action) {
		case ACTION::MOVE_RIGHT: m_pos.x += m_Speed; ++m_MoveImgCnt; m_MoveImgCnt %= m_NumOfMoveImg; break;
		case ACTION::MOVE_LEFT: m_pos.x -= m_Speed; ++m_MoveImgCnt;
			m_MoveImgCnt %= m_NumOfMoveImg;
			m_MoveImgCnt += m_NumOfImg - m_NumOfMoveImg;
			break;
		case ACTION::JUMP_LEFT: 
			if (!m_IsJumpOn) {
				m_IsJumpOn = true;
				m_JumpTimer = GetTickCount();
			}
			else {
				if (m_JumpTimer + 100 < GetTickCount()) {
					if (m_JumpImgCnt == m_NumOfMoveImg) { m_IsJumpOn = false;  m_pos.y += m_JumpSpeed; break; }
					--m_JumpImgCnt;
					if (m_JumpImgCnt > m_NumOfMoveImg) { m_pos.x -= m_Speed; m_pos.y -= m_JumpSpeed; }
					else { m_pos.y += m_JumpSpeed; }
					m_JumpTimer = GetTickCount();
				}

			}break;
		case ACTION::JUMP_RIGHT:
			if (!m_IsJumpOn) {
				m_IsJumpOn = true;
				m_JumpTimer = GetTickCount();
			}
			else {
				if (m_JumpTimer + 100 < GetTickCount()) {
					if (m_JumpImgCnt == 11) { m_IsJumpOn = false;  m_pos.y += m_JumpSpeed; break; }
					++m_JumpImgCnt;
					if (m_JumpImgCnt <= 8) { m_pos.x += m_Speed; m_pos.y -= m_JumpSpeed; }
					else{ m_pos.y += m_JumpSpeed; }
					m_JumpTimer = GetTickCount();
				}

			}
			break;
		}
		m_Time = GetTickCount();
	}
}

void CNPC::MoveRender()
{
	switch (m_Action) {
	case ACTION::MOVE_RIGHT:
		BITMAPMANAGER->GetImage()[m_RightMoveJumpStr]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_ImgWidth,
			m_ImgHeight,
			m_ImgWidth * m_MoveImgCnt,
			0,
			m_ImgWidth,
			m_ImgHeight, RGB(147, 187, 236));
		break;
	case ACTION::MOVE_LEFT:
		BITMAPMANAGER->GetImage()[m_LeftMoveJumpStr]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_ImgWidth,
			m_ImgHeight,
			m_ImgWidth * m_MoveImgCnt,
			0,
			m_ImgWidth,
			m_ImgHeight, RGB(147, 187, 236));
		break;
	}
}

void CNPC::JumpRender()
{
	switch (m_Action) {
	case ACTION::JUMP_RIGHT:
		BITMAPMANAGER->GetImage()[m_RightMoveJumpStr]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_ImgWidth,
			m_ImgHeight,
			m_ImgWidth * m_JumpImgCnt,
			0,
			m_ImgWidth,
			m_ImgHeight, RGB(147, 187, 236));
		break;
	case ACTION::JUMP_LEFT:
		BITMAPMANAGER->GetImage()[m_LeftMoveJumpStr]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_ImgWidth,
			m_ImgHeight,
			m_ImgWidth * m_JumpImgCnt,
			0,
			m_ImgWidth,
			m_ImgHeight, RGB(147, 187, 236));
		break;
	}

}

void CNPC::Render()
{
	this->MoveRender();
	this->JumpRender();

}


void CNPC::Release()
{


}


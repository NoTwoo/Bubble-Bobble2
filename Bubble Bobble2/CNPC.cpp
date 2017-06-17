#include "global.h"

CNPC::CNPC(const ObjType a_ObjType)
{ 
	m_ObjType = a_ObjType;
	switch (SCENEMANAGER->GetStage()) {
	case STAGE1: m_name = "Stage1"; m_NumOfImg = NUM_OF_STAGE1_MONSTER_MOVE_JUMP_IMG;
		m_NumOfMoveImg = NUM_OF_STAGE1_MONSTER_MOVE_IMG;
		m_StartJumpImg = END_OF_STAGE1_JUMP_IMG;
		m_StartLeftJumpImg = START_OF_STAGE1_LEFT_JUMP_IMG;
		m_EndRightJumpImg = END_OF_STAGE1_RIGHT_JUMP_IMG;
		break;
	case STAGE2: m_name = "Stage2"; m_NumOfImg = NUM_OF_STAGE2_MONSTER_MOVE_JUMP_IMG;
		m_NumOfMoveImg = NUM_OF_STAGE2_MONSTER_MOVE_IMG; 
		m_StartJumpImg = END_OF_STAGE2_JUMP_IMG;
		m_StartLeftJumpImg = START_OF_STAGE2_LEFT_JUMP_IMG;
		m_EndRightJumpImg = END_OF_STAGE2_RIGHT_JUMP_IMG;
		break;
	case STAGE3: m_name = "Stage3"; m_NumOfImg = NUM_OF_STAGE3_MONSTER_MOVE_JUMP_IMG;
		m_NumOfMoveImg = NUM_OF_STAGE3_MONSTER_MOVE_IMG;
		m_StartJumpImg = END_OF_STAGE3_JUMP_IMG;
		m_StartLeftJumpImg = START_OF_STAGE3_LEFT_JUMP_IMG;
		m_EndRightJumpImg = END_OF_STAGE3_RIGHT_JUMP_IMG;
		break;
	case STAGE4: m_name = "Stage4"; m_NumOfImg = NUM_OF_STAGE4_MONSTER_MOVE_JUMP_IMG;
		m_NumOfMoveImg = NUM_OF_STAGE4_MONSTER_MOVE_IMG;
		m_StartJumpImg = END_OF_STAGE4_JUMP_IMG;
		m_StartLeftJumpImg = START_OF_STAGE4_LEFT_JUMP_IMG;
		m_EndRightJumpImg = END_OF_STAGE4_RIGHT_JUMP_IMG;
		break;
	case STAGE5: m_name = "Stage5"; m_NumOfImg = NUM_OF_STAGE5_MONSTER_MOVE_JUMP_IMG;
		m_NumOfMoveImg = NUM_OF_STAGE5_MONSTER_MOVE_IMG;
		m_StartJumpImg = END_OF_STAGE5_JUMP_IMG;
		m_StartLeftJumpImg = START_OF_STAGE5_LEFT_JUMP_IMG;
		m_EndRightJumpImg = END_OF_STAGE5_RIGHT_JUMP_IMG;
		break;
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
	switch (SCENEMANAGER->GetStage()) {
	case STAGE1:
		m_JumpXSpeed = NPC_SPEED;
		m_JumpSpeed = NPC_JUMP_SPEED;
		break;
	case STAGE2:
		m_JumpXSpeed = NPC_SPEED * 2;
		m_JumpSpeed = NPC_JUMP_SPEED * 2;
		break;
	case STAGE3:
		m_JumpXSpeed = NPC_SPEED * 2;
		m_JumpSpeed = NPC_JUMP_SPEED * 2;
		break;
	case STAGE4:
		m_JumpXSpeed = NPC_SPEED * 2;
		m_JumpSpeed = NPC_JUMP_SPEED * 2;
		break;
	case STAGE5:
		m_JumpXSpeed = NPC_SPEED * 2;
		m_JumpSpeed = NPC_JUMP_SPEED * 2;
		break;
	}
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


				if (tempRect.right <= tempRect.bottom) // �浹�Ѱ� ���̰� ũ�ٸ�(==�������浹)
				{
					if (m_pos.x < d->GetPos().x)	// �ڽ� �������� �浹
						m_pos.x -= tempRect.right;
					else	// �ڽ� ���������� �浹
						m_pos.x += tempRect.right;
				}

				else  // ���Ʒ����� �浹���� ���,
				{
					if (m_pos.y >= d->GetPos().y) // �ڽ��� ������ �浹
					{
						m_pos.y += tempRect.bottom;
					}
					else  // �ڽ��� ���� �浹
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
		case ACTION::JUMP_LEFT: m_Action = ACTION::JUMP_LEFT; m_JumpImgCnt = m_StartLeftJumpImg; break;
		case ACTION::JUMP_RIGHT:
			m_Action = ACTION::JUMP_RIGHT; m_JumpImgCnt = m_NumOfMoveImg - 1; break;
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
				if (m_JumpImgCnt == 0) {
					m_Action = ACTION::MOVE_LEFT; if (m_IsJumpOn) m_IsJumpOn = false;
					m_MoveImgCnt = m_NumOfImg - 1; break;
				}
				m_IsJumpOn = true;
				m_JumpTimer = GetTickCount();
			}
			else {
				if (m_JumpTimer + 100 < GetTickCount()) {
					if (m_JumpImgCnt == m_NumOfMoveImg || m_JumpImgCnt == 0) { m_IsJumpOn = false;  m_pos.y += m_JumpSpeed; break; }
					--m_JumpImgCnt;
					if (m_JumpImgCnt > m_NumOfMoveImg || m_JumpImgCnt > 0) { m_pos.x -= m_JumpXSpeed; m_pos.y -= m_JumpSpeed; }
					else { m_pos.y += m_JumpSpeed; }
					m_JumpTimer = GetTickCount();
				}

			}break;
		case ACTION::JUMP_RIGHT:
			if (!m_IsJumpOn) {
				if (m_JumpImgCnt == m_StartJumpImg) {
					m_Action = ACTION::MOVE_RIGHT; if (m_IsJumpOn) m_IsJumpOn = false; m_MoveImgCnt = 0; break;
				}
				m_IsJumpOn = true;
				m_JumpTimer = GetTickCount();
			}
			else {
				if (m_JumpTimer + 100 < GetTickCount()) {
					if (m_JumpImgCnt == m_StartJumpImg) { m_IsJumpOn = false;  m_pos.y += m_JumpSpeed; break; }
					++m_JumpImgCnt;
					if (m_JumpImgCnt <= m_EndRightJumpImg) { m_pos.x += m_JumpXSpeed; m_pos.y -= m_JumpSpeed; }
					else {m_pos.y += m_JumpSpeed; }
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
	// Rectangle(GAMEMANAGER->GetMemDC(), m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
	this->MoveRender();
	this->JumpRender();

}


void CNPC::Release()
{


}


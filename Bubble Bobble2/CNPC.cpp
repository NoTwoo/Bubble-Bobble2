#include "global.h"

CNPC::CNPC(const ObjType a_Type)
{ 
	m_ObjType = a_Type; 
	switch (m_ObjType) {
	case STAGE1_NPC: m_name = "Stage1"; break;

	}
}

void CNPC::Initiallize()
{
	m_MoveJumpStr = m_name;
	m_MoveJumpStr.Append("NPCMoveAndJumpImg");
	m_ImgWidth = BITMAPMANAGER->GetImage()[m_MoveJumpStr]->GetWidth() / NUM_OF_STAGE1_MONSTER_MOVE_JUMP_IMG;
	m_ImgHeight = BITMAPMANAGER->GetImage()[m_MoveJumpStr]->GetHeight();
	m_rect.left = m_pos.x; m_rect.top = m_pos.y;
	m_rect.right = m_rect.left + m_ImgWidth;
	m_rect.bottom = m_rect.top + m_ImgHeight;

	m_MoveImgCnt = 0;
	m_Direction = DIRECTION::RIGHT;

}

void CNPC::Update()
{


}

void CNPC::MoveRender()
{
	if (m_Direction == DIRECTION::RIGHT)
		BITMAPMANAGER->GetImage()[m_MoveJumpStr]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_ImgWidth,
			m_ImgHeight,
			m_ImgWidth * m_MoveImgCnt,
			0,
			m_ImgWidth,
			m_ImgHeight, RGB(147, 187, 236));
}

void CNPC::Render()
{
	this->MoveRender();
}


void CNPC::Release()
{


}
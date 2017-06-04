#include "global.h"

void CPlayer::Initiallize()
{
	m_ImgWidth = BITMAPMANAGER->GetImage()["PlayerMoveAndJumpToRightImg"]->GetWidth() / NUM_OF_PLAYER_MOVE_JUMP_IMG;
	m_ImgHeight = BITMAPMANAGER->GetImage()["PlayerMoveAndJumpToRightImg"]->GetHeight();

	m_rect.left = 40;
	m_rect.right = m_rect.left + m_ImgWidth;
	m_rect.top = GAMEMANAGER->GetRect().bottom - m_ImgHeight;
	m_rect.bottom = m_rect.top + m_ImgHeight;

	m_pos.x = m_rect.left;
	m_pos.y = m_rect.top;
	m_Speed = SPEED;
	m_AttImgCnt = 0;
	m_IsAttOn = false;
	m_Direction = DIRECTION::RIGHT;
	m_JumpImgCnt = NUM_OF_PLAYER_JUMP_IMG - 1;
	m_IsJumpOn = false;
	m_Time = GetTickCount();
	m_MoveImgCnt = 0;

	m_Drop = false;

	m_BubbleImgWidth = BITMAPMANAGER->GetImage()["BubbleMoveImg"]->GetWidth() / NUM_OF_PLAYER_BUBBLE_MOVE_IMG;
	m_BubbleImgHeight = BITMAPMANAGER->GetImage()["BubbleMoveImg"]->GetHeight();
}

const bool CPlayer::CheckCollision(const DIRECTION a_Direction)
{
	
	switch (a_Direction) {
	case DIRECTION::RIGHT: if ((m_pos.x + m_ImgWidth + m_Speed) < GAMEMANAGER->GetRect().right) return true;
		break;
	case DIRECTION::LEFT: if ((m_pos.x - m_Speed) > GAMEMANAGER->GetRect().left) return true;
		break;
	}

	return false;
}

void CPlayer::CheckPopBubble()
{
	RECT tempRect;

	for (auto d : m_Obj) {
		list<CObject*>::iterator itor = m_Obj.begin();
		if (IntersectRect(&tempRect, &m_rect, &d->GetRect())) {
			if (d->GetObjType() == BUBBLE) {
				CBubble* pBubble = dynamic_cast<CBubble*>(d);
				pBubble->SetPop();
				while (itor != m_Obj.end()) {
					list<CObject*>::iterator itor2 = m_Obj.begin();
					while (itor2 != m_Obj.end()) {
						if (itor != itor2) {
							if (IntersectRect(&tempRect, &(*itor)->GetRect(), &(*itor2)->GetRect())) {
								CBubble* pBubble2 = dynamic_cast<CBubble*>(*itor2);
								pBubble2->SetPop();
							}
						}
						++itor2;
					}
					++itor;
				}
				return;
			}

		}
	}

}
void CPlayer::CheckCollision()
{
	RECT tempRect;
	m_rect.left = m_pos.x;
	m_rect.right = (m_rect.left + m_ImgWidth);
	m_rect.top = m_pos.y;
	m_rect.bottom = m_rect.top + m_ImgHeight;
	


	for (auto d : SCENEMANAGER->GetStage1List()) {
		if (IntersectRect(&tempRect, &m_rect, &d->GetRect())) {

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
					//m_pos.y += tempRect.bottom;
				}
				else  // 박스의 위로 충돌
				{
					m_pos.y -= tempRect.bottom;
					m_Drop = false;
				}
			}
		}
	}

	CheckPopBubble();

}
void CPlayer::Move()
{

	if (GetAsyncKeyState(VK_RIGHT)) {
		if (m_Direction != DIRECTION::RIGHT) { if (m_IsJumpOn) return; m_Direction = DIRECTION::RIGHT; m_MoveImgCnt = 0; m_MoveImgCnt = 0; }
		++m_MoveImgCnt; m_MoveImgCnt = m_MoveImgCnt % NUM_OF_PLAYER_MOVE_IMG;
		if(this->CheckCollision(DIRECTION::RIGHT)) m_pos.x += m_Speed;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if (m_Direction != DIRECTION::LEFT) { if (m_IsJumpOn) return; m_Direction = DIRECTION::LEFT; m_MoveImgCnt = NUM_OF_PLAYER_MOVE_JUMP_IMG; }
		--m_MoveImgCnt; m_MoveImgCnt = m_MoveImgCnt % NUM_OF_PLAYER_MOVE_JUMP_IMG;
		if (m_MoveImgCnt < NUM_OF_PLAYER_MOVE_IMG) m_MoveImgCnt = NUM_OF_PLAYER_MOVE_JUMP_IMG - 1;
		if (this->CheckCollision(DIRECTION::LEFT)) m_pos.x -= m_Speed;
	}

}

void CPlayer::Attack()
{

	if (GetAsyncKeyState('A')) {
		if (!m_IsAttOn) {
			m_IsAttOn = true;
			if (m_Direction == DIRECTION::RIGHT) m_AttImgCnt = 0;
			else  m_AttImgCnt = NUM_OF_PLAYER_SHOOT_BUBBLE_IMG - 1;
			m_BubbleTimer = GetTickCount();
			if (m_pos.x - m_ImgWidth > GAMEMANAGER->GetRect().left || m_pos.x + m_ImgWidth < GAMEMANAGER->GetRect().right) {
				CFactory<CBubble> m_fact;
				if (m_Direction == DIRECTION::RIGHT)
					m_Obj.push_back(m_fact.CreateObj(m_Direction,
						RECT{m_pos.x + m_ImgWidth, m_pos.y + 10,
						(m_pos.x + m_ImgWidth) + m_BubbleImgWidth, (m_pos.y + 10) + m_BubbleImgHeight }));
				else
					m_Obj.push_back(m_fact.CreateObj(m_Direction,
						RECT{ m_pos.x - m_ImgWidth, m_pos.y - 10,
						(m_pos.x - m_ImgWidth) + m_BubbleImgWidth, (m_pos.y - 10) + m_BubbleImgHeight }));

			}
		}
		SOUNDMANAGER->effplaysound(EFFSOUNDKIND::ATTACK);
	}
	if (m_IsAttOn) {
		if (m_BubbleTimer + 100 < GetTickCount()) {
			if (m_Direction == DIRECTION::RIGHT) {
				++m_AttImgCnt;
				if (m_AttImgCnt > NUM_OF_PLAYER_SHOOT_BUBBLE_IMG - 1) { m_IsAttOn = false; m_MoveImgCnt = 0;}
			}
			else {
				--m_AttImgCnt;
				if (m_AttImgCnt == 0) { m_IsAttOn = false; m_MoveImgCnt = NUM_OF_PLAYER_MOVE_JUMP_IMG - 1;}
			}
			m_BubbleTimer = GetTickCount();
		}

	}

}

void CPlayer::Jump()
{
	if (GetAsyncKeyState(VK_SPACE)) {
		if (!m_IsJumpOn) {
			m_IsJumpOn = true;
			m_JumpTimer = GetTickCount();
			if (m_Direction == DIRECTION::RIGHT) m_JumpImgCnt = NUM_OF_PLAYER_MOVE_IMG;
			else m_JumpImgCnt = NUM_OF_PLAYER_MOVE_IMG - 1;
			SOUNDMANAGER->effplaysound(EFFSOUNDKIND::JUMP);
		}
		
	}

	if (m_IsJumpOn) {
		if (m_JumpTimer + 100 < GetTickCount()) {
			if (m_Direction == DIRECTION::RIGHT) {
				
				++m_JumpImgCnt;
				if (m_JumpImgCnt == NUM_OF_PLAYER_MOVE_JUMP_IMG) { m_IsJumpOn = false; m_MoveImgCnt = 0; m_pos.y += m_Speed; return; }

				if (m_JumpImgCnt <= 12) {  m_pos.y -= m_Speed; }
				else {  m_pos.y += m_Speed; }
			
			}
			else {
				--m_JumpImgCnt;
				if (m_JumpImgCnt == 0) { m_IsJumpOn = false; m_MoveImgCnt = NUM_OF_PLAYER_MOVE_JUMP_IMG - 1; return; }

				if (m_JumpImgCnt > 3) { m_pos.y -= m_Speed; }
				else { m_pos.y += m_Speed; }
			}
			m_JumpTimer = GetTickCount();
		}
	}
}

void CPlayer::Update()
{
	if (!m_IsJumpOn &&  m_pos.y < GAMEMANAGER->GetRect().bottom - m_ImgHeight)
		m_Drop = true;

	if (!m_IsJumpOn && m_Drop && m_pos.y < GAMEMANAGER->GetRect().bottom - m_ImgHeight) {
		m_pos.y += 1;
	}
	
	this->CheckCollision();
	this->CheckDelete();

	if (m_Time + 100 < GetTickCount()) {
		this->Move();
		this->Attack();
		this->Jump();
		for (auto d : m_Obj) d->Update();
		m_Time = GetTickCount();
	}

}

void CPlayer::MoveRender()
{
	if(m_Direction == DIRECTION::RIGHT)
	BITMAPMANAGER->GetImage()["PlayerMoveAndJumpToRightImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		m_ImgWidth,
		m_ImgHeight,
		m_ImgWidth * m_MoveImgCnt + 4,
		0,
		m_ImgWidth - 4,
		m_ImgHeight, RGB(147, 187, 236));

	else
		BITMAPMANAGER->GetImage()["PlayerMoveAndJumpToLeftImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_ImgWidth,
			m_ImgHeight,
			m_ImgWidth * m_MoveImgCnt,
			0,
			m_ImgWidth -4,
			m_ImgHeight, RGB(147, 187, 236));

}

void CPlayer::ShootBubbleRender()
{
	if (m_Direction == DIRECTION::RIGHT)
	BITMAPMANAGER->GetImage()["PlayerShootBubbleToRightImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleToRightImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleToRightImg"]->GetHeight(),
		(BITMAPMANAGER->GetImage()["PlayerShootBubbleToRightImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG) * m_AttImgCnt,
		0,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleToRightImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleToRightImg"]->GetHeight(), RGB(147, 187, 236));

	else
		BITMAPMANAGER->GetImage()["PlayerShootBubbleToLeftImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			BITMAPMANAGER->GetImage()["PlayerShootBubbleToLeftImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG,
			BITMAPMANAGER->GetImage()["PlayerShootBubbleToLeftImg"]->GetHeight(),
			(BITMAPMANAGER->GetImage()["PlayerShootBubbleToLeftImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG) * m_AttImgCnt,
			0,
			BITMAPMANAGER->GetImage()["PlayerShootBubbleToLeftImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG,
			BITMAPMANAGER->GetImage()["PlayerShootBubbleToLeftImg"]->GetHeight(), RGB(147, 187, 236));
}

void CPlayer::JumpRender()
{

	if (m_Direction == DIRECTION::RIGHT)
	BITMAPMANAGER->GetImage()["PlayerMoveAndJumpToRightImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		m_ImgWidth,
		m_ImgHeight,
		m_ImgWidth * m_JumpImgCnt,
		0,
		m_ImgWidth - 2,
		m_ImgHeight, RGB(147, 187, 236));
	else
		BITMAPMANAGER->GetImage()["PlayerMoveAndJumpToLeftImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			m_ImgWidth,
			m_ImgHeight,
			m_ImgWidth * m_JumpImgCnt + 2,
			0,
			m_ImgWidth,
			m_ImgHeight, RGB(147, 187, 236));
}

void CPlayer::Render()
{
	if (!m_IsAttOn && !m_IsJumpOn) this->MoveRender();
	if (m_IsJumpOn) this->JumpRender();

	if(m_IsAttOn) this->ShootBubbleRender();

	for (auto d : m_Obj) d->Render();
}

void CPlayer::Release()
{

}

void CPlayer::CheckDelete()
{
	list<CObject*>::iterator itor = m_Obj.begin();

	while (itor != m_Obj.end()) {
		if ((*itor)->GetDelete()) {
			itor = m_Obj.erase(itor);
		}
		else ++itor;
	}


}
//CPlayer::~CPlayer() { this->Release(); }
#include "global.h"

void CPlayer::Initiallize()
{
	m_rect.left = 0, m_rect.right = BITMAPMANAGER->GetImage()["PlayerMove"]->GetWidth() / PLAYER_MOVE_X_IMG;
	m_rect.top = 0, m_rect.bottom = BITMAPMANAGER->GetImage()["PlayerMove"]->GetHeight() / PLAYER_MOVE_Y_IMG;

	m_pos.x = 40;
	m_pos.y = GAMEMANAGER->GetRect().bottom - m_rect.bottom;
	m_XCnt = 0;
	m_YCnt = 1;
	m_Speed = SPEED;
	m_AttCnt = 0;
	m_IsAttOn = false;
	m_Time = GetTickCount();
}

void CPlayer::CheckCollision()
{

}

void CPlayer::Move()
{
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (m_YCnt != 1) { m_YCnt = 1; m_XCnt = 0; }
		++m_XCnt; m_XCnt = m_XCnt % PLAYER_MOVE_X_IMG;
		if ((m_pos.x + m_rect.right + m_Speed) < GAMEMANAGER->GetRect().right) m_pos.x += m_Speed;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if (m_YCnt != 0) { m_YCnt = 0; m_XCnt = 0; } ++m_XCnt; m_XCnt = m_XCnt % PLAYER_MOVE_X_IMG;
		if ((m_pos.x - m_Speed) > GAMEMANAGER->GetRect().left) m_pos.x -= m_Speed;
	}

}

void CPlayer::Attack()
{
	if (GetAsyncKeyState('A')) {
		if (!m_IsAttOn) {
			m_IsAttOn = true;
			m_BubbleTimer = GetTickCount();
		}
		SOUNDMANAGER->effplaysound(EFFSOUNDKIND::EFFSD_1);
	}
	if (m_IsAttOn) {
		if (m_BubbleTimer + 100 < GetTickCount()) {
			++m_AttCnt;
			m_BubbleTimer = GetTickCount();
			if (m_AttCnt > NUM_OF_PLAYER_SHOOT_BUBBLE_IMG) { m_IsAttOn = false; m_AttCnt = 0; }
		}

	}
}

void CPlayer::Update()
{

	if (m_Time + 100 < GetTickCount()) {
		this->Move();
		this->Attack();

		m_Time = GetTickCount();
	}

}

void CPlayer::MoveRender()
{
	BITMAPMANAGER->GetImage()["PlayerMove"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetWidth() / PLAYER_MOVE_X_IMG,
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetHeight() / PLAYER_MOVE_Y_IMG,
		(BITMAPMANAGER->GetImage()["PlayerMove"]->GetWidth() / PLAYER_MOVE_X_IMG) * m_XCnt,
		(BITMAPMANAGER->GetImage()["PlayerMove"]->GetHeight() / PLAYER_MOVE_Y_IMG) * m_YCnt,
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetWidth() / PLAYER_MOVE_X_IMG,
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetHeight() / PLAYER_MOVE_Y_IMG, RGB(0, 0, 0));

}

void CPlayer::BubbleRender()
{
	
	BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetHeight(),
		(BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG) * m_AttCnt,
		0,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetWidth() / NUM_OF_PLAYER_SHOOT_BUBBLE_IMG,
		BITMAPMANAGER->GetImage()["PlayerShootBubbleImg"]->GetHeight(), RGB(0, 0, 0));


}

void CPlayer::Render()
{
	if (!m_IsAttOn) this->MoveRender();
	else this->BubbleRender();
}

void CPlayer::Release()
{

}

//CPlayer::~CPlayer() { this->Release(); }
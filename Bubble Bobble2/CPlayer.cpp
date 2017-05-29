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
	m_Time = GetTickCount();
}

void CPlayer::CheckCollision()
{

}

void CPlayer::Move()
{
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (m_YCnt != 1) m_YCnt = 1;
		++m_XCnt; m_XCnt = m_XCnt % PLAYER_MOVE_X_IMG;
		if ((m_pos.x + m_rect.right + m_Speed) < GAMEMANAGER->GetRect().right) m_pos.x += m_Speed;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if (m_YCnt != 0) m_YCnt = 0; ++m_XCnt; m_XCnt = m_XCnt % PLAYER_MOVE_X_IMG; 
		if ((m_pos.x - m_Speed) > GAMEMANAGER->GetRect().left) m_pos.x -= m_Speed;
	}

}

void CPlayer::Attack()
{
	if (GetAsyncKeyState('A')) {
		SOUNDMANAGER->effplaysound(EFFSOUNDKIND::EFFSD_1);
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

void CPlayer::Render()
{
	BITMAPMANAGER->GetImage()["PlayerMove"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetWidth() / PLAYER_MOVE_X_IMG, 
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetHeight() / PLAYER_MOVE_Y_IMG,
		(BITMAPMANAGER->GetImage()["PlayerMove"]->GetWidth() / PLAYER_MOVE_X_IMG) * m_XCnt, 
		(BITMAPMANAGER->GetImage()["PlayerMove"]->GetHeight() / PLAYER_MOVE_Y_IMG) * m_YCnt,
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetWidth() / PLAYER_MOVE_X_IMG ,
		BITMAPMANAGER->GetImage()["PlayerMove"]->GetHeight() / PLAYER_MOVE_Y_IMG, RGB(0, 0, 0));
}

void CPlayer::Release()
{

}

//CPlayer::~CPlayer() { this->Release(); }
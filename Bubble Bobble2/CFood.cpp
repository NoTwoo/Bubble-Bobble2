#include "global.h"


void CFood::CheckCollision()
{

	RECT tempRect;
	m_rect.left = m_pos.x;
	m_rect.right = (m_rect.left + BITMAPMANAGER->GetImage()[m_name]->GetWidth());
	m_rect.top = m_pos.y;
	m_rect.bottom = (m_rect.top + BITMAPMANAGER->GetImage()[m_name]->GetHeight());

	for (auto d : SCENEMANAGER->GetStageList()) {
		if (IntersectRect(&tempRect, &m_rect, &d->GetRect())) {
			::SetRect(&tempRect, 0, 0, tempRect.right - tempRect.left, tempRect.bottom - tempRect.top);

			if (tempRect.right >= tempRect.bottom){
				if (m_pos.y >= d->GetPos().y);
				else {
					m_pos.y -= tempRect.bottom;
					m_Fall = false; return;
				}
			}

		}
	}
}
void CFood::Update()
{

	if (!m_DrawPoint) this->CheckCollision();
	else {
		if (m_Time + 100 < GetTickCount()) {
			GAMEMANAGER->AddPoint((m_ItemType + 1) * 10);
			this->DeleteMe();
		}
	}
	if (m_Fall) m_pos.y += SPEED;

}

void CFood::Render()
{

	if(!m_DrawPoint)
	BITMAPMANAGER->GetImage()[m_name]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
		BITMAPMANAGER->GetImage()[m_name]->GetWidth(),
		BITMAPMANAGER->GetImage()[m_name]->GetHeight(),
		0,
		0,
		BITMAPMANAGER->GetImage()[m_name]->GetWidth(),
		BITMAPMANAGER->GetImage()[m_name]->GetHeight(), RGB(147, 187, 236));

	else 
		BITMAPMANAGER->GetImage()["PointImg"]->TransparentBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y,
			BITMAPMANAGER->GetImage()["PointImg"]->GetWidth() / NUM_OF_POINT_IMG,
			BITMAPMANAGER->GetImage()["PointImg"]->GetHeight(),
			m_ItemType * BITMAPMANAGER->GetImage()["PointImg"]->GetWidth() / NUM_OF_POINT_IMG,
			0,
			BITMAPMANAGER->GetImage()["PointImg"]->GetWidth() / NUM_OF_POINT_IMG - 10,
			BITMAPMANAGER->GetImage()["PointImg"]->GetHeight(), RGB(147, 187, 236));
}

#include "global.h"

void CObstacle::Initiallize()
{
	if (m_name.GetLength() != 0) m_ObjType = OBSTACLE;
	else m_ObjType = REAR_OBSTACLE;
}

void CObstacle::Update()
{


}

void CObstacle::Render()
{
	if(m_name.GetLength() != 0)
	BITMAPMANAGER->GetImage()[m_name]->BitBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y, m_rect.right, m_rect.bottom, 0, 0, SRCCOPY);
	//Rectangle(GAMEMANAGER->GetMemDC(), m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
}


void CObstacle::Release()
{


}
#include "global.h"

void CObstacle::Initiallize()
{
	m_ObjType = OBSTACLE;

}

void CObstacle::Update()
{


}

void CObstacle::Render()
{
	BITMAPMANAGER->GetImage()[m_name]->BitBlt(GAMEMANAGER->GetMemDC(), m_pos.x, m_pos.y, m_rect.right, m_rect.bottom, 0, 0, SRCCOPY);;
}


void CObstacle::Release()
{


}
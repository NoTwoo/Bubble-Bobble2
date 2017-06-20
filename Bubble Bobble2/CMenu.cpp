#include "global.h"

CMenu::CMenu(){ this->Initialize(); }
void CMenu::Initialize()
{
	// Initialize rect of menu
	m_MenuType = MENUTYPE::NORMAL;
	SOUNDMANAGER->playsound(SOUNDKIND::MENUBGM);

	for (int i = 0; i < NUM_OF_MENU - 1; ++i) {
		m_MenuRect[i].left = 55;
		m_MenuRect[i].right = 515;
		if (i == 0) m_MenuRect[i].top = 220;
		else  m_MenuRect[i].top = m_MenuRect[i - 1].bottom + 5;

		m_MenuRect[i].bottom = m_MenuRect[i].top + 80;
	}

}

void CMenu::ChangeMenuImg()
{
	GetCursorPos(&m_mouse);
	ScreenToClient(GAMEMANAGER->GethWnd(), &m_mouse);

	for (int i = 0; i < NUM_OF_MENU - 1; ++i) {
		if (m_mouse.x >= m_MenuRect[i].left &&  m_mouse.x <= m_MenuRect[i].right)
			if (m_mouse.y >= m_MenuRect[i].top &&  m_mouse.y <= m_MenuRect[i].bottom) { m_MenuType = i + 2; return; }
	}

	m_MenuType = MENUTYPE::NORMAL;

}
SCENE_ID CMenu::Update()
{
	this->ChangeMenuImg();

	if (GetAsyncKeyState(VK_LBUTTON)) {
		switch (m_MenuType) {
		case MENUTYPE::NORMAL: return SCENE_ID::NOTHING;
		case MENUTYPE::GAME_START: return SCENE_ID::STAGE1;
		case MENUTYPE::REPLAY: return SCENE_ID::NOTHING;
		case MENUTYPE::RANKING: return SCENE_ID::NOTHING;
		case MENUTYPE::HELP: return SCENE_ID::MENU_HELP;
		case MENUTYPE::MENU_EXIT: return SCENE_ID::GAME_EXIT;
		}

	}
	return NOTHING;
}

void CMenu::Render()
{
	CString str;
	str.Format("Menu%dImg", m_MenuType);
	BITMAPMANAGER->GetImage()[str]->BitBlt(GAMEMANAGER->GetMemDC(), 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 0, 0, SRCCOPY);
	
	GAMEMANAGER->Render();
}

void CMenu::Release()
{

}


CMenu::~CMenu(){ this->Release(); }
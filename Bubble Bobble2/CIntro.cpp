#include "global.h"

#pragma comment(lib,"Vfw32.lib")

void CIntro::Initialize()
{
	m_hVideo = MCIWndCreate(GAMEMANAGER->GethWnd(), NULL, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD,
		"Resources\\Movie\\Intro.wmv");
	MoveWindow(m_hVideo, 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, NULL);
	MCIWndPlay(m_hVideo);
}

SCENE_ID CIntro::Update()
{
	if (GetAsyncKeyState(VK_RETURN)) return MENU;

	return NOTHING;
}


void CIntro::Release() { MCIWndClose(m_hVideo); }

CIntro::~CIntro(){ this->Release(); }
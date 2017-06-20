#include "global.h"

#pragma comment(lib,"Vfw32.lib")

void CEnding::Initialize()
{
	m_hVideo = MCIWndCreate(GAMEMANAGER->GethWnd(), NULL, MCIWNDF_NOTIFYPOS | MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD,
		"Resources\\Movie\\Ending.wmv");
	MoveWindow(m_hVideo, 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, NULL);
	if (m_hVideo) MCIWndPlay(m_hVideo);
}

SCENE_ID CEnding::Update()
{
	if (GetAsyncKeyState(VK_RETURN)) return MENU;

	return NOTHING;
}


void CEnding::Release() { MCIWndClose(m_hVideo); }

CEnding::~CEnding() { this->Release(); }
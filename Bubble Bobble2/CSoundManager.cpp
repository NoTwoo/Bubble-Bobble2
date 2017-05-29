#include"global.h"

CSoundManager* CSoundManager::m_instance = nullptr;


void CSoundManager::Initialize()
{
	this->soundsetup();
	this->effsoundsetup();
}

void CSoundManager::Release()
{
	this->BGsoundoff();
	this->effsoundoff();
	for (int i = 0; i<1; i++)
		FMOD_Sound_Release(this->g_psound[i]);
	for (int i = 0; i<1; i++)
		FMOD_Sound_Release(this->effg_psound[i]);
	FMOD_System_Close(this->g_psystem);
	FMOD_System_Release(this->g_psystem);
}
void CSoundManager::soundsetup()
{
	char str[128];

	//사운드 시스템 생성
	FMOD_System_Create(&this->g_psystem);
	//채널 수 , 모드, 0
	//FMOD_System_Init(this->g_psystem, 7, FMOD_INIT_NORMAL, NULL);
	FMOD_System_Init(this->g_psystem, 1, FMOD_INIT_NORMAL, NULL);

	//사운드 경로
	//for (int i = 0; i<SD_END; i++){
	//	sprintf_s(str, "Sound\\Sound%d.mp3", i + 1, lstrlen(str));
	//	FMOD_System_CreateStream(this->g_psystem, str, FMOD_LOOP_NORMAL, 0, &this->g_psound[i]);
	//}
	FMOD_System_CreateStream(this->g_psystem, "Resources\\Sound\\BGM\\BGM.mp3", FMOD_LOOP_NORMAL, 0, &this->g_psound[0]);
}

/*
사운드 1 - 메인메뉴
사운드 2 - 게임중
*/

void CSoundManager::playsound(SOUNDKIND esound)
{
	FMOD_System_PlaySound(this->g_psystem, FMOD_CHANNEL_FREE, this->g_psound[esound], 0, &this->g_pchannel[esound]);
}

void CSoundManager::effsoundsetup()
{
	char str[128];

	//사운드 시스템 생성
	FMOD_System_Create(&this->effg_psystem);

	//채널 수 , 모드, 0
	FMOD_System_Init(this->effg_psystem, 1, FMOD_INIT_NORMAL, NULL);

	//사운드 경로
	/*for (int i = 0; i<EFFSD_END; i++){
		sprintf_s(str, "Sound\\effsound%d.wav", i + 1, lstrlen(str));
		FMOD_System_CreateSound(this->effg_psystem, (const char*)str, FMOD_DEFAULT, 0, &this->effg_psound[i]);
	}*/
	FMOD_System_CreateSound(this->effg_psystem, "Resources\\Sound\\Effects\\Attack.mp3", FMOD_DEFAULT, 0, &this->effg_psound[0]);
}
/*
1~7각종 스킬같은 종류 사운드
*/

void CSoundManager::BGsoundoff()
{
	for (int i = 0; i<1; i++)
		FMOD_Channel_Stop(this->g_pchannel[i]);
}

void CSoundManager::effsoundoff()
{
	for (int i = 0; i<1; i++)
		FMOD_Channel_Stop(this->effg_pchannel[i]);
}
void CSoundManager::effplaysound(EFFSOUNDKIND esound)
{
	FMOD_BOOL IsPlaying;
	FMOD_Channel_IsPlaying(this->effg_pchannel[esound], &IsPlaying);
	if(!IsPlaying)
	FMOD_System_PlaySound(this->effg_psystem, FMOD_CHANNEL_FREE, this->effg_psound[esound], 0, &this->effg_pchannel[esound]);
}


CSoundManager::~CSoundManager(){ this->Release(); }
#include"global.h"

void CSoundManager::soundsetup()
{
	char str[128];

	//���� �ý��� ����
	FMOD_System_Create(&this->g_psystem);
	//ä�� �� , ���, 0
	FMOD_System_Init(this->g_psystem, 7, FMOD_INIT_NORMAL, NULL);

	//���� ���
	for (int i = 0; i<SD_END; i++){
		sprintf_s(str, "Sound\\Sound%d.mp3", i + 1, lstrlen(str));
		//SetWindowText(GAMEMANAGER->getWndHandle(), str);
		FMOD_System_CreateStream(this->g_psystem, str, FMOD_LOOP_NORMAL, 0, &this->g_psound[i]);
	}
}

/*
���� 1 - ���θ޴�
���� 2 - ������
*/

void CSoundManager::playsound(SOUNDKIND esound)
{
	cout << "PlaySound() Call!" << endl;
	FMOD_System_PlaySound(this->g_psystem, FMOD_CHANNEL_FREE, this->g_psound[esound], 0, &this->g_pchannel[esound]);
}

void CSoundManager::effsoundsetup()
{
	char str[128];

	//���� �ý��� ����
	FMOD_System_Create(&this->effg_psystem);

	//ä�� �� , ���, 0
	FMOD_System_Init(this->effg_psystem, 1, FMOD_INIT_NORMAL, NULL);

	//���� ���
	for (int i = 0; i<EFFSD_END; i++){
		sprintf_s(str, "Sound\\effsound%d.wav", i + 1, lstrlen(str));
		FMOD_System_CreateSound(this->effg_psystem, (const char*)str, FMOD_DEFAULT, 0, &this->effg_psound[i]);
	}
}
/*
1~7���� ��ų���� ���� ����
*/

void CSoundManager::BGsoundoff()
{
	for (int i = 0; i<SD_END; i++)
		FMOD_Channel_Stop(this->g_pchannel[i]);
}

void CSoundManager::effsoundoff()
{
	for (int i = 0; i<EFFSD_END; i++)
		FMOD_Channel_Stop(this->effg_pchannel[i]);
}
void CSoundManager::effplaysound(EFFSOUNDKIND esound)
{
	FMOD_System_PlaySound(this->effg_psystem, FMOD_CHANNEL_FREE, this->effg_psound[esound], 0, &this->effg_pchannel[esound]);
}
#pragma once

#ifndef _SOUND_H_
#define _SOUND_H_
#include<Windows.h>
#include<fmod.h>
#pragma comment (lib, "fmodex_vc.lib")

enum SOUNDKIND
{
	SD_1 = 0,
	SD_2,
	SD_3,
	SD_4,
	SD_5,
	SD_END = 7
};

enum EFFSOUNDKIND
{
	EFFSD_1 = 0,
	EFFSD_2,
	EFFSD_3,
	EFFSD_4,
	EFFSD_5,
	EFFSD_6,
	EFFSD_7,
	EFFSD_END
};

class CSoundManager
{
public:
	FMOD_SYSTEM* GetBgmSystem() { return g_psystem; }
	FMOD_SOUND** GetBgmSound() { return g_psound; }
	FMOD_CHANNEL** GetBgmChannel() { return g_pchannel; }

	FMOD_SYSTEM* GetEftSystem() { return effg_psystem; }
	FMOD_SOUND** GetEftSound() { return effg_psound; }
	FMOD_CHANNEL** GetEftChannel() { return effg_pchannel; }
public:
	void soundsetup();
	void effsoundsetup();
	void playsound(SOUNDKIND esound);
	void effsoundoff();
	void BGsoundoff();
	void effplaysound(EFFSOUNDKIND esound);

private:
	CSoundManager() {};
	CSoundManager(const CSoundManager&) = delete;
	void operator=(const CSoundManager&) = delete;

private:
	FMOD_SYSTEM* g_psystem;
	FMOD_SOUND* g_psound[SD_END];
	FMOD_CHANNEL* g_pchannel[SD_END];

	FMOD_SYSTEM* effg_psystem;
	FMOD_SOUND* effg_psound[EFFSD_END];
	FMOD_CHANNEL* effg_pchannel[EFFSD_END];
};
#endif
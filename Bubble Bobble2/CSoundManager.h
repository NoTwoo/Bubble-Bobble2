#pragma once

#ifndef _SOUND_H_
#define _SOUND_H_
#include<Windows.h>
#include<fmod.h>
#pragma comment (lib, "fmodex_vc.lib")

enum SOUNDKIND
{
	MENUBGM = 0,
	STAGE1BGM,
	SD_END	
};

enum EFFSOUNDKIND
{
	ATTACK = 0,
	JUMP,
	ITEM_DROP,
	STUCK,
	EFFSD_END
};

class CSoundManager
{

public:
	void Initialize();
	void Release();

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

public:
	static CSoundManager* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new CSoundManager;

		return m_instance;
	}

private:
	CSoundManager() {};
	~CSoundManager();

	CSoundManager(const CSoundManager&) = delete;
	void operator=(const CSoundManager&) = delete;
	static CSoundManager* m_instance;

private:
	FMOD_SYSTEM* g_psystem;
	FMOD_SOUND* g_psound[SD_END];
	FMOD_CHANNEL* g_pchannel[SD_END];

	FMOD_SYSTEM* effg_psystem;
	FMOD_SOUND* effg_psound[EFFSD_END];
	FMOD_CHANNEL* effg_pchannel[EFFSD_END];
};
#endif
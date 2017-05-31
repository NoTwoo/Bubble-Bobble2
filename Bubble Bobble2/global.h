#pragma once

#include <stdio.h>
#include <iostream>
#include <map>
#include <atlimage.h>
#include <algorithm>
#include <iterator>
#include <windows.h>
#include <atlstr.h>
#include <Vfw.h>

using namespace std;

#include "CGameManager.h"
#include "CSceneManager.h"
#include "CSoundManager.h"
#include "CDBManager.h"
#include "CBitmapManager.h"
#include "CIntro.h"
#include "CMenu.h"

#include "CFactory.h"
#include "CObject.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CNPC.h"
#include "CScene.h"
#include "CStage1.h"
#include "macro.h"
#include "enum.h"
#include "CBubble.h"


///
#define GAMEMANAGER CGameManager::GetInstance()
#define SCENEMANAGER CSceneManager::GetInstance()
#define DBMANAGER CDBManager::GetInstance()
#define SOUNDMANAGER CSoundManager::GetInstance()
#define BITMAPMANAGER CBitmapManager::GetInstance()
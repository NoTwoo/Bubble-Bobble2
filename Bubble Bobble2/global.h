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
#include <time.h>
using namespace std;

#include "CGameManager.h"
#include "CSceneManager.h"
#include "CSoundManager.h"
#include "CDBManager.h"
#include "CBitmapManager.h"
#include "CIntro.h"
#include "CMenu.h"
#include "CObstacle.h"

#include "CFactory.h"
#include "CObject.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CNPC.h"
#include "CScene.h"
#include "CStage1.h"
#include "CStage2.h"
#include "CStage3.h"
#include "CStage4.h"
#include "CStage5.h"
#include "macro.h"
#include "enum.h"
#include "CBubble.h"
#include "CItem.h"
#include "CFood.h"
#include "CHelp.h"
#include "CGameOver.h"

///
#define GAMEMANAGER CGameManager::GetInstance()
#define SCENEMANAGER CSceneManager::GetInstance()
#define DBMANAGER CDBManager::GetInstance()
#define SOUNDMANAGER CSoundManager::GetInstance()
#define BITMAPMANAGER CBitmapManager::GetInstance()
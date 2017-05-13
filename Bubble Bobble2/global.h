#pragma once

#include <stdio.h>
#include <iostream>
#include <map>
#include<windows.h>

using namespace std;

#include "CGameManager.h"
#include "CSceneManager.h"
#include "CSoundManager.h"
#include "CDBManager.h"
#include "CBitmapManager.h"

#include "CFactory.h"
#include "CObject.h"
#include "CScene.h"
#include "CBitmap.h"
#include "macro.h"

///
#define GAMEMANAGER CGameManager::GetInstance()
#define SCENEMANAGER CSceneManager::GetInstance()
#define DBMANAGER CDBManager::GetInstance()
#define SOUNDMANAGER CSoundManager::GetInstance()
#define BITMAPMANAGER CBitmapManager::GetInstance()
#define FACTORY CFactory::GetInstance()
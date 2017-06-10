v0.1170513: Build Up Frame Work
v0.1170524: Build Up Frame Work And Intro
v0.5170610: Stage1 Complete




처음으로 해야되는게   CSceneManager.cpp 들어가서 
setState 함수에서 추가할 스테이지를 만들어준다.
만들어주고  스테이지에 따른 메크로.h 가서 몬스터 숫자를 추가 해준다  

Stage폴더 우클릭 -> CStage숫자.h 및 cpp를 추가
globl.h 가서 새로 추가된 헤더파일 추가

전에 있던 Stage h, cpp 내용 복사하여 붙여 넣기

새로만든 CStage숫자.h, cpp 가서 숫자 변경

void CStage2::ObstacleInitialize() 함수에서 장애물 배치

전 Stage.cpp에 있는 SCENE_ID CStage1::Update()로 이동
return STAGE숫자 변경

장애물 배치가 제대로 되었는지 확인

CMenu.cpp로 이동

case MENUTYPE::GAME_START: return stage 숫자 변경
테스트 하면서 장애물 좌표 바꾼다.

Tip 장애물 간의 Y좌표 차이는 110

정 안되면
CObstacle.cpp 가서 //Rectangle 주석 해제 한다 

ㅊㅋㅊㅋ 장애물 끝 다시 Rectangle 주석

이제 void CStage1::NPCInitialize() 로 이동
NUM_OF_STAGE1_MONSTER_NUM에서 STAGE 숫자 바꾸고
global 에 추가 

컴파일 -> NPC가 제대로 움직이는지 확인

SCENE_ID CStage2::Update() 이동

if (GAMEMANAGER->IsGameOver()) 주석 처리 // 무적 모드(테스트를 위해)

테스트 끝났으면 주석 해제
if (SCENEMANAGER->GetNPCNum() == 0) return menu를 return 다음 STAGE
예를 들어 현재 스테이지2 다음스테이지3 return STAGE3


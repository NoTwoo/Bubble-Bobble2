v0.1170513: Build Up Frame Work
v0.1170524: Build Up Frame Work And Intro
v0.5170610: Stage1 Complete




ó������ �ؾߵǴ°�   CSceneManager.cpp ���� 
setState �Լ����� �߰��� ���������� ������ش�.
������ְ�  ���������� ���� ��ũ��.h ���� ���� ���ڸ� �߰� ���ش�  

Stage���� ��Ŭ�� -> CStage����.h �� cpp�� �߰�
globl.h ���� ���� �߰��� ������� �߰�

���� �ִ� Stage h, cpp ���� �����Ͽ� �ٿ� �ֱ�

���θ��� CStage����.h, cpp ���� ���� ����

void CStage2::ObstacleInitialize() �Լ����� ��ֹ� ��ġ

�� Stage.cpp�� �ִ� SCENE_ID CStage1::Update()�� �̵�
return STAGE���� ����

��ֹ� ��ġ�� ����� �Ǿ����� Ȯ��

CMenu.cpp�� �̵�

case MENUTYPE::GAME_START: return stage ���� ����
�׽�Ʈ �ϸ鼭 ��ֹ� ��ǥ �ٲ۴�.

Tip ��ֹ� ���� Y��ǥ ���̴� 110

�� �ȵǸ�
CObstacle.cpp ���� //Rectangle �ּ� ���� �Ѵ� 

�������� ��ֹ� �� �ٽ� Rectangle �ּ�

���� void CStage1::NPCInitialize() �� �̵�
NUM_OF_STAGE1_MONSTER_NUM���� STAGE ���� �ٲٰ�
global �� �߰� 

������ -> NPC�� ����� �����̴��� Ȯ��

SCENE_ID CStage2::Update() �̵�

if (GAMEMANAGER->IsGameOver()) �ּ� ó�� // ���� ���(�׽�Ʈ�� ����)

�׽�Ʈ �������� �ּ� ����
if (SCENEMANAGER->GetNPCNum() == 0) return menu�� return ���� STAGE
���� ��� ���� ��������2 ������������3 return STAGE3


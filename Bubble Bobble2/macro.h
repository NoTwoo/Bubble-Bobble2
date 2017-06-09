#pragma once

#define WINDOWS_WIDTH 1280
#define WINDOWS_HEIGHT 720

#define END_OF_LEFT 25
#define END_OF_RIGHT 1239
#define START_OF_TOP 38
#define END_OF_TOP 65
#define END_OF_BOTTOM 800

#define NUM_OF_IMAGES 10
#define NUM_OF_MENU 6
#define NUM_OF_STAGE 1

#define NUM_OF_PLAYER_MOVE_IMG 8
#define NUM_OF_PLAYER_JUMP_IMG 8
#define NUM_OF_PLAYER_MOVE_JUMP_IMG 16

#define PLAYER_START_X 40
#define PLAYER_START_Y 591
#define PLAYER_MOVE_X_IMG 7
#define PLAYER_MOVE_Y_IMG 2
#define PLAYER_STUCK_TIME 5000

#define SPEED 20
#define NPC_SPEED 30
#define NPC_JUMP_SPEED 20
#define NPC_START_X 500
#define NPC_START_Y 120

#define NUM_OF_POINT_IMG 38
#define NUM_OF_FOOD_IMG 1

#define NUM_OF_PLAYER_BUBBLE_MOVE_IMG 7 
#define NUM_OF_BUBBLE_POP_IMG 6
#define NUM_OF_PLAYER_SHOOT_BUBBLE_IMG 4
#define NUM_OF_PLAYER_STUCK_IMG 8

#define NUM_OF_STAGE1_MONSTER_MOVE_JUMP_IMG 16
#define NUM_OF_STAGE1_MONSTER_MOVE_IMG 4
#define NUM_OF_STAGE1_MONSTER_JUMP_IMG 8
#define NUM_OF_STAGE1_MONSTER_NUM 2

#define NUM_OF_STAGE2_MONSTER_NUM 10

#define NUM_OF_MONSTER_STUCK_IMG 3


#define SAFE_DELETE(pointer) if(pointer) {delete pointer; pointer = NULL;}
#pragma once
#include "myhge.h"
#include "include/hgeanim.h"
#include "resourcesManager.h"

enum PLAYER_STATE{
	PS_IDLE,
	PS_WALK,
	PS_FALL,
	PS_JUMP,
	PS_COUNT,
};
enum PLAYER_FACE{
	PF_LEFT,
	PF_RIGHT,
};
class MyPlayer{
public:
	MyPlayer();
	~MyPlayer();
	void Init();
	void Render();
	void Frame();
	void SetState(PLAYER_STATE ps);
	void AniHandle(PLAYER_STATE ps);
	void keyHandle();
	void FaceHandle(PLAYER_FACE f);
private:
	PLAYER_FACE _face;
	PLAYER_STATE _state;
	float _x, _y;
	float _velocity;//ÒÆ¶¯ËÙ¶È
	hgeAnimation* _ani[PS_COUNT];
	hgeAnimation* _cur;
};


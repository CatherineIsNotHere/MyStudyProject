#pragma once
#include "g_object.h"
#include "hgeanim.h"

enum ROLE_STATE
{
	RS_IDLE_LEFT,
	RS_IDLE_RIGHT,
	RS_WALK_LEFT,
	RS_WALK_RIGHT,
	RS_JUMP_LEFT,
	RS_JUMP_RIGHT,
	RS_FALL,
	RS_COUNT,
};

class g_worms :public g_object{
public:
	g_worms();
	~g_worms();
	void Init();
	void Render();
	void Frame();
	void setX(float x);
	void setMoveX(float x);
	float getX();
private:
	hgeAnimation* w_anime[RS_COUNT];
	hgeAnimation* w_cur;
	int w_state;
	float w_x;
	float w_y;
	float w_move_x;
	float w_jump_time;
	float w_weight;//≥Ê◊”÷ ¡ø
};


#pragma once
#include "g_object.h"
#include "hgeanim.h"

enum ROLE_STATE
{
	RS_IDLE_LEFT,
	RS_IDLE_RIGHT,
	RS_WALK_LEFT,
	RS_WALK_RIGHT,
	RS_FALL,
	RS_JUMP,
	RS_COUNT,
};

class g_role:public g_object{
public:
	g_role();
	~g_role();
	void Init();
	void Render();
	void Frame();
private:
	hgeAnimation* r_anime[RS_COUNT];
	hgeAnimation* r_cur;
	float r_x;
	float r_y;
	int r_state;
};


#pragma once
#include "g_object.h"
#include "hgeanim.h"

enum WEAPON_STATE
{
	WPS_NONE,
	WPS_IDLE_LEFT,
	WPS_IDLE_RIGHT,
	WPS_WALK_LEFT,
	WPS_WALK_RIGHT,
	WPS_COUNT,
};

class g_weapon:public g_object{
public:
	g_weapon();
	~g_weapon();
	void Init();
	void Render();
	void Frame();
	void setX(float);
	float getX();
	float getY();
	int getWPState();
	float getWPRot();
	void setMoveX(float);
	void compelFlush();
private:
	hgeAnimation* wp_anime[WPS_COUNT];
	hgeAnimation* wp_cur;
	float wp_x;
	float wp_y;
	float wp_moveX;
	int wp_state;
	float wp_rot;
	float wp_hotpotX;
	float wp_hotpotY;
	bool wp_radReversal;
};
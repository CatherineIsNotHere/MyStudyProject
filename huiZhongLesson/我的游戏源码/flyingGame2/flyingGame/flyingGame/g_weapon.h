#pragma once
#include "g_object.h"
#include "hgeanim.h"

enum WEAPON_STATE
{
	WPS_NONE,
	WPS_IDLE_LEFT,
	WPS_IDLE_RIGHT,
	WPS_COUNT,
};

class g_weapon:public g_object{
public:
	g_weapon();
	~g_weapon();
	void Init();
	void Render();
	void Frame();
private:
	hgeAnimation* wp_anime[WPS_COUNT];
	hgeAnimation* wp_cur;
	float wp_x;
	float wp_y;
	int wp_state;

};
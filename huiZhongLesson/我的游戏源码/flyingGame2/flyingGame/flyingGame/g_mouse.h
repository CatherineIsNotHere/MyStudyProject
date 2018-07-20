#pragma once
#include "hgesprite.h"
#include "g_object.h"


class g_mouse:public g_object{
public:
	g_mouse();
	~g_mouse();
	void Init();
	void Render();
	void Frame();
	float getX();
private:
	hgeSprite* ms_sprite;
	float ms_x;
	float ms_y;
};
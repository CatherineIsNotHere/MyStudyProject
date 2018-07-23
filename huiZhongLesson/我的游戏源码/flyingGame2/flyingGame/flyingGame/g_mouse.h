#pragma once
#include "hgesprite.h"


class g_mouse{
public:
	void Init();
	void Render();
	void Frame();
	float getX();
private:
	hgeSprite* ms_sprite;
	float ms_x;
	float ms_y;
};
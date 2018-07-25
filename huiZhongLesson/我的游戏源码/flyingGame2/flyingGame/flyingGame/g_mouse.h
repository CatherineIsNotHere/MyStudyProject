#pragma once
#include "hgesprite.h"

#define mymouse g_mouse::Instance() 

class g_mouse{
public:
	g_mouse();
	~g_mouse();
	void Init();
	void Render();
	void Frame();
	static g_mouse& Instance();
	float getX();
private:
	hgeSprite* ms_sprite;
	float ms_x;
	float ms_y;
};
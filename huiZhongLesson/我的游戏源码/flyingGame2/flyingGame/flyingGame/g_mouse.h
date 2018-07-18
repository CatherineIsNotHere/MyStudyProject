#pragma once
#include "hge.h"
#include "hgesprite.h"
#include "string"
using namespace std;
#include "g_object.h"
#include "g_resourceManager.h"

class g_mouse:public g_object{
public:
	g_mouse();
	~g_mouse();
	void Init();
	void Render();
	void Frame();
	
private:
	hgeSprite* ms_sprite;
	float ms_x;
	float ms_y;

};
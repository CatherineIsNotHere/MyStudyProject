#pragma once
#include "hge.h"
#include "hgesprite.h"
#include "g_object.h"
#include "g_resourceManager.h"
#include "string"
using namespace std;

class g_maps:public g_object{
public:
	g_maps();
	~g_maps();
	void Init();
	void Render();
private:
	hgeSprite* m_sprites;
	float m_x;
	float m_y;
};
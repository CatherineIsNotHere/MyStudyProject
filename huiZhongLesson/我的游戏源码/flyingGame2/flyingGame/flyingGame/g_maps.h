#pragma once
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
	void setX(float x);
	void setY(float y);
	void setMoveX(float x);
private:
	hgeSprite* m_sprites;
	float m_x;
	float m_y;
	float m_move_x;
};
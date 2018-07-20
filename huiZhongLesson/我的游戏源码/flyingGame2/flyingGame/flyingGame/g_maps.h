#pragma once
#include "hgesprite.h"
#include "g_object.h"

class g_maps:public g_object{
public:
	g_maps();
	~g_maps();
	void Init();
	void Render();
	void setX(float x);
	float getX();
	void setY(float y);
	void setMoveX(float x);
private:
	hgeSprite* m_sprites;
	float m_x;
	float m_y;
	float m_move_x;
};
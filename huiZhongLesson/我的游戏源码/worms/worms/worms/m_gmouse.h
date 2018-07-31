#pragma once
#include "g_object.h"
#include "hgesprite.h"
#define mymouse m_gmouse::Instance() 

class m_gmouse:public g_object{
public:
	m_gmouse();
	~m_gmouse();
	void Init();
	void Frame();
	void Render();
	float getX();
	static m_gmouse& Instance();
private:
	hgeSprite* ms_sprite;
	float ms_x;
	float ms_y;
};
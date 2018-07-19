#pragma once
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
	float getMoveX();
	float getOverMoveX();
private:
	hgeSprite* ms_sprite;
	float ms_x;
	float ms_y;
	float ms_click_x;//�����ʱ��¼x����Ļ�е�����
	float ms_move_x;//����϶�ʱ��¼x�϶�����
	float ms_overmove_x;//�������϶�ʱ��¼�ܹ��϶��ľ���

};
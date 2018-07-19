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
	float ms_click_x;//鼠标点击时记录x在屏幕中的坐标
	float ms_move_x;//鼠标拖动时记录x拖动距离
	float ms_overmove_x;//鼠标结束拖动时记录总共拖动的距离

};
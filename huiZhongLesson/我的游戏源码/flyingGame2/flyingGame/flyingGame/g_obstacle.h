#pragma once
#include "hge.h"
#include "hgesprite.h"
#include "dx_hge.h"
#include "g_object.h"
#include "config.h"


class g_obstacle:public g_object{
public:
	g_obstacle();
	~g_obstacle();
	void Render();
	void PaintRect();//»­·½¿é
	void setMoveX(float x);
	void updateDragMove();
	int beImpacted(const hgeRect*);
	int checkRect(const hgeRect*);
	hgeRect* o_rect[O_NUM];
private:
	
	float o_move_x;
};
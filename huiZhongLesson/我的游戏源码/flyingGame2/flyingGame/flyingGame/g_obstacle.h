#pragma once
#include "hge.h"

#include "dx_hge.h"
#include "g_object.h"
#include "config.h"


class g_obstacle:public g_object{
public:
	g_obstacle();
	~g_obstacle();
	void Render();
	void PaintRect(bool paintLine);
private:
	hgeQuad* rect[O_NUM];//定义n个矩形
	bool o_paintLine;
};
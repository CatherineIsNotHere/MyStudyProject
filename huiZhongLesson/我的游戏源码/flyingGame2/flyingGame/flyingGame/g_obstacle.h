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
	void PaintRect(bool paintLine);//»­·½¿é
private:
	hgeRect* rect[O_NUM];
	bool o_paintLine;
};
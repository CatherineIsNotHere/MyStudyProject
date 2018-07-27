#pragma once
#include "g_obstacle.h"
#include "pys_asvt.h"
#include "config.h"

g_obstacle::g_obstacle()
:o_wormstay(999)
{
	hgeRect* r0 = new hgeRect(-10, 0, 0, 960);
	hgeRect* r1=new hgeRect(0,705,766,960);
	hgeRect* r2 = new hgeRect(482, 331, 988, 374);
	hgeRect* r3 = new hgeRect(817, 835, 1496, 960);
	hgeRect* r4 = new hgeRect(1088, 446, 1514, 490);
	hgeRect* r5 = new hgeRect(1592, 748, 1842, 960);
	hgeRect* r6 = new hgeRect(1894, 835, 2142, 960);
	hgeRect* r7 = new hgeRect(1942, 264, 2450, 440);
	hgeRect* r8 = new hgeRect(2142, 707, 2560, 960);
	hgeRect* r9 = new hgeRect(2560, 0, 2570, 960);
	o_rect[0] = r0;
	o_rect[1] = r1;
	o_rect[2] = r2;
	o_rect[3] = r3;
	o_rect[4] = r4;
	o_rect[5] = r5;
	o_rect[6] = r6;
	o_rect[7] = r7;
	o_rect[8] = r8;
	o_rect[9] = r9;
	o_move_x = .0f;
}

g_obstacle::~g_obstacle()
{

}

void g_obstacle::Render()
{
	PaintRect();
}

/*
	函数名：PaintRect
	参数：是否显示线条
*/
void g_obstacle::PaintRect()
{
	bool paint = getPaintLine();
	if (!getPaintLine())
		return;
	for (auto r : o_rect){
		myhge.getHGE()->Gfx_RenderLine(r->x1+o_move_x, r->y1, r->x2+o_move_x, r->y1, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(r->x2+o_move_x, r->y1, r->x2+o_move_x, r->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(r->x2+o_move_x, r->y2, r->x1+o_move_x, r->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(r->x1+o_move_x, r->y2, r->x1+o_move_x, r->y1, 0xffff00ff);
	}
	return;
}

void g_obstacle::setMoveX(float x)
{
	o_move_x = x;
}

void g_obstacle::updateDragMove()
{
	for (auto r : o_rect){
		r->x1 += o_move_x;
		r->x2 += o_move_x;
	}
}

int g_obstacle::beImpacted(const hgeRect* other)
{
	int impactedState = IM_NONE;
	int impactedFirst = IM_NONE;//碰撞点至多为2个因为只有四个边
	int impactedSecond = IM_NONE;
	int i = 0;
	for (auto rc : o_rect)
	{
		impactedState = myIntersect(other, rc);
		if (impactedFirst == IM_NONE){
			impactedFirst = impactedState;
		}
		else{
			impactedSecond = impactedState;
		}
		if (impactedState / 1000 % 10 == 9){//找寻虫子正在站立的障碍物
			o_wormstay = i;
		}
		impactedState = IM_NONE;
		i++;
	}
	return impactedFirst + impactedSecond;
}
////检查是否嵌入(上下)
int g_obstacle::checkRect(const hgeRect* other)
{
	int rectlr=0;
	int rectud = 0;
	if (o_wormstay>=0&&o_wormstay<O_NUM){
		rectud = inRectUD(other, o_rect[o_wormstay]);
	}
	if (rectud!=0){
		return rectud;
	}
	return IN_NONE;
}



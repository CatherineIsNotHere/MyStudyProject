#include "g_obstacle.h"

g_obstacle::g_obstacle()
:o_paintLine(O_LINE)
{
	hgeRect* r0=new hgeRect(0,705,766,960);
	hgeRect* r1 = new hgeRect(817, 835, 1496, 960);
	hgeRect* r2 = new hgeRect(1592, 748, 1842, 960);
	hgeRect* r3 = new hgeRect(1894, 835, 2142, 960);
	hgeRect* r4 = new hgeRect(2142, 707, 2560, 960);
	hgeRect* r5 = new hgeRect(482, 331, 988, 374);
	hgeRect* r6 = new hgeRect(1088, 446, 1514, 490);
	hgeRect* r7 = new hgeRect(1942, 264, 2450, 440);
	rect[0] = r0;
	rect[1] = r1;
	rect[2] = r2;
	rect[3] = r3;
	rect[4] = r4;
	rect[5] = r5;
	rect[6] = r6;
	rect[7] = r7;
	o_move_x = .0f;
}

g_obstacle::~g_obstacle()
{

}

void g_obstacle::Render()
{
	PaintRect(o_paintLine);
}

/*
	函数名：PaintRect
	参数：是否显示线条
*/
void g_obstacle::PaintRect(bool paintLine)
{
	if (!paintLine)
		return;
	for (auto r:rect){
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

void g_obstacle::updateMove()
{
	for (auto r : rect){
		r->x1 += o_move_x;
		r->x2 += o_move_x;
	}
}

hgeRect* g_obstacle::getRects()
{
	return rect[0];
}

void g_obstacle::setPaintLine(bool b)
{
	o_paintLine = b;
}

bool g_obstacle::getPaintLine()
{
	return o_paintLine;
}

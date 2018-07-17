#include "g_obstacle.h"

g_obstacle::g_obstacle()
:o_paintLine(O_LINE)
{
	hgeRect* r=new hgeRect(0,0,5,570);
	rect[0] = r;
}

g_obstacle::~g_obstacle()
{

}

void g_obstacle::Render()
{
	PaintRect(o_paintLine);
}

/*
	��������PaintRect
	�������Ƿ���ʾ����
*/
void g_obstacle::PaintRect(bool paintLine)
{
	if (!paintLine)
		return;
	for (auto r:rect){
		myhge.getHGE()->Gfx_RenderLine(r->x1, r->y1, r->x2, r->y1, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(r->x2, r->y1, r->x2, r->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(r->x2, r->y2, r->x1, r->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(r->x1, r->y2, r->x1, r->y1, 0xffff00ff);
	}
	return;
}

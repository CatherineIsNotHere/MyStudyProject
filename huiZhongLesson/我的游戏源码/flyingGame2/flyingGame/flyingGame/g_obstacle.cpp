#include "g_obstacle.h"

g_obstacle::g_obstacle()
:o_paintLine(O_LINE)
{
	/*rect[0]->v[0] = {0,400};
	rect[0]->v[0] = { 0, 400 };*/
}

g_obstacle::~g_obstacle()
{

}

void g_obstacle::Render()
{
	PaintRect(o_paintLine);
}

void g_obstacle::PaintRect(bool paintLine)
{
	if (!paintLine)
		return;
	for (hgeQuad* r : rect){
		myhge.getHGE()->Gfx_RenderQuad(r);
	}
}

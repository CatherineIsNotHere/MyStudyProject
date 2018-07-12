#include "map.h"
#include "myhge.h"

CMap::CMap()
{

}

CMap::~CMap()
{
	myhge.FreeTex(tex);
	delete spr;
}


void CMap::Init()
{
	tex = myhge.LoadTex(".\\snowbro\\map.png");
	spr = new hgeSprite(tex, 0, 0, BASESCREENW, BASESCREENH);
}

void CMap::Render()
{
	spr->Render(0, 0);
}


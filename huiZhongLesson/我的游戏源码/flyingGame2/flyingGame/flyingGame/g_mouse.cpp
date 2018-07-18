#pragma once
#include "g_mouse.h"

g_mouse::g_mouse()
{

}

g_mouse::~g_mouse()
{

}

void g_mouse::Init()
{
	ms_sprite=resMgr.getSprite("ЪѓБъ.png", 0, 0, 15, 22);
	ms_sprite->SetZ(.5f);
	ms_x = 0;
	ms_y = 0;
}

void g_mouse::Render()
{
	ms_sprite->Render(ms_x, ms_y);
}

void g_mouse::Frame()
{

}

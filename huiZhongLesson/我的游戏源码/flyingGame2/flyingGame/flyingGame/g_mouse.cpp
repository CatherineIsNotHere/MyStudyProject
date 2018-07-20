#pragma once
#include "g_mouse.h"
#include "g_resourceManager.h"
g_mouse::g_mouse()
{
}

g_mouse::~g_mouse()
{

}

void g_mouse::Init()
{
	ms_sprite = resMgr.getSprite("ЪѓБъ.png", 0, 0, 42, 50);
	ms_x = 0;
	ms_y = 0;
}

void g_mouse::Render()
{
	ms_sprite->Render(ms_x, ms_y);
}

void g_mouse::Frame()
{
	myhge.getHGE()->Input_GetMousePos(&ms_x, &ms_y);
}

float g_mouse::getX()
{
	return ms_x;
}


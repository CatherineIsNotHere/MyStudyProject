#pragma once
#include "g_mouse.h"

g_mouse::g_mouse()
:ms_sprite(resMgr.getSprite("ЪѓБъ.png", 0, 0, 15, 22)),
ms_x(0),
ms_y(0),
ms_move_x(0),
ms_click_x(0),
ms_overmove_x(0)
{
	ms_sprite->SetZ(.5f);
}

g_mouse::~g_mouse()
{

}

void g_mouse::Init()
{
}

void g_mouse::Render()
{
	ms_sprite->Render(ms_x, ms_y);
}

void g_mouse::Frame()
{
	myhge.getHGE()->Input_GetMousePos(&ms_x, &ms_y);
	if (myhge.getHGE()->Input_KeyDown(HGEK_LBUTTON)){
		ms_click_x = ms_x;
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_LBUTTON)){
		ms_move_x = ms_x - ms_click_x;
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LBUTTON)){
		ms_click_x = 0;
	}
}

float g_mouse::getOverMoveX()
{
	return ms_overmove_x;
}

float g_mouse::getMoveX()
{
	return ms_move_x;
}

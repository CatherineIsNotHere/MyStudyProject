#pragma once
#include "g_maps.h"

g_maps::g_maps()
:m_sprites(resMgr.getSprite("°ÙÕ½Ìì³æ³õ¸å.png", 0, 0, 2560, 960)),
m_x(0),
m_y(0)
{
	m_sprites->SetZ(.4f);
}

g_maps::~g_maps()
{

}

void g_maps::Init()
{
}

void g_maps::Render()
{
	m_sprites->Render(m_x+m_move_x,m_y);
}

void g_maps::setX(float x)
{
	m_x = x;
}

void g_maps::setY(float y)
{
	m_y = y;
}

void g_maps::setMoveX(float x)
{
	m_move_x = x;
}


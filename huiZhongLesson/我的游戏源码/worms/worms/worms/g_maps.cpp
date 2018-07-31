#pragma once
#include "g_maps.h"
#include "g_resourceManager.h"
#include "config.h"

g_maps::g_maps()
{
}

g_maps::~g_maps()
{

}

void g_maps::Init()
{
	m_sprites = resMgr.getSprite("°ÙÕ½Ìì³æ³õ¸å.png", 0, 0, M_SCREEN_W, M_SCREEN_H);
	m_x = -M_WALL_W;
	m_y = 0;
	m_move_x = 0;
}

void g_maps::Render()
{
	m_sprites->Render(m_x+m_move_x,m_y);
}

void g_maps::setX(float x)
{
	m_x = x;
}

float g_maps::getX()
{
	return m_x;
}

void g_maps::setY(float y)
{
	m_y = y;
}

void g_maps::setMoveX(float x)
{
	m_move_x = x;
}

float g_maps::getMoveX()
{
	return m_move_x;
}


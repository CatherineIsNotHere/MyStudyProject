#pragma once
#include "g_maps.h"

g_maps::g_maps()
{

}

g_maps::~g_maps()
{

}

void g_maps::Init()
{
	m_sprites=resMgr.getSprite("°ÙÕ½Ìì³æ³õ¸å.png",0,0,2560,960);
	m_sprites->SetZ(.4f);
	m_x = 0;
	m_y = 0;
}

void g_maps::Render()
{
	m_sprites->Render(m_x,m_y);
}

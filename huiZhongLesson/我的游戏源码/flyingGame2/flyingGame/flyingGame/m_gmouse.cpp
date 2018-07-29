#pragma once
#include "m_gmouse.h"
#include "g_resourceManager.h"
#include "dx_hge.h"

m_gmouse::m_gmouse()
{

}

m_gmouse::~m_gmouse()
{

}

void m_gmouse::Init()
{
	ms_sprite = resMgr.getSprite("ЪѓБъ.png", 0, 0, 42, 50);
	ms_x = 0;
	ms_y = 0;
}

void m_gmouse::Frame()
{
	myhge.getHGE()->Input_GetMousePos(&ms_x, &ms_y);
}

void m_gmouse::Render()
{
	ms_sprite->Render(ms_x, ms_y);
}

float m_gmouse::getX()
{
	return ms_x;
}

m_gmouse& m_gmouse::Instance()
{
		static Poco::SingletonHolder<m_gmouse> mmouse;
		return *mmouse.get();
}


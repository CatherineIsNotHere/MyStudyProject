#pragma once
#include "m_game.h"
#include "dx_hge.h"

m_game::m_game()
{

}

m_game::~m_game()
{

}

void m_game::Init()
{
	maps.Init();
	mouse.Init();
	roles.Init();
}

void m_game::clean()
{

}

bool m_game::Frame()
{
	mygame.mouseDrag();
	mygame.roles.Frame();
	mygame.mouse.Frame();
	if (myhge.getKeyState(HGEK_ESCAPE)){
		return true;
	}
	return false;
}

bool m_game::Render()
{
	myhge.BeginRender(0xffffff);
	//mygame.obs.Render();
	mygame.maps.Render();
	mygame.roles.Render();
	mygame.mouse.Render();
	myhge.EndRender();
	return false;
}

m_game& m_game::Instance()
{
	static Poco::SingletonHolder<m_game> mgame;
	return *mgame.get();
}

void m_game::Run()
{
	myhge.setProc(Frame,Render);
	mygame.Init();
	myhge.Start();
}

void m_game::mouseDrag()
{
	if (myhge.getHGE()->Input_KeyDown(HGEK_LBUTTON)){
		ms_overmove_x = .0f;
		ms_move_x = .0f;
		ms_click_x = mygame.mouse.getX();
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_LBUTTON)){
		ms_move_x = mygame.mouse.getX()-ms_click_x;
		mygame.maps.setMoveX(ms_move_x);
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LBUTTON)){
		ms_overmove_x=ms_move_x;
		mygame.maps.setX(mygame.maps.getX()+ms_overmove_x);
		mygame.maps.setMoveX(0);
	}

}

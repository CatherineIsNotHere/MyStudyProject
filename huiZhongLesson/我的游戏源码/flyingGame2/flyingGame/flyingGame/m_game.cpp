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
	worms.Init();
}

void m_game::clean()
{

}

bool m_game::Frame()
{
	mygame.worms.Frame();
	mygame.mouse.Frame();
	mygame.mouseDrag();
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
	mygame.worms.Render();
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
	if (myhge.getHGE()->Input_KeyDown(HGEK_LBUTTON)){//鼠标按下记录按下坐标
		ms_overmove_x = .0f;
		ms_move_x = .0f;
		ms_click_x = mygame.mouse.getX();
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_LBUTTON)){//鼠标拖动记录位移距离
		ms_move_x = mygame.mouse.getX()-ms_click_x;
		mygame.maps.setMoveX(ms_move_x);
		mygame.worms.setMoveX(ms_move_x);
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LBUTTON)){//鼠标拖动结束将真实坐标传入对象
		ms_overmove_x=ms_move_x;
		mygame.maps.setX(mygame.maps.getX()+ms_overmove_x);
		mygame.maps.setMoveX(0);
		mygame.worms.setX(mygame.worms.getX() + ms_overmove_x);
		mygame.worms.setMoveX(0);
	}

}

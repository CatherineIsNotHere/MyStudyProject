#include "m_game.h"

m_game::m_game()
{

}

m_game::~m_game()
{

}

void m_game::Init()
{

}

void m_game::clean()
{

}

bool m_game::Frame()
{

	if (myhge.getKeyState(HGEK_ESCAPE)){
		return true;
	}
	return false;
}

bool m_game::Render()
{
	myhge.BeginRender(0xffffff);
	mygame.obs.Render();
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

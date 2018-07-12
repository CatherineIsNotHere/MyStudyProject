#pragma once
#include "game.h"
#include "myhge.h"
#include <Poco/SingletonHolder.h>
#include "resourcesManager.h"

CGame::CGame()
{
	
	
}

CGame::~CGame()
{

}

void CGame::Init()
{
	pmap = new CGameMap();
	pmap->Init();

	bulletMgr.Init();
	bulletMgr.Add(0, 0);
	bulletMgr.Add(0, 100);
	bulletMgr.Add(0, 200);
}

void CGame::Clean()
{
	bulletMgr.Clean();
	resMgr.Clear();
}

bool CGame::Frame()
{
	if (phge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	mygame.bulletMgr.Update();
	return false;
}

bool CGame::Render()
{
	myhge.BeginRender(0);
	mygame.pmap->Render();
	mygame.bulletMgr.Render();

	myhge.EndRender();
	return false;
}

CGame& CGame::Instance()
{
	static Poco::SingletonHolder<CGame> sh;
	return *sh.get();
}

void CGame::Run()
{
	myhge.SetProc(Frame, Render);
	mygame.Init();
	myhge.Start();
}


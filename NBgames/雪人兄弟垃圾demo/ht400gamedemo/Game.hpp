#pragma once
#include "HGEsingleton.hpp"
#include <Poco/SingletonHolder.h>
#include "Map.hpp"
#include "player.hpp"
#include <iostream>
class CGame
{
public:
	CGame()
	{
		
	}
	~CGame()
	{

	}

	void Run()
	{
		HGEsgt::Instance().SetProc(&CGame::RenderFunc, &CGame::FrameFunc);
		_map.Init();
		_player.Init(&_map);
		HGEsgt::Instance().Start();
	}

	static bool RenderFunc()
	{
		HGEsgt::Instance().BeginRender(0xff888888);
		CGame::Instance()._map.Render();
		CGame::Instance()._player.Render();
		HGEsgt::Instance().EndRender();
		return false;
	}

	static bool FrameFunc()
	{
		CGame::Instance()._player.Frame();
		if (HGEsgt::Instance().GetHGE()->Input_GetKeyState(HGEK_ESCAPE)) return true;
		return false;
	}

	CMap* GetMap()
	{
		return &_map;
	}

	static CGame& Instance()
	{
		static Poco::SingletonHolder<CGame> sh;
		return *sh.get();
	}
private: // 不能类外调用拷贝构造与赋值操作符
	CGame(const CGame&);
	CGame& operator = (const CGame&);
protected:
	CMap _map;
	CPlayer _player;
};

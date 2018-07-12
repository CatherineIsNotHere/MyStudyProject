#pragma once
#include "CGameMap.h"
#include "bullet.h"
#include "player.h"

#define mygame CGame::Instance()
class CGame
{
public:
	CGame();
	~CGame();
	void Init();
	void Clean();
	static bool Frame();
	static bool Render();
	static CGame& Instance();
	void Run();

	CGameMap* pmap;
	CbulletManager bulletMgr;

private:
	CGame(const CGame&);// ����������ÿ��������븳ֵ������
	CGame& operator = (const CGame&);
};
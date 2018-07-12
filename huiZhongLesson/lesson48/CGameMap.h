#pragma once
#include "include/hgeSprite.h"

class CGameMap
{
public:
	CGameMap();
	~CGameMap();

	void Init();
	void Render();
protected:
	hgeSprite* spr;
};

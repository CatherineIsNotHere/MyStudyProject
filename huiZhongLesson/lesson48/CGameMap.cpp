#pragma once
#include "CGameMap.h"
#include "myhge.h"
#include "resourcesManager.h"

CGameMap::CGameMap()
{

}

CGameMap::~CGameMap()
{

}


void CGameMap::Init()
{
	spr = resMgr.GetSpr(".\\snowbro\\ditu.bmp", 0, 0, 1024, 448);
}

void CGameMap::Render()
{
	spr->Render(0, 0);
}


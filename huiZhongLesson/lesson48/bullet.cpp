#pragma once
#include "bullet.h"
#include "myhge.h"
#include "resourcesManager.h"

CBullet::CBullet()
{

}

CBullet::~CBullet()
{
	
}

void CBullet::Init(float x, float y)
{
	spr = resMgr.GetSpr(".\\snowbro\\bullet.png", 0, 0, 36, 36);
	_x = x;
	_y = y;
}

void CBullet::Render()
{
	spr->Render(_x, _y);
}

void CBullet::Update()
{
	_x += 0.1f;
}

CbulletManager::CbulletManager()
{

}

CbulletManager::~CbulletManager()
{

}

void CbulletManager::Init()
{

}

void CbulletManager::Clean()
{
	for (auto b : _lst)
	{
		delete b;
		b = nullptr;
	}
	_lst.clear();
}

void CbulletManager::Add(float x, float y)
{
	CBullet* p = new CBullet();
	p->Init(x, y);
	_lst.push_back(p);
}

void CbulletManager::Render()
{
	for (auto b : _lst)
	{
		b->Render();
	}
}

void CbulletManager::Update()
{
	for (auto b : _lst)
	{
		b->Update();
	}
}

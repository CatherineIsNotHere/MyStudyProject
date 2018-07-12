#pragma once
#include "include/hgeSprite.h"
#include <list>
using namespace std;

class CBullet
{
public:
	CBullet();
	~CBullet();
	void Init(float x, float y);
	void Render();
	void Update();
private:
	hgeSprite* spr;
	float _x;
	float _y;
};

class CbulletManager
{
public:
	CbulletManager();
	~CbulletManager();
	void Init();
	void Clean();

	void Add(float x, float y);
	void Render();
	void Update();

protected:
	list<CBullet*> _lst;
};
#pragma once
#include <Poco/SingletonHolder.h>
#include "include/hge.h"
#include "include/hgesprite.h"
#include "include/hgeanim.h"
#include <string>
#include <map>
using namespace std;

#define resMgr CResourcesManager::Instance()
class CResourcesManager
{
public:
	CResourcesManager();
	~CResourcesManager();
	void Init();
	void Clear();
	static CResourcesManager& Instance();

	HTEXTURE GetTex(const string&);
	hgeSprite* GetSpr(const string&, float x, float y, float w, float h);
	hgeAnimation* GetAni(const string&, int frames, float fps, float x, float y, float w, float h);
private:
	map<string, HTEXTURE> _mapTex;
	map<string, hgeSprite*> _mapSpr;
	map<string, hgeAnimation*> _mapAni;
};
 
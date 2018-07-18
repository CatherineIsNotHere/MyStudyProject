#pragma once
#include "hge.h"
#include "hgesprite.h"
#include "hgeanim.h"
#include "string"
#include "map"
#include "dx_hge.h"
using namespace std;
#define resMgr g_resourceManager::Instance()

class g_resourceManager{
public:
	g_resourceManager();
	~g_resourceManager();
	void Init();
	void Clear();
	static g_resourceManager& Instance();

	HTEXTURE getTex(const string&);
	hgeSprite* getSprite(const string&,float x,float y,float w,float h);
	hgeAnimation* getAnimation(const string&,int frames,float fps,float x,float y,float w,float h);
private:
	map<string, HTEXTURE> r_textures;
	map<string, hgeSprite*> r_sprite;
	map<string, hgeAnimation*> r_animation;
};
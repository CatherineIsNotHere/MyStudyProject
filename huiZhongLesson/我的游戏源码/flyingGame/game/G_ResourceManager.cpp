//#pragma once
//#include <Poco/SingletonHolder.h>
//#include "hge.h"
//#include "hgesprite.h"
//#include "hgeanim.h"
//#include <string>
//#include <map>
//using namespace std;
//#define resMgr CResourcesManager::Instance()
//class CResourcesManager
//{
//public:
//	CResourcesManager();
//	~CResourcesManager();
//	void Init();
//	void Clear();
//	static CResourcesManager& Instance(){
//		static Poco::SingletonHolder<CResourcesManager> sh;
//		return *sh.get();
//	}
//
//	HTEXTURE GetTex(const string& k){
//		auto it = _mapTex.find(k);
//		if (it != _mapTex.end())
//		{
//			return it->second;
//		}
//		//auto t = myhge.LoadTex(k.c_str());
//		_mapTex[k] = t;
//		return t;
//	}
//
//
//	hgeSprite* GetSpr(const string& k, float x, float y, float w, float h){
//		auto it = _mapSpr.find(k);
//		if (it != _mapSpr.end())
//		{
//			return it->second;
//		}
//
//		auto t = GetTex(k);
//		auto s = new hgeSprite(t, x, y, w, h);
//		_mapSpr[k] = s;
//		return s;
//	}
//
//
//	hgeAnimation* GetAni(const string&, int frames, float fps, float x, float y, float w, float h);
//private:
//	map<string, HTEXTURE> _mapTex;
//	map<string, hgeSprite*> _mapSpr;
//	map<string, hgeAnimation*> _mapAni;
//};
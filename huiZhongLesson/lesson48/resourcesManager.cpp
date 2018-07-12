#pragma once
#include "resourcesManager.h"
#include "myhge.h"
CResourcesManager::CResourcesManager()
{

}

CResourcesManager::~CResourcesManager()
{

}

void CResourcesManager::Init()
{

}

void CResourcesManager::Clear()
{
	for (auto t : _mapAni)
	{
		delete t.second;
	}
	_mapAni.clear();

	for (auto t : _mapSpr)
	{
		delete t.second;
	}
	_mapSpr.clear();

	for (auto t : _mapTex)
	{
		myhge.FreeTex(t.second);
	}
	_mapTex.clear();
}

CResourcesManager& CResourcesManager::Instance()
{
	static Poco::SingletonHolder<CResourcesManager> sh;
	return *sh.get();
}

HTEXTURE CResourcesManager::GetTex(const string& k)
{
	auto it = _mapTex.find(k);
	if (it != _mapTex.end())
	{
		return it->second;
	}
	auto t = myhge.LoadTex(k.c_str());
	_mapTex[k] = t;
	return t;
}

hgeSprite* CResourcesManager::GetSpr(const string& k, float x, float y, float w, float h)
{
	auto it = _mapSpr.find(k);
	if (it != _mapSpr.end())
	{
		return it->second;
	}

	auto t = GetTex(k);
	auto s = new hgeSprite(t, x, y, w, h);
	_mapSpr[k] = s;
	return s;
}

hgeAnimation* CResourcesManager::GetAni(const string& k, int frames, float fps, float x, float y, float w, float h)
{
	auto it = _mapAni.find(k);
	if (it != _mapAni.end())
	{
		return it->second;
	}

	auto t = GetTex(k);
	auto a = new hgeAnimation(t, frames, fps, x, y, w, h);
	_mapAni[k] = a;
	return a;
}
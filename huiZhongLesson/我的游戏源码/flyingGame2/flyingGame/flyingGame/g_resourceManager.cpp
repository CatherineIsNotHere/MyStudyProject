#pragma once
#include "g_resourceManager.h"

g_resourceManager::g_resourceManager()
{

}

g_resourceManager::~g_resourceManager()
{

}

void g_resourceManager::Init()
{
}

void g_resourceManager::Clear()
{
	for (auto r:r_sprite)
	{
		delete r.second;
	}
	r_sprite.clear();
	for (auto r:r_animation)
	{
		delete r.second;
	}
	r_animation.clear();
	for (auto r : r_textures)
	{
		myhge.FreeTex(r.second);
	}
	r_textures.clear();
}

g_resourceManager& g_resourceManager::Instance()
{
	static Poco::SingletonHolder<g_resourceManager> rm;
	return *rm.get();
}

HTEXTURE g_resourceManager::getTex(const string& k)
{
	auto it = r_textures.find(k);
	if (it!=r_textures.end()){
		return it->second;
	}
	auto tex = myhge.LoadTex(k.c_str());
	r_textures[k] = tex;
	return tex;
}

hgeSprite* g_resourceManager::getSprite(const string& k, float x, float y, float w, float h)
{
	auto it = r_sprite.find(k);
	if (it!=r_sprite.end()){
		return it->second;
	}
	auto tex= getTex(k);
	auto spirit = new hgeSprite(tex,x,y,w,h);
	r_sprite[k] = spirit;
	return spirit;
}

hgeAnimation* g_resourceManager::getAnimation(const string& k, int frames, float fps, float x, float y, float w, float h)
{
	auto it = r_animation.find(k);
	if (it!=r_animation.end())
	{
		return it->second;
	}
	auto tex = getTex(k);
	auto animation = new hgeAnimation(tex,frames,fps,x,y,w,h);
	r_animation[k] = animation;
	return animation;
}


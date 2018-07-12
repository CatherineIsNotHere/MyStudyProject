#pragma once
#include "myhge.h"
#include <Poco/SingletonHolder.h>

MyHGE::MyHGE()
{
	hge = hgeCreate(HGE_VERSION);// 使用hgeCreate函数创建HGE接口，参数必须传递正确的HGE_VERSION,它是在hge.h中定义的 
	hge->System_SetState(HGE_SCREENWIDTH, BASESCREENW);//将屏幕宽度设置为800 
	hge->System_SetState(HGE_SCREENHEIGHT, BASESCREENH);//将屏幕高度设置为600 
	hge->System_SetState(HGE_TITLE, "我的第一个HGE程序");//设置窗口标题为“我的第一个HGE程序” 
	hge->System_SetState(HGE_WINDOWED, true);//设置使用窗口模式 
	hge->System_SetState(HGE_USESOUND, false);//设置不使用声音（第一个程序我们先不讲解声音和图像的知识） 
	hge->System_SetState(HGE_SHOWSPLASH, false); // 解除掉程序开头HGE的LOGO
}

MyHGE::~MyHGE()
{
	hge->System_Shutdown();//程序停止 
	hge->Release();//释放HGE所占用的内存。 
}

void MyHGE::SetProc(hgeCallback ff, hgeCallback rf)
{
	hge->System_SetState(HGE_FRAMEFUNC, ff);//设置逻辑函数为FrameFunc函数 
	hge->System_SetState(HGE_RENDERFUNC, rf);//设置绘制函数为RenderFunc函数
	hge->System_Initiate();
}

void MyHGE::BeginRender(DWORD col)
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(col);//以某颜色清屏，OxFF000000为透明度为0的黑色
}

void MyHGE::EndRender()
{
	hge->Gfx_EndScene();
}

void MyHGE::Start()
{
	hge->System_Start();//如果没有问题，则使用System_Start方法，开始程序。 
}

MyHGE& MyHGE::Instance()
{
	static Poco::SingletonHolder<MyHGE> sh;
	return *sh.get();
}

HTEXTURE MyHGE::LoadTex(const char* fname)
{
	return hge->Texture_Load(fname);
}

void MyHGE::FreeTex(HTEXTURE t)
{
	hge->Texture_Free(t);
}

float MyHGE::GetDelta()
{
	return hge->Timer_GetDelta();
}

bool MyHGE::GetKeyState(int k)
{
	return hge->Input_GetKeyState(k);
}

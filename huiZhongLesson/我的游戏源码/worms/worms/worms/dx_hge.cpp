#pragma once
#include "dx_hge.h"

dx_hge::dx_hge()
{
	hge = hgeCreate(HGE_VERSION);// 使用hgeCreate函数创建HGE接口，参数必须传递正确的HGE_VERSION,它是在hge.h中定义的 
	hge->System_SetState(HGE_SCREENWIDTH, B_SCREEN_W);//设置屏幕宽度
	hge->System_SetState(HGE_SCREENHEIGHT, B_SCREEN_H);//设置屏幕高度
	hge->System_SetState(HGE_TITLE, "worms");//设置窗口标题
	hge->System_SetState(HGE_WINDOWED, true);//设置使用窗口模式 
	hge->System_SetState(HGE_USESOUND, false);//设置不使用声音（第一个程序我们先不讲解声音和图像的知识） 
	hge->System_SetState(HGE_SHOWSPLASH, false); // 解除掉程序开头HGE的LOGO
}

dx_hge::~dx_hge()
{
	hge->System_Shutdown();//程序停止 
	hge->Release();//释放HGE所占用的内存。 
}
/*
	函数名：Instance
	参数：无
*/
dx_hge& dx_hge::Instance()
{
	static Poco::SingletonHolder<dx_hge> thehge;
	return *thehge.get();
}
/*
	函数名：setProc
	参数：回调函数
*/
void dx_hge::setProc(hgeCallback ff, hgeCallback rf)
{
	hge->System_SetState(HGE_FRAMEFUNC, ff);//设置逻辑函数为FrameFunc函数 
	hge->System_SetState(HGE_RENDERFUNC, rf);//设置绘制函数为RenderFunc函数
	hge->System_Initiate();
}
/*
	函数名：BeginRender
	参数：颜色
*/
void dx_hge::BeginRender(DWORD col)
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(col);//以某颜色清屏，OxFF000000为透明度为0的黑色
}
/*
	函数名：EndRender
	参数：无
*/
void dx_hge::EndRender()
{
	hge->Gfx_EndScene();
}


/*
	函数名：Start
	参数：无
*/
void dx_hge::Start()
{
	hge->System_Start();//如果没有问题，则使用System_Start方法，开始程序。 

}
/*
	函数名：LoadTex
	参数：文件名
*/
HTEXTURE dx_hge::LoadTex(const char* fname)
{
	return hge->Texture_Load(fname);
}
/*
	函数名：LoadTex
	参数：纹理
*/
void dx_hge::FreeTex(HTEXTURE t)
{
	hge->Texture_Free(t);
}
/*
	函数名：getDelta
	参数：无
*/
float dx_hge::getDelta()
{
	return hge->Timer_GetDelta();
}
/*
	函数名：getKeyState
	参数：键盘值
*/
bool dx_hge::getKeyState(int k)
{
	return hge->Input_GetKeyState(k);
}

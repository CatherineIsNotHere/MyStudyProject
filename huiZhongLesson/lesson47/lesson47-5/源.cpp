#include "hge.h"
#include "hgesprite.h"
#include "Poco/Any.h"
using namespace Poco;

HGE *hge = 0;
HTARGET target;
HTEXTURE tex;
hgeSprite* spr;
hgeSprite* tar;
bool RenderFunc(){//绘制的回调，程序开始后会被不停的回调
	{ hge->Gfx_BeginScene(target);//开始绘图
	static float r = 0;
	r += 0.01f;
	if (r >= 6.28f){
		r = 0;
	}
	spr->SetHotSpot(210/2, 250/2);
	hge->Gfx_Clear(0xFFFFFFFF);
	spr->RenderEx(210/2, 250/2, r, .5f, .5f);
	hge->Gfx_EndScene();
	}
	{
		hge->Gfx_BeginScene();//开始绘图
		hge->Gfx_Clear(0xFFFF0000);
		tar->Render(0, 0);
		hge->Gfx_EndScene();
	}
	return false;//正常应返回false
}
bool FrameFunc(){//输入的回调，程序开始后会被不停的回调
	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{
		return true;
	}
	return false;//正常应返回false
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	
	hge = hgeCreate(HGE_VERSION);//创建
	hge->System_SetState(HGE_SCREENWIDTH, 520);
	hge->System_SetState(HGE_SCREENHEIGHT, 851);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_TITLE, "hello hge");
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	if (hge->System_Initiate()){//初始化
		tex = hge->Texture_Load("ppt图片1.png");
		spr = new hgeSprite(tex,0,0,210,250);
		target = hge->Target_Create(210, 250, false);
		tar = new hgeSprite(hge->Target_GetTexture(target), 210, 0, 210, 250);
		hge->System_Start();//开始运行	
	}
	delete tar;
	tar = nullptr;
	delete spr;
	spr = nullptr;
	hge->Texture_Free(tex);
	hge->Target_Free(target);
	hge->System_Shutdown();//结束程序
	hge->Release();//释放

	return 0;
}
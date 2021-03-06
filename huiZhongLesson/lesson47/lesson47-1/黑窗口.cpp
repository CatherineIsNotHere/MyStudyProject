#include "hge.h"

HGE *hge = 0;
bool RenderFunc(){//绘制的回调，程序开始后会被不停的回调
	
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
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_TITLE, "hello hge");
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	if (hge->System_Initiate()){//初始化
		hge->System_Start();//开始运行
	}
	hge->System_Shutdown();//结束程序
	hge->Release();//释放

	return 0;
}
#include"hgefont.h"
#include "hge.h"

HGE *hge = 0;
hgeFont* font;
float pi = 0.0f;
TCHAR msg[128] = TEXT("");
float x, y;
int wheel = 0;
bool isin;
bool RenderFunc(){//绘制的回调，程序开始后会被不停的回调
	hge->Gfx_BeginScene();//开始绘图
	hge->Gfx_Clear(0x00000000);
	font->SetColor(ARGB(255,0,0,255));
	font->SetScale(1.0f);
	//font->SetRotation(pi+=0.01f);//倾斜弧度
	font->printf(0, 100, HGETEXT_LEFT, "%S", TEXT("HELLO WORLD"));//xy对齐方式，“%d%c%s”
	font->printf(0, 200, HGETEXT_LEFT, "%f\n%d", hge->Timer_GetDelta(),hge->Timer_GetFPS());//xy对齐方式，时间戳，帧速率
	//font->printf(0, 300, HGETEXT_LEFT, "%S", msg);
	
	font->printf(0, 300, HGETEXT_LEFT, "x=%.0f,y=%.0f", x,y);
	hge->Gfx_EndScene();
	return false;//正常应返回false
}
bool FrameFunc(){//输入的回调，程序开始后会被不停的回调
	
	hge->Input_GetMousePos(&x,&y);
	wheel = hge->Input_GetMouseWheel();//是否滚轮-1向下1向上
	isin = hge->Input_IsMouseOver();//是否在客户区内
	hge->Input_KeyDown(HGEK_LBUTTON);//鼠标按下左键
	hge->Input_KeyUp(HGEK_RBUTTON);//鼠标抬起右键
	hge->Input_GetKeyState(HGEK_MBUTTON);//按住中键
	hge->Input_GetKey();//获取键盘按键
	
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
		font = new hgeFont("font1.fnt");
		hge->System_Start();//开始运行
	}
	delete font;
	hge->System_Shutdown();//结束程序
	hge->Release();//释放

	return 0;
}
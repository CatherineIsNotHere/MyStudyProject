#include"hgefont.h"
#include "hge.h"
#include<string>
using namespace std;

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
	int n1 = hge->Random_Int(0, 100);
	float f1 = hge->Random_Float(-1.0f, 1.0f);
	float time = hge->Timer_GetTime();//获取当前时间
	font->printf(100, 100, HGETEXT_LEFT, "%d\n%.3f\n%.1f", n1, f1,time);
	hge->Gfx_EndScene();
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
	hge->System_SetState(HGE_INIFILE,"c:\\123.ini");//设置用于读写的配置文件
	hge->System_SetState(HGE_LOGFILE, "c:\\123.log");
	if (hge->System_Initiate()){//初始化
		font = new hgeFont("font1.fnt");
		//hge->Ini_SetInt("AAA", "d1", 100);
		//hge->Ini_SetInt("BBB", "d1", 500);
		//hge->Ini_SetString("AAA", "d2", "攻击");
		//int d = hge->Ini_GetInt("AAA", "d1", -999);
		//char* s1 = hge->Ini_GetString("AAA","d2",nullptr);
		//string s2 = hge->Ini_GetString("AAA", "d2", nullptr);
		//hge->System_Log("%d,%c,%f,%s", 100, 'c', 123.123f, "汉字测试abc");//记录日志
		//hge->System_Launch("mspaint");//打开画图板
		//hge->System_Launch("devenv");//启动vs
		//hge->System_Launch("cmd"); 
		//hge->System_Launch("www.baidu.com");
		hge->Random_Seed();//设置随机种子
		hgeRect rc1;//矩形类
		hgeRect rc2;
		bool b1 = rc1.IsClean();//矩形是否有效
		rc1.Set(0, 0, 100, 200);//设置x1y1x2y2
		rc2.Set(50, 50, 150, 250);
		b1 = rc1.Intersect(&rc2);//相交检测
		b1 = rc1.TestPoint(10, 20);//判断点是否在矩形内
		rc2.SetRadius(200, 200, 100);//画一个以200200为圆心100为半径的正方形
		rc1.Clear();
		rc1.Encapsulate(-100, -100);//如果r1已经被清空，则rc1则会变为一个点，否则会将rc变大到包含那个点
		hge->System_Start();//开始运行
	}
	delete font;
	hge->System_Shutdown();//结束程序
	hge->Release();//释放

	return 0;
}
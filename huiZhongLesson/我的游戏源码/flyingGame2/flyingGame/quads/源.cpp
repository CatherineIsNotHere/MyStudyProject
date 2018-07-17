#include "hge.h" 
#include "hgeSprite.h"


//窗口宽高 
#define WINDOW_WIDTH    1024
#define WINDOW_HEIGHT    768

//图片宽高 
#define PIC_WIDTH    648
#define PIC_HEIGHT    720

//创建HGE指针 
HGE *hge = 0;

//创建精灵类指针 
hgeSprite *spr;

//定义纹理对象 
HTEXTURE tex;

//定义Quad对象 
hgeQuad quad;

float x = 324.0f;
float y = 360.0f;

bool RenderFunc()//绘制函数，程序开始后将不停调用它 
{
	//开始渲染 
	hge->Gfx_BeginScene();
	//以某颜色清屏 
	hge->Gfx_Clear(0);
	//设置精灵相对于窗口的显示位置，(0, 0)为左上角 
	spr->Render(WINDOW_WIDTH, WINDOW_HEIGHT);
	//渲染Quad 
	hge->Gfx_RenderQuad(&quad);
	//结束渲染 
	hge->Gfx_EndScene();

	return false;//总是返回false 
}

//逻辑函数 
//程序开始后将不停调用它 
//一些逻辑判断或处理写在这里 
bool FrameFunc()
{
	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{//按ESC退出 
		return true;//返回true将从System_Start往下执行 
	}

	//设置Quad的坐标位置 
	quad.v[0].x = x - 324; quad.v[0].y = y - 360;
	quad.v[1].x = x + 324; quad.v[1].y = y - 360;
	quad.v[2].x = x + 324; quad.v[2].y = y + 360;
	quad.v[3].x = x - 324; quad.v[3].y = y + 360;

	return false;//程序正常时总是返回false 
}
//WinMain函数，程序的入口 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd)
{
	//创建HGE接口 
	hge = hgeCreate(HGE_VERSION);

	//去掉HGE开场动画 
	hge->System_SetState(HGE_SHOWSPLASH, false);
	//设置逻辑函数为FrameFunc函数 
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	//设置绘制函数为RenderFunc函数 
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	//使用窗口模式 
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, WINDOW_WIDTH);
	hge->System_SetState(HGE_SCREENHEIGHT, WINDOW_HEIGHT);
	//不使用声音 
	hge->System_SetState(HGE_USESOUND, false);
	//设置标题 
	hge->System_SetState(HGE_TITLE, "显示图像2");
	//写入日志 
	hge->System_SetState(HGE_LOGFILE, "Image2.log");

	if (hge->System_Initiate())
	{
		//载入纹理文件 
		tex = hge->Texture_Load("Hellbenter.jpg");
		quad.tex = hge->Texture_Load("Soultaker.jpg");
		//初始化图像(精灵)对象 
		spr = new hgeSprite(tex, 0, 0, PIC_WIDTH, PIC_HEIGHT);
		spr->SetHotSpot(PIC_WIDTH, PIC_HEIGHT);//将热点设为右下角 

		//检测是否载入成功 
		if (!tex)
		{  //失败则弹出对话框并退出程序 
			MessageBox(NULL, TEXT("载入图片失败"), TEXT("错误"), MB_OK | MB_ICONERROR | MB_APPLMODAL);
			hge->System_Shutdown();
			hge->Release();
			return 0;
		}

		//设置混合模式 
		quad.blend = BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE;

		for (int i = 0; i < 4; i++)
		{
			//设置顶点的Z坐标 
			quad.v[i].z = 0.1f;
			//设置顶点的颜色 
			quad.v[i].col = ARGB(255, 255, 255, 255);
		}

		//截取图形 
		float tw = hge->Texture_GetWidth(quad.tex);
		float th = hge->Texture_GetHeight(quad.tex);
		quad.v[0].tx = 0 / tw;        quad.v[0].ty = 0 / th;
		quad.v[1].tx = 648.0 / tw;   quad.v[1].ty = 0 / th;
		quad.v[2].tx = 648.0 / tw;   quad.v[2].ty = 720.0 / th;
		quad.v[3].tx = 0 / tw;        quad.v[3].ty = 720.0 / th;

		//开始程序 
		hge->System_Start();
	}

	//释放资源 
	hge->Texture_Free(tex);
	hge->Texture_Free(quad.tex);
	delete spr;
	//停止程序 
	hge->System_Shutdown();
	//释放内存 
	hge->Release();

	return 0;
}

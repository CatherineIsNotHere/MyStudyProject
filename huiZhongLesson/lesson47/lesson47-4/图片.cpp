#include "hge.h"
#include "hgesprite.h"

HGE *hge = 0;
HTEXTURE tex;
hgeSprite * pspr;
hgeSprite * pspr2;
HTEXTURE tex2;
float w, h;
float x, y;
float x2, y2;
bool RenderFunc(){//绘制的回调，程序开始后会被不停的回调
	hge->Gfx_BeginScene();//开始绘图
	hge->Gfx_Clear(0x00000000);
	//pspr->RenderStretch(300, 200, 400, 500);//将图片绘制到指定的矩形中
	pspr->SetColor(0XFFFF00FF);
	pspr->SetTextureRect(0, 0, 100, 100);//仅适用纹理的指定部分
	pspr->Render(x, y );
	//if (y<h*(-1)){
	//	y = h;
	//}
	//if (y2 < h*(-1)){
	//	y2 = h;
	//}
	//pspr->SetHotSpot(w/2,h/2);//设置锚点
	//pspr2->SetHotSpot(w / 2, h / 2);//设置锚点
	/*pspr->Render(x, y-=0.5f);
	pspr2->Render(x2, y2 -= 0.5f);*/
	//pspr->SetFlip(true,false);//水平与垂直的翻转
	//static float r = 0;
	//r += 0.002f;
	//if (r>=2*3.14){
	//	r = 0;
	//}
	//pspr->RenderEx(x, y -= 0.5f, 0, 1.0f, 1.0f);//x,y,旋转角度，缩放
	//pspr2->RenderEx(x, y2 -= 0.5f, 0, 1.0f, 1.0f);//x,y,旋转角度，缩放
	//hgeRect* prc = new hgeRect();
	//pspr->GetBoundingBox(x, y, prc);//获取外包矩形，xy可以实现矩形的偏移
	//hge->Gfx_RenderLine(prc->x1, prc->y1, prc->x2, prc->y1);//绘制边框线
	hge->Gfx_EndScene();
	return false;//正常应返回false
}
bool FrameFunc(){//输入的回调，程序开始后会被不停的回调
	if (hge->Input_GetKeyState(HGEK_A)){
		hge->System_Snapshot("../a.jpg");
	}
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
		tex = hge->Texture_Load("bg1.bmp");
		tex2 = hge->Texture_Load("bg1.bmp");
		/*	tex = hge->Texture_Load("ppt图片1.png");
			tex2 = hge->Texture_Load("ppt图片1.png");*/
		w = hge->Texture_GetWidth(tex);
		h = hge->Texture_GetHeight(tex);
		pspr = new hgeSprite(tex,0,0,w,h);
		pspr2 = new hgeSprite(tex2, 0, 0, w, h);
		x = 0;
		y = 0;
		x2 = 0;
		y2 = h;
		hge->System_Start();//开始运行
	}
	delete pspr;
	pspr = nullptr;
	hge->Texture_Free(tex);
	hge->System_Shutdown();//结束程序
	hge->Release();//释放

	return 0;
}
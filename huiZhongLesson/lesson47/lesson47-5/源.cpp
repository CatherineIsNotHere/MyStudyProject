#include "hge.h"
#include "hgesprite.h"
#include "Poco/Any.h"
using namespace Poco;

HGE *hge = 0;
HTARGET target;
HTEXTURE tex;
hgeSprite* spr;
hgeSprite* tar;
bool RenderFunc(){//���ƵĻص�������ʼ��ᱻ��ͣ�Ļص�
	{ hge->Gfx_BeginScene(target);//��ʼ��ͼ
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
		hge->Gfx_BeginScene();//��ʼ��ͼ
		hge->Gfx_Clear(0xFFFF0000);
		tar->Render(0, 0);
		hge->Gfx_EndScene();
	}
	return false;//����Ӧ����false
}
bool FrameFunc(){//����Ļص�������ʼ��ᱻ��ͣ�Ļص�
	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{
		return true;
	}
	return false;//����Ӧ����false
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	
	hge = hgeCreate(HGE_VERSION);//����
	hge->System_SetState(HGE_SCREENWIDTH, 520);
	hge->System_SetState(HGE_SCREENHEIGHT, 851);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_TITLE, "hello hge");
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	if (hge->System_Initiate()){//��ʼ��
		tex = hge->Texture_Load("pptͼƬ1.png");
		spr = new hgeSprite(tex,0,0,210,250);
		target = hge->Target_Create(210, 250, false);
		tar = new hgeSprite(hge->Target_GetTexture(target), 210, 0, 210, 250);
		hge->System_Start();//��ʼ����	
	}
	delete tar;
	tar = nullptr;
	delete spr;
	spr = nullptr;
	hge->Texture_Free(tex);
	hge->Target_Free(target);
	hge->System_Shutdown();//��������
	hge->Release();//�ͷ�

	return 0;
}
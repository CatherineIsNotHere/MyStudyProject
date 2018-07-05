#include"hgefont.h"
#include "hge.h"
#include "hgeanim.h"
#include "hgeSprite.h" 
HGE *hge = 0;
hgeAnimation* g_animat;
HTEXTURE g_tex;
bool RenderFunc(){//���ƵĻص�������ʼ��ᱻ��ͣ�Ļص�
	hge->Gfx_BeginScene();//��ʼ��ͼ
	hge->Gfx_Clear(0x00000000);
	g_animat->Render(100, 200);
	hge->Gfx_EndScene();
	return false;//����Ӧ����false
}
bool FrameFunc(){//����Ļص�������ʼ��ᱻ��ͣ�Ļص�
	float dt = hge->Timer_GetDelta();
	g_animat->Update(dt); // ����
	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{
		return true;
	}
	return false;//����Ӧ����false
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	hge = hgeCreate(HGE_VERSION);//����
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_TITLE, "hello hge");
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	if (hge->System_Initiate()){//��ʼ��
		g_tex = hge->Texture_Load("�ɻ�1���ҷ�.png");
		g_animat = new hgeAnimation(g_tex, 20, 20, 0, 0, 100, 90);
		g_animat->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		g_animat->SetSpeed(10);// �ٶ�
		g_animat->Play();
		hge->System_Start();//��ʼ����
	}
	delete g_animat;
	hge->System_Shutdown();//��������
	hge->Release();//�ͷ�

	return 0;
}
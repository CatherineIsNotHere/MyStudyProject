#include"hgefont.h"
#include "hge.h"
#include "hgeanim.h"
#include "hgeSprite.h" 
#include "G_Player.cpp"

HGE *hge = 0;
hgeAnimation* g_animat;
HTEXTURE g_tex;
G_Player* player1;
bool RenderFunc(){//���ƵĻص�������ʼ��ᱻ��ͣ�Ļص�
	hge->Gfx_BeginScene();//��ʼ��ͼ
	hge->Gfx_Clear(0x00000000);
	player1->p_animat[P_COMMON]->Render(100, 200);
	hge->Gfx_EndScene();
	return false;//����Ӧ����false
}
bool FrameFunc(){//����Ļص�������ʼ��ᱻ��ͣ�Ļص�
	float dt = hge->Timer_GetDelta();
	player1->p_animat[0]->Update(dt); // ����
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
		player1 = new G_Player(hge);

		hge->System_Start();//��ʼ����
	}
	delete player1;
	hge->System_Shutdown();//��������
	hge->Release();//�ͷ�

	return 0;
}
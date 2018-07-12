#include"hgefont.h"
#include "hge.h"
#include "hgeanim.h"
#include "hgeSprite.h" 
#include "G_Player.cpp"
#include "G_Map.cpp"

HGE *hge = 0;
G_Player* player1;
G_Map* map1;
bool RenderFunc(){//���ƵĻص�������ʼ��ᱻ��ͣ�Ļص�
	hge->Gfx_BeginScene();//��ʼ��ͼ
	hge->Gfx_Clear(0x00000000);
	static float y = 0;
	//player1->p_animat[player1->p_state]
	map1->m_spr->SetHotSpot(0,4096-960);
	map1->m_spr->Render(0,y+=.1f);
	player1->p_animat[player1->p_state]->RenderEx(player1->p_x, player1->p_y,0,1.f,1.f);
	hge->Gfx_EndScene();
	return false;//����Ӧ����false
}
bool FrameFunc(){//����Ļص�������ʼ��ᱻ��ͣ�Ļص�
	player1->PlayerFrame();
	
	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{
		return true;
	}
	return false;//����Ӧ����false
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	hge = hgeCreate(HGE_VERSION);//����
	hge->System_SetState(HGE_SCREENWIDTH, 640);
	hge->System_SetState(HGE_SCREENHEIGHT, 960);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_TITLE, "flyingGame");
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	if (hge->System_Initiate()){//��ʼ��
		player1 = new G_Player(hge);
		map1 = new G_Map(hge);
		hge->System_Start();//��ʼ����
	}
	delete player1;
	hge->System_Shutdown();//��������
	hge->Release();//�ͷ�

	return 0;
}
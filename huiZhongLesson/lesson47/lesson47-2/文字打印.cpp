#include"hgefont.h"
#include "hge.h"

HGE *hge = 0;
hgeFont* font;
float pi = 0.0f;
TCHAR msg[128] = TEXT("");
float x, y;
int wheel = 0;
bool isin;
bool RenderFunc(){//���ƵĻص�������ʼ��ᱻ��ͣ�Ļص�
	hge->Gfx_BeginScene();//��ʼ��ͼ
	hge->Gfx_Clear(0x00000000);
	font->SetColor(ARGB(255,0,0,255));
	font->SetScale(1.0f);
	//font->SetRotation(pi+=0.01f);//��б����
	font->printf(0, 100, HGETEXT_LEFT, "%S", TEXT("HELLO WORLD"));//xy���뷽ʽ����%d%c%s��
	font->printf(0, 200, HGETEXT_LEFT, "%f\n%d", hge->Timer_GetDelta(),hge->Timer_GetFPS());//xy���뷽ʽ��ʱ�����֡����
	//font->printf(0, 300, HGETEXT_LEFT, "%S", msg);
	
	font->printf(0, 300, HGETEXT_LEFT, "x=%.0f,y=%.0f", x,y);
	hge->Gfx_EndScene();
	return false;//����Ӧ����false
}
bool FrameFunc(){//����Ļص�������ʼ��ᱻ��ͣ�Ļص�
	
	hge->Input_GetMousePos(&x,&y);
	wheel = hge->Input_GetMouseWheel();//�Ƿ����-1����1����
	isin = hge->Input_IsMouseOver();//�Ƿ��ڿͻ�����
	hge->Input_KeyDown(HGEK_LBUTTON);//��갴�����
	hge->Input_KeyUp(HGEK_RBUTTON);//���̧���Ҽ�
	hge->Input_GetKeyState(HGEK_MBUTTON);//��ס�м�
	hge->Input_GetKey();//��ȡ���̰���
	
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
		font = new hgeFont("font1.fnt");
		hge->System_Start();//��ʼ����
	}
	delete font;
	hge->System_Shutdown();//��������
	hge->Release();//�ͷ�

	return 0;
}
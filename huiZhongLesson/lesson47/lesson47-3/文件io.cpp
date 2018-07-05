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
bool RenderFunc(){//���ƵĻص�������ʼ��ᱻ��ͣ�Ļص�
	hge->Gfx_BeginScene();//��ʼ��ͼ
	hge->Gfx_Clear(0x00000000);
	int n1 = hge->Random_Int(0, 100);
	float f1 = hge->Random_Float(-1.0f, 1.0f);
	float time = hge->Timer_GetTime();//��ȡ��ǰʱ��
	font->printf(100, 100, HGETEXT_LEFT, "%d\n%.3f\n%.1f", n1, f1,time);
	hge->Gfx_EndScene();
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
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_TITLE, "hello hge");
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	hge->System_SetState(HGE_INIFILE,"c:\\123.ini");//�������ڶ�д�������ļ�
	hge->System_SetState(HGE_LOGFILE, "c:\\123.log");
	if (hge->System_Initiate()){//��ʼ��
		font = new hgeFont("font1.fnt");
		//hge->Ini_SetInt("AAA", "d1", 100);
		//hge->Ini_SetInt("BBB", "d1", 500);
		//hge->Ini_SetString("AAA", "d2", "����");
		//int d = hge->Ini_GetInt("AAA", "d1", -999);
		//char* s1 = hge->Ini_GetString("AAA","d2",nullptr);
		//string s2 = hge->Ini_GetString("AAA", "d2", nullptr);
		//hge->System_Log("%d,%c,%f,%s", 100, 'c', 123.123f, "���ֲ���abc");//��¼��־
		//hge->System_Launch("mspaint");//�򿪻�ͼ��
		//hge->System_Launch("devenv");//����vs
		//hge->System_Launch("cmd"); 
		//hge->System_Launch("www.baidu.com");
		hge->Random_Seed();//�����������
		hgeRect rc1;//������
		hgeRect rc2;
		bool b1 = rc1.IsClean();//�����Ƿ���Ч
		rc1.Set(0, 0, 100, 200);//����x1y1x2y2
		rc2.Set(50, 50, 150, 250);
		b1 = rc1.Intersect(&rc2);//�ཻ���
		b1 = rc1.TestPoint(10, 20);//�жϵ��Ƿ��ھ�����
		rc2.SetRadius(200, 200, 100);//��һ����200200ΪԲ��100Ϊ�뾶��������
		rc1.Clear();
		rc1.Encapsulate(-100, -100);//���r1�Ѿ�����գ���rc1����Ϊһ���㣬����Ὣrc��󵽰����Ǹ���
		hge->System_Start();//��ʼ����
	}
	delete font;
	hge->System_Shutdown();//��������
	hge->Release();//�ͷ�

	return 0;
}
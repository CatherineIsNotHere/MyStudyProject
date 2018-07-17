#include "hge.h" 
#include "hgeSprite.h"


//���ڿ�� 
#define WINDOW_WIDTH    1024
#define WINDOW_HEIGHT    768

//ͼƬ��� 
#define PIC_WIDTH    648
#define PIC_HEIGHT    720

//����HGEָ�� 
HGE *hge = 0;

//����������ָ�� 
hgeSprite *spr;

//����������� 
HTEXTURE tex;

//����Quad���� 
hgeQuad quad;

float x = 324.0f;
float y = 360.0f;

bool RenderFunc()//���ƺ���������ʼ�󽫲�ͣ������ 
{
	//��ʼ��Ⱦ 
	hge->Gfx_BeginScene();
	//��ĳ��ɫ���� 
	hge->Gfx_Clear(0);
	//���þ�������ڴ��ڵ���ʾλ�ã�(0, 0)Ϊ���Ͻ� 
	spr->Render(WINDOW_WIDTH, WINDOW_HEIGHT);
	//��ȾQuad 
	hge->Gfx_RenderQuad(&quad);
	//������Ⱦ 
	hge->Gfx_EndScene();

	return false;//���Ƿ���false 
}

//�߼����� 
//����ʼ�󽫲�ͣ������ 
//һЩ�߼��жϻ���д������ 
bool FrameFunc()
{
	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{//��ESC�˳� 
		return true;//����true����System_Start����ִ�� 
	}

	//����Quad������λ�� 
	quad.v[0].x = x - 324; quad.v[0].y = y - 360;
	quad.v[1].x = x + 324; quad.v[1].y = y - 360;
	quad.v[2].x = x + 324; quad.v[2].y = y + 360;
	quad.v[3].x = x - 324; quad.v[3].y = y + 360;

	return false;//��������ʱ���Ƿ���false 
}
//WinMain�������������� 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd)
{
	//����HGE�ӿ� 
	hge = hgeCreate(HGE_VERSION);

	//ȥ��HGE�������� 
	hge->System_SetState(HGE_SHOWSPLASH, false);
	//�����߼�����ΪFrameFunc���� 
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	//���û��ƺ���ΪRenderFunc���� 
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	//ʹ�ô���ģʽ 
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, WINDOW_WIDTH);
	hge->System_SetState(HGE_SCREENHEIGHT, WINDOW_HEIGHT);
	//��ʹ������ 
	hge->System_SetState(HGE_USESOUND, false);
	//���ñ��� 
	hge->System_SetState(HGE_TITLE, "��ʾͼ��2");
	//д����־ 
	hge->System_SetState(HGE_LOGFILE, "Image2.log");

	if (hge->System_Initiate())
	{
		//���������ļ� 
		tex = hge->Texture_Load("Hellbenter.jpg");
		quad.tex = hge->Texture_Load("Soultaker.jpg");
		//��ʼ��ͼ��(����)���� 
		spr = new hgeSprite(tex, 0, 0, PIC_WIDTH, PIC_HEIGHT);
		spr->SetHotSpot(PIC_WIDTH, PIC_HEIGHT);//���ȵ���Ϊ���½� 

		//����Ƿ�����ɹ� 
		if (!tex)
		{  //ʧ���򵯳��Ի����˳����� 
			MessageBox(NULL, TEXT("����ͼƬʧ��"), TEXT("����"), MB_OK | MB_ICONERROR | MB_APPLMODAL);
			hge->System_Shutdown();
			hge->Release();
			return 0;
		}

		//���û��ģʽ 
		quad.blend = BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE;

		for (int i = 0; i < 4; i++)
		{
			//���ö����Z���� 
			quad.v[i].z = 0.1f;
			//���ö������ɫ 
			quad.v[i].col = ARGB(255, 255, 255, 255);
		}

		//��ȡͼ�� 
		float tw = hge->Texture_GetWidth(quad.tex);
		float th = hge->Texture_GetHeight(quad.tex);
		quad.v[0].tx = 0 / tw;        quad.v[0].ty = 0 / th;
		quad.v[1].tx = 648.0 / tw;   quad.v[1].ty = 0 / th;
		quad.v[2].tx = 648.0 / tw;   quad.v[2].ty = 720.0 / th;
		quad.v[3].tx = 0 / tw;        quad.v[3].ty = 720.0 / th;

		//��ʼ���� 
		hge->System_Start();
	}

	//�ͷ���Դ 
	hge->Texture_Free(tex);
	hge->Texture_Free(quad.tex);
	delete spr;
	//ֹͣ���� 
	hge->System_Shutdown();
	//�ͷ��ڴ� 
	hge->Release();

	return 0;
}

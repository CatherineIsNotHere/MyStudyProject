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
bool RenderFunc(){//���ƵĻص�������ʼ��ᱻ��ͣ�Ļص�
	hge->Gfx_BeginScene();//��ʼ��ͼ
	hge->Gfx_Clear(0x00000000);
	//pspr->RenderStretch(300, 200, 400, 500);//��ͼƬ���Ƶ�ָ���ľ�����
	pspr->SetColor(0XFFFF00FF);
	pspr->SetTextureRect(0, 0, 100, 100);//�����������ָ������
	pspr->Render(x, y );
	//if (y<h*(-1)){
	//	y = h;
	//}
	//if (y2 < h*(-1)){
	//	y2 = h;
	//}
	//pspr->SetHotSpot(w/2,h/2);//����ê��
	//pspr2->SetHotSpot(w / 2, h / 2);//����ê��
	/*pspr->Render(x, y-=0.5f);
	pspr2->Render(x2, y2 -= 0.5f);*/
	//pspr->SetFlip(true,false);//ˮƽ�봹ֱ�ķ�ת
	//static float r = 0;
	//r += 0.002f;
	//if (r>=2*3.14){
	//	r = 0;
	//}
	//pspr->RenderEx(x, y -= 0.5f, 0, 1.0f, 1.0f);//x,y,��ת�Ƕȣ�����
	//pspr2->RenderEx(x, y2 -= 0.5f, 0, 1.0f, 1.0f);//x,y,��ת�Ƕȣ�����
	//hgeRect* prc = new hgeRect();
	//pspr->GetBoundingBox(x, y, prc);//��ȡ������Σ�xy����ʵ�־��ε�ƫ��
	//hge->Gfx_RenderLine(prc->x1, prc->y1, prc->x2, prc->y1);//���Ʊ߿���
	hge->Gfx_EndScene();
	return false;//����Ӧ����false
}
bool FrameFunc(){//����Ļص�������ʼ��ᱻ��ͣ�Ļص�
	if (hge->Input_GetKeyState(HGEK_A)){
		hge->System_Snapshot("../a.jpg");
	}
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
		tex = hge->Texture_Load("bg1.bmp");
		tex2 = hge->Texture_Load("bg1.bmp");
		/*	tex = hge->Texture_Load("pptͼƬ1.png");
			tex2 = hge->Texture_Load("pptͼƬ1.png");*/
		w = hge->Texture_GetWidth(tex);
		h = hge->Texture_GetHeight(tex);
		pspr = new hgeSprite(tex,0,0,w,h);
		pspr2 = new hgeSprite(tex2, 0, 0, w, h);
		x = 0;
		y = 0;
		x2 = 0;
		y2 = h;
		hge->System_Start();//��ʼ����
	}
	delete pspr;
	pspr = nullptr;
	hge->Texture_Free(tex);
	hge->System_Shutdown();//��������
	hge->Release();//�ͷ�

	return 0;
}
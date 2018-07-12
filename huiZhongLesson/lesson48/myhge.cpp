#pragma once
#include "myhge.h"
#include <Poco/SingletonHolder.h>

MyHGE::MyHGE()
{
	hge = hgeCreate(HGE_VERSION);// ʹ��hgeCreate��������HGE�ӿڣ��������봫����ȷ��HGE_VERSION,������hge.h�ж���� 
	hge->System_SetState(HGE_SCREENWIDTH, BASESCREENW);//����Ļ�������Ϊ800 
	hge->System_SetState(HGE_SCREENHEIGHT, BASESCREENH);//����Ļ�߶�����Ϊ600 
	hge->System_SetState(HGE_TITLE, "�ҵĵ�һ��HGE����");//���ô��ڱ���Ϊ���ҵĵ�һ��HGE���� 
	hge->System_SetState(HGE_WINDOWED, true);//����ʹ�ô���ģʽ 
	hge->System_SetState(HGE_USESOUND, false);//���ò�ʹ����������һ�����������Ȳ�����������ͼ���֪ʶ�� 
	hge->System_SetState(HGE_SHOWSPLASH, false); // ���������ͷHGE��LOGO
}

MyHGE::~MyHGE()
{
	hge->System_Shutdown();//����ֹͣ 
	hge->Release();//�ͷ�HGE��ռ�õ��ڴ档 
}

void MyHGE::SetProc(hgeCallback ff, hgeCallback rf)
{
	hge->System_SetState(HGE_FRAMEFUNC, ff);//�����߼�����ΪFrameFunc���� 
	hge->System_SetState(HGE_RENDERFUNC, rf);//���û��ƺ���ΪRenderFunc����
	hge->System_Initiate();
}

void MyHGE::BeginRender(DWORD col)
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(col);//��ĳ��ɫ������OxFF000000Ϊ͸����Ϊ0�ĺ�ɫ
}

void MyHGE::EndRender()
{
	hge->Gfx_EndScene();
}

void MyHGE::Start()
{
	hge->System_Start();//���û�����⣬��ʹ��System_Start��������ʼ���� 
}

MyHGE& MyHGE::Instance()
{
	static Poco::SingletonHolder<MyHGE> sh;
	return *sh.get();
}

HTEXTURE MyHGE::LoadTex(const char* fname)
{
	return hge->Texture_Load(fname);
}

void MyHGE::FreeTex(HTEXTURE t)
{
	hge->Texture_Free(t);
}

float MyHGE::GetDelta()
{
	return hge->Timer_GetDelta();
}

bool MyHGE::GetKeyState(int k)
{
	return hge->Input_GetKeyState(k);
}

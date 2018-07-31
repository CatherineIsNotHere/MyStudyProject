#pragma once
#include "dx_hge.h"

dx_hge::dx_hge()
{
	hge = hgeCreate(HGE_VERSION);// ʹ��hgeCreate��������HGE�ӿڣ��������봫����ȷ��HGE_VERSION,������hge.h�ж���� 
	hge->System_SetState(HGE_SCREENWIDTH, B_SCREEN_W);//������Ļ���
	hge->System_SetState(HGE_SCREENHEIGHT, B_SCREEN_H);//������Ļ�߶�
	hge->System_SetState(HGE_TITLE, "worms");//���ô��ڱ���
	hge->System_SetState(HGE_WINDOWED, true);//����ʹ�ô���ģʽ 
	hge->System_SetState(HGE_USESOUND, false);//���ò�ʹ����������һ�����������Ȳ�����������ͼ���֪ʶ�� 
	hge->System_SetState(HGE_SHOWSPLASH, false); // ���������ͷHGE��LOGO
}

dx_hge::~dx_hge()
{
	hge->System_Shutdown();//����ֹͣ 
	hge->Release();//�ͷ�HGE��ռ�õ��ڴ档 
}
/*
	��������Instance
	��������
*/
dx_hge& dx_hge::Instance()
{
	static Poco::SingletonHolder<dx_hge> thehge;
	return *thehge.get();
}
/*
	��������setProc
	�������ص�����
*/
void dx_hge::setProc(hgeCallback ff, hgeCallback rf)
{
	hge->System_SetState(HGE_FRAMEFUNC, ff);//�����߼�����ΪFrameFunc���� 
	hge->System_SetState(HGE_RENDERFUNC, rf);//���û��ƺ���ΪRenderFunc����
	hge->System_Initiate();
}
/*
	��������BeginRender
	��������ɫ
*/
void dx_hge::BeginRender(DWORD col)
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(col);//��ĳ��ɫ������OxFF000000Ϊ͸����Ϊ0�ĺ�ɫ
}
/*
	��������EndRender
	��������
*/
void dx_hge::EndRender()
{
	hge->Gfx_EndScene();
}


/*
	��������Start
	��������
*/
void dx_hge::Start()
{
	hge->System_Start();//���û�����⣬��ʹ��System_Start��������ʼ���� 

}
/*
	��������LoadTex
	�������ļ���
*/
HTEXTURE dx_hge::LoadTex(const char* fname)
{
	return hge->Texture_Load(fname);
}
/*
	��������LoadTex
	����������
*/
void dx_hge::FreeTex(HTEXTURE t)
{
	hge->Texture_Free(t);
}
/*
	��������getDelta
	��������
*/
float dx_hge::getDelta()
{
	return hge->Timer_GetDelta();
}
/*
	��������getKeyState
	����������ֵ
*/
bool dx_hge::getKeyState(int k)
{
	return hge->Input_GetKeyState(k);
}

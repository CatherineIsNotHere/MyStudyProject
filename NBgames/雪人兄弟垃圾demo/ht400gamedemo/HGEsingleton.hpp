#pragma once

#include <Poco/SingletonHolder.h>
#include "Poco/Bugcheck.h" 
#include "hge.h"//����hgeͷ�ļ�

#define BIT 4
#define BASESCREENW 256 * BIT
#define BASESCREENH 224 * BIT

class HGEsgt
{
public:
	HGE* GetHGE()
	{
		return hge;
	}

	void SetProc(hgeCallback rp, hgeCallback fp)
	{
		hge->System_SetState(HGE_FRAMEFUNC, fp);//�����߼�����ΪFrameFunc���� 
		hge->System_SetState(HGE_RENDERFUNC, rp);//���û��ƺ���ΪRenderFunc����
		poco_assert(hge->System_Initiate());
	}

	void BeginRender(DWORD col)
	{
		hge->Gfx_BeginScene();
		hge->Gfx_Clear(col);//��ĳ��ɫ������OxFF000000Ϊ͸����Ϊ0�ĺ�ɫ
	}

	void EndRender()
	{
		hge->Gfx_EndScene();
	}
	void Start()
	{
		hge->System_Start();//���û�����⣬��ʹ��System_Start��������ʼ���� 
	}

	static HGEsgt& Instance()
	{
		static Poco::SingletonHolder<HGEsgt> sh;
		return *sh.get();
	}

public:
	HGEsgt()
	{
		hge = hgeCreate(HGE_VERSION);// ʹ��hgeCreate��������HGE�ӿڣ��������봫����ȷ��HGE_VERSION,������hge.h�ж���� 
		poco_assert(hge);
		hge->System_SetState(HGE_SCREENWIDTH, BASESCREENW);//����Ļ�������Ϊ800 
		hge->System_SetState(HGE_SCREENHEIGHT, BASESCREENH);//����Ļ�߶�����Ϊ600 
		hge->System_SetState(HGE_TITLE, "�ҵĵ�һ��HGE����");//���ô��ڱ���Ϊ���ҵĵ�һ��HGE���� 
		hge->System_SetState(HGE_WINDOWED, true);//����ʹ�ô���ģʽ 
		hge->System_SetState(HGE_USESOUND, false);//���ò�ʹ����������һ�����������Ȳ�����������ͼ���֪ʶ�� 
		hge->System_SetState(HGE_SHOWSPLASH, false); // ���������ͷHGE��LOGO
	}

	~HGEsgt()
	{
		hge->System_Shutdown();//����ֹͣ 
		hge->Release();//�ͷ�HGE��ռ�õ��ڴ档 
	}
private: // ����������ÿ��������븳ֵ������
	HGEsgt(const HGEsgt&);
	HGEsgt& operator = (const HGEsgt&);
	HGE* hge;
};

 
#pragma once
#include <windows.h>
#include "configuration.hpp"
#include "g_cSprite.hpp"

class cObject{
private:
	CSprite o_spr;
	//CMyRect m_rc;
	int o_nX;//����x����
	int o_nY;//����y����
	OBJSTATE o_state;//״̬
public:
	cObject();
	~cObject();
	int getNX();
	int getNY();
	OBJSTATE getOState();
	CSprite getSpr();
	void setNX(int x);
	void setNY(int y);
	void setOState(OBJSTATE os);
	void setSpr(CSprite spr);
	/*
	���ƣ�Init
	���ܣ���ʼ������
	������fname:ͼƬ·��.
		framew:ͼƬÿ֡��ȣ������֡����ΪͼƬ��ȣ�.
		frameh:ͼƬ�߶�.
		frames:ͼƬ��֡��.
		x:ͼƬ����x����.
		y��ͼƬ����y����.
		ssc��ͼƬ���Ŵ�С
	*/
	virtual BOOL Init(LPTSTR fname, int framew, int frameh, int frames, int x, int y, float sscw, float ssch);
	/*
		����:Update
		���ܣ�����ͼƬ״̬λ�ô�С��
		��������
	*/
	virtual BOOL Update();
	/*
	����:Draw
	���ܣ���ͼ
	������HDC�豸��� COL��ɫ
	*/
	virtual BOOL Draw(HDC hdc);
	virtual BOOL Draw(HDC hdc,COLORREF col);
};

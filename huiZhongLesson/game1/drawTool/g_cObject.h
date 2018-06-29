#pragma once
#include <windows.h>
#include "configuration.hpp"
#include "g_cSprite.hpp"

class cObject{
private:
	CSprite o_spr;
	//CMyRect m_rc;
	int o_nX;//所在x坐标
	int o_nY;//所在y坐标
	OBJSTATE o_state;//状态
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
	名称：Init
	功能：初始化精灵
	参数：fname:图片路径.
		framew:图片每帧宽度（如果无帧数则为图片宽度）.
		frameh:图片高度.
		frames:图片总帧数.
		x:图片所在x坐标.
		y：图片所在y坐标.
		ssc：图片缩放大小
	*/
	virtual BOOL Init(LPTSTR fname, int framew, int frameh, int frames, int x, int y, float sscw, float ssch);
	/*
		名称:Update
		功能：更新图片状态位置大小等
		参数：无
	*/
	virtual BOOL Update();
	/*
	名称:Draw
	功能：画图
	参数：HDC设备句柄 COL颜色
	*/
	virtual BOOL Draw(HDC hdc);
	virtual BOOL Draw(HDC hdc,COLORREF col);
};

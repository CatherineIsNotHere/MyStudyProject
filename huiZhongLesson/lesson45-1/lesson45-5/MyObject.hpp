#pragma once;
#include <windows.h>
#include "myrect.hpp"
#include "mysprite.hpp"


enum OBJSTATE // ½ÇÉ«×´Ì¬Ã¶¾Ù
{
	OS_IDLE = 0,
	OS_RUN,
	OS_JUMP,
	OS_DEAD,
};

class CMyObject{
private:
	CMySprite m_spr;
	CMyRect m_rc;
	int m_nX;
	int m_nY;
	OBJSTATE m_state;
public:
	CMyObject(){
	
	}
	~CMyObject(){
	
	}
	virtual void Init(LPTSTR fname,int framew,int frameh,int frames,int x,int y,float scalex=1.0f,float scaley=1.0f){
		m_spr.Load(fname);
		m_spr.setSprite(framew, frameh, frames);
		m_spr.setScale(scalex,scaley);
		m_rc.SetRect(x, y, 2*framew, frameh);
		m_nX = x;
		m_nY = y;
	}
	virtual void Draw(HDC dc){
		m_spr.Draw(dc, m_nX, m_nY, RGB(255,255,255));
		m_rc.Draw(dc);
	}
	virtual void Update(){
		int x = m_nX;
		int y = m_nY;
		if (GetKeyState(VK_LEFT) & 0X80){
			x-=10;
		}
		else if (GetKeyState(VK_RIGHT) & 0x80){
			x+=10;
		}
		else if (GetKeyState(VK_UP) & 0x80){
			y-=10;
		}
		else if (GetKeyState(VK_DOWN) & 0x80){
			y+=10;
		}
		m_rc.Offset(x-m_nX,y-m_nY);
		m_nX = x;
		m_nY = y;
	}
};
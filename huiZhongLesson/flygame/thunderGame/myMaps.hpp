#pragma once;
#include <windows.h>
#include "myObject.hpp"
class CMymaps:public CMyObject{
public:
	CMymaps(){

	}
	~CMymaps(){

	}
	void Init(LPTSTR fname, int framew, int frameh, int frames, int x, int y, float scalex = 1.0f, float scaley = 1.0f){
		m_spr.Load(fname);
		m_spr.setSprite(framew, frameh, frames);
		m_spr.setScale(scalex, scaley);
		//m_rc.SetRect(x, y, 2 * framew, frameh);
		m_nX = x;
		m_nY = y;
	}
	void Draw(HDC dc){
		m_spr.Draw(dc, m_nX, m_nY, RGB(255, 255, 255));
		//m_rc.Draw(dc);
		m_spr.Draw(dc, m_nX, m_nY + m_spr.getHeight(), RGB(255, 255, 255));
	}
	void Update(){
		m_nY -= 1;
		int height = m_spr.getHeight();
		if (m_nY*(-1) >= height){
			m_nY = 0;
		}
	}
};
#pragma once
#include <windows.h>

#pragma once;
#include "g_cBitmap.hpp"

class CSprite :public CBitmap{
public:
	CSprite()
	{

	}

	~CSprite(){

	}

	void setSprite(int w, int h, int c){
		m_nFrameWidth = w;
		m_nFrameHeight = h;
		m_nFrames = c;
		m_nCurrent = 0;
	}
	void setCurrentFrame(int m){
		if (m < 0){
			m = 0;
		}
		if (m >= m_nFrames){
			m = m_nFrames - 1;
		}
		m_nCurrent = m;
	}

	void NextFrame(){
		if (++m_nCurrent >= m_nFrames){
			setCurrentFrame(0);
		}
	}

	BOOL Draw(HDC hdc, int x, int y, COLORREF keycol){
		HDC memdc = CreateCompatibleDC(hdc);
		HBITMAP oldbm = (HBITMAP)SelectObject(memdc, m_hBitmap);
		TransparentBlt(hdc, x, y, m_nWidth*m_ssc.w, m_nHeight*m_ssc.h, memdc, m_nFrameWidth*m_nCurrent, 0, m_nFrameWidth, m_nFrameHeight, keycol);
		SelectObject(memdc, oldbm);
		DeleteDC(memdc);
		this->NextFrame();
		return true;
	}

	DWORD getHeight(){
		return m_nFrameHeight;
	}
	DWORD getWidth(){
		return m_nFrameWidth;
	}
protected:
	DWORD m_nFrameWidth;//每帧宽
	DWORD m_nFrameHeight;//每帧高
	DWORD m_nFrames;//多少帧
	DWORD m_nCurrent;//当前第几帧

};
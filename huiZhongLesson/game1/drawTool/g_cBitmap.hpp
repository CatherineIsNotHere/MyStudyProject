#pragma once;
#include <windows.h>
#include "configuration.hpp"
#pragma comment(lib,"msimg32.lib")
class CBitmap{
protected:
	HBITMAP m_hBitmap;
	DWORD m_nWidth;
	DWORD m_nHeight;
	SCALE m_ssc;
public:
	CBitmap()
		:m_hBitmap(NULL)
		, m_nHeight(0)
		, m_nWidth(0)
	{
		m_ssc.h = 1.f;
		m_ssc.w = 1.f;
	}
	CBitmap(LPTSTR fname)
		:m_hBitmap(NULL)
		, m_nHeight(0)
		, m_nWidth(0)
	{
		m_ssc.h = 1.f;
		m_ssc.w = 1.f;
		Load(fname);
	}
	~CBitmap(){
		DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}
	void setScale(FLOAT w, FLOAT h){
		m_ssc.w = w;
		m_ssc.h = h;
	}
	//void create(HDC hdc, DWORD w, DWORD h, COLORREF col){
	//	m_hBitmap = CreateCompatibleBitmap(hdc, w, h);
	//	HDC memdc = CreateCompatibleDC(hdc);
	//	HBRUSH brush = CreateSolidBrush(col);
	//	HBITMAP old = (HBITMAP)SelectObject(memdc, m_hBitmap);
	//	RECT rc = { 0, 0, w, h };

	//	FillRect(memdc, &rc, brush);

	//	SelectObject(memdc, old);
	//	DeleteDC(memdc);
	//	DeleteObject(brush);
	//	m_nWidth = w;
	//	m_nHeight = h;

	//}
	virtual BOOL Draw(HDC hdc, int x, int y, COLORREF keycol){
		HDC memdc = CreateCompatibleDC(hdc);
		HBITMAP oldbm = (HBITMAP)SelectObject(memdc, m_hBitmap);
		TransparentBlt(hdc, x, y, m_nWidth*m_ssc.w, m_nHeight*m_ssc.h, memdc, 0, 0, m_nWidth, m_nHeight, keycol);
		SelectObject(memdc, oldbm);
		DeleteDC(memdc);
		return true;
	}

	BOOL Load(LPTSTR fname){
		m_hBitmap = (HBITMAP)LoadImage(NULL, fname, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		BITMAP bitmapinfo;
		GetObject(m_hBitmap, sizeof(BITMAP), &bitmapinfo);
		m_nWidth = bitmapinfo.bmWidth;
		m_nHeight = bitmapinfo.bmHeight;
		return true;
	}
	/*
	get and set
	*/

	HBITMAP getHBitmap(){
		return m_hBitmap;
	}
	DWORD getNWidth(){
		return m_nWidth;
	}
	DWORD getNHeight(){
		return m_nHeight;
	}
	SCALE getSSC(){
		return m_ssc;
	}

	void setHBithmap(HBITMAP hbitmap){
		this->m_hBitmap = hbitmap;
	}

	void setNWidth(DWORD width){
		this->m_nWidth = width;
	}

	void setNHeight(DWORD height){
		this->m_nHeight = height;
	}
	void setSSC(SCALE ssc){
		this->m_ssc = ssc;
	}


};

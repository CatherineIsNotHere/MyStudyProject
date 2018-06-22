#pragma once;
#include <windows.h>
#pragma comment(lib,"msimg32.lib")
class CMyBitmap{
protected:
	HBITMAP m_hBitmap;
	DWORD m_nWidth;
	DWORD m_nHeight;
	FLOAT m_nHScale;
	FLOAT m_nWScale;
public:
	CMyBitmap()
		:m_hBitmap(NULL)
		, m_nHeight(0)
		, m_nWidth(0)
		, m_nWScale(1.f)
		, m_nHScale(1.f)
	{

	}
	CMyBitmap(LPTSTR fname)
		:m_hBitmap(NULL)
		, m_nHeight(0)
		, m_nWidth(0)
		, m_nWScale(1.f)
		, m_nHScale(1.f)
	{
		Load(fname);
	}
	CMyBitmap(DWORD w, DWORD h, COLORREF col)
		:m_hBitmap(NULL)
		, m_nHeight(0)
		, m_nWidth(0)
		, m_nWScale(1.f)
		, m_nHScale(1.f)
	{
	}
	~CMyBitmap(){
		DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}
	void setScale(FLOAT w, FLOAT h){
		m_nWScale = w;
		m_nHScale = h;
	}
	void create(HDC hdc, DWORD w, DWORD h, COLORREF col){
		m_hBitmap = CreateCompatibleBitmap(hdc, w, h);
		HDC memdc = CreateCompatibleDC(hdc);
		HBRUSH brush = CreateSolidBrush(col);
		HBITMAP old = (HBITMAP)SelectObject(memdc, m_hBitmap);
		RECT rc = { 0, 0, w, h };

		FillRect(memdc, &rc, brush);

		SelectObject(memdc, old);
		DeleteDC(memdc);
		DeleteObject(brush);
		m_nWidth = w;
		m_nHeight = h;

	}
	virtual void Draw(HDC hdc, int x, int y, COLORREF keycol){
		HDC memdc = CreateCompatibleDC(hdc);
		HBITMAP oldbm = (HBITMAP)SelectObject(memdc, m_hBitmap);
		TransparentBlt(hdc, x, y, m_nWidth*m_nWScale, m_nHeight*m_nHScale, memdc, 0, 0, m_nWidth, m_nHeight, keycol);
		SelectObject(memdc, oldbm);
		DeleteDC(memdc);
	}

	BOOL Load(LPTSTR fname){
		m_hBitmap = (HBITMAP)LoadImage(NULL, fname, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		BITMAP bitmapinfo;
		GetObject(m_hBitmap, sizeof(BITMAP), &bitmapinfo);
		m_nWidth = bitmapinfo.bmWidth;
		m_nHeight = bitmapinfo.bmHeight;
		return true;
	}
};

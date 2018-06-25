#pragma once;
#include <windows.h>

class CMyRect{
private:
	int nPosX;
	int nPosY;
	int nWidth;
	int nHeight;
public:
	CMyRect(void){
		SetRect(0, 0, 0, 0);
	}
	~CMyRect(void){
		
	}
	void SetRect(int x,int y,int w,int h){
		nPosX = x;
		nPosY = y;
		nWidth = w;
		nHeight = h;
	}
	void Offset(int x,int y){
		nPosX += x;
		nPosY += y;
	}
	bool IntersectWdth(CMyRect &rect){//œ‡ΩªºÏ≤‚
		return!(rect.nPosX+rect.nWidth<nPosX||nPosX+nWidth<rect.nPosX||rect.nPosY+rect.nHeight<nPosY||nPosY+nHeight<rect.nPosY);
	}
	void Draw(HDC dc){
		HPEN pen = CreatePen(2,2,RGB(255,255,255));
		auto old = SelectObject(dc, pen);

		MoveToEx(dc,nPosX,nPosY,0);
		LineTo(dc,nPosX+nWidth,nPosY);
		LineTo(dc, nPosX + nWidth, nPosY+nHeight);
		LineTo(dc, nPosX, nPosY+nHeight);
		LineTo(dc, nPosX, nPosY);


		SelectObject(dc, old);
		DeleteObject(pen);
	}
};
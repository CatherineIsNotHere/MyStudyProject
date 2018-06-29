#pragma once;
#include <windows.h>
#include <iostream>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "configuration.hpp"
#include "resource.h"
#include "g_cObject.h"
using namespace std;



class winIni{
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	HWND m_hStatusBar;
	HWND m_hToolbar;
	int m_nWidth;
	int m_nHeight;
public:
	winIni();
	winIni(HINSTANCE,WNDCLASSEX*);
	virtual ~winIni();
	HINSTANCE getHInst();
	HWND getHWnd();
	int getNWidth();
	int getNHeight();
	HWND getHStatusBar();
	HWND getHToolBar();
	void setHInst(HINSTANCE);
	void setHWnd(HWND);
	void setNWidth(int);
	void setNHeight(int);
	void setHStatusBar(HWND);
	void setHToolBar(HWND);
	int Run(int w, int h);

	static HWND initBars(HWND & hwnd, HWND & statusBar, HWND & toolBar);
	/*
	���ƣ�createStatusBar
	���ܣ�����״̬��
	������HWND�����ھ��
	*/
	static int createStatusBar(HWND & hwnd, HWND & statusBar);
	/*
	���ƣ�createStatusBar
	���ܣ�����������
	������HWND�����ھ��
	*/
	static int createToolBar(HWND & hwnd, HWND & toolbar);

	void initResuorce();
	void destroy();

};
void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime);
#pragma once;
#include <windows.h>
#include <iostream>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "configuration.hpp"
#include "resource.h"
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
	//static LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
	//virtual LRESULT onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	int Run(int w, int h);

	static HWND initBars(HWND & hwnd, HWND & statusBar, HWND & toolBar);
	/*
	名称：createStatusBar
	功能：创建状态栏
	参数：HWND主窗口句柄
	*/
	static int createStatusBar(HWND & hwnd, HWND & statusBar);
	/*
	名称：createStatusBar
	功能：创建工具栏
	参数：HWND主窗口句柄
	*/
	static int createToolBar(HWND & hwnd, HWND & toolbar);

	void initResource();
	static void CALLBACK repaintResource(HWND hWnd,UINT uMsg,UINT idEvent,	DWORD dwTime);
};
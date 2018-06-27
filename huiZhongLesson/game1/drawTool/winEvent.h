#pragma once
#include "winIni.h"
#include "configuration.hpp"

class winEvent:public winIni{
public:
	winEvent(HINSTANCE,WNDCLASSEX*);
	~winEvent();
	static LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
	LRESULT onEvent(HWND, UINT, WPARAM, LPARAM);
	/*
	名称：setStatusBar
	功能：将状态栏划分成多格
	参数：hwnd主窗口句柄，hstatus状态栏句柄
	*/
	static int printStatusBar(HWND, HWND);
	/*
	名称：printStatusRightBar
	功能：打印最右边状态栏的格子
	参数：hstatus状态栏句柄 lParam
	*/
	static int printStatusRightBar(HWND, LPARAM);
};

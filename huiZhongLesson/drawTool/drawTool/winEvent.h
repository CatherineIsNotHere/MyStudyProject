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
	���ƣ�setStatusBar
	���ܣ���״̬�����ֳɶ��
	������hwnd�����ھ����hstatus״̬�����
	*/
	static int printStatusBar(HWND, HWND);
	/*
	���ƣ�printStatusRightBar
	���ܣ���ӡ���ұ�״̬���ĸ���
	������hstatus״̬����� lParam
	*/
	static int printStatusRightBar(HWND, LPARAM);
};

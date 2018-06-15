#include <windows.h>
#include <iostream>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "resource.h"
#include "squareness.h"
using namespace std;

class wicket{
public:
	wicket(HINSTANCE inst);
	virtual ~wicket();
	HINSTANCE getHInst();
	HWND getHWnd();
	int getNWidth();
	int getNHeight();
	HWND getHStatusBar();
	void setHInst(HINSTANCE hInstance);
	void setHWnd(HWND hwnd);
	void setNWidth(int width);
	void setNHeight(int height);
	void setHStatusBar(HWND statusBar);
	static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	int Run(int w, int h);

	static HWND initBars(HWND & hwnd, HWND & statusBar, HWND & toolBar);
	/*
	名称：createStatusBar
	功能：创建状态栏
	参数：HWND主窗口句柄
	*/
	static int createStatusBar(HWND & hwnd, HWND & statusBar);
	/*
	名称：setStatusBar
	功能：将状态栏划分成多格
	参数：hwnd主窗口句柄，hstatus状态栏句柄
	*/
	static int setStatusBar(HWND hwnd, HWND statusBar);
	/*
	名称：printStatusRightBar
	功能：打印最右边状态栏的格子
	参数：hstatus状态栏句柄 lParam
	*/
	static int printStatusRightBar(HWND statusBar, LPARAM lParam);

	static int createToolBar(HWND & hwnd, HWND & toolbar);
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	HWND m_hStatusBar;
	HWND m_hToolbar;
	int m_nWidth;
	int m_nHeight;
};
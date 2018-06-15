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
	���ƣ�createStatusBar
	���ܣ�����״̬��
	������HWND�����ھ��
	*/
	static int createStatusBar(HWND & hwnd, HWND & statusBar);
	/*
	���ƣ�setStatusBar
	���ܣ���״̬�����ֳɶ��
	������hwnd�����ھ����hstatus״̬�����
	*/
	static int setStatusBar(HWND hwnd, HWND statusBar);
	/*
	���ƣ�printStatusRightBar
	���ܣ���ӡ���ұ�״̬���ĸ���
	������hstatus״̬����� lParam
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
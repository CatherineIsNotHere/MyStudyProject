#pragma once
#include "winIni.h"

cObject mapObject;
HDC hdc;

winIni::winIni(HINSTANCE inst,WNDCLASSEX *wc)
	:m_hInst(inst)
	{
		wndCreateConfig(wc);
		wc->hInstance = m_hInst;
}
winIni::~winIni(){
	UnregisterClass(TEXT("窗口"), m_hInst);
}


int winIni::Run(int w, int h){
	m_nWidth = w;
	m_nHeight = h;
	m_hWnd = CreateWindowEx(
		NULL, TEXT("窗口"), TEXT("窗口"),
		WS_OVERLAPPEDWINDOW,
		0,0,w, h,NULL,NULL,m_hInst,this);
	if (m_hWnd == 0){
		return -1;
	}
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
	hdc = GetDC(m_hWnd);
	initBars(m_hWnd,m_hStatusBar,m_hToolbar);
	initResuorce();
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else{
			//Sleep(100);
		}
	}
	ReleaseDC(m_hWnd, hdc);
	return 0;
}


HWND winIni::initBars(HWND & hwnd,HWND & statusBar,HWND & toolBar){
	createStatusBar(hwnd, statusBar);
	createToolBar(hwnd, toolBar);
	return hwnd;
}

int winIni::createStatusBar(HWND & hwnd,HWND & statusBar){
	statusBar = CreateWindowEx(0, STATUSCLASSNAME, __TEXT(""), WS_CHILD | WS_VISIBLE,
		0, 0, 0, 0,
		hwnd, NULL,
		GetModuleHandle(NULL), NULL);//bar
	int Rightend[3];
	RECT WinRect;
	GetClientRect(hwnd, &WinRect);
	int right = WinRect.right;
	Rightend[0] = WinRect.right / 2;
	Rightend[1] = WinRect.right - LEFT_STATUSBAR * 8;
	Rightend[2] = WinRect.right;
	SendMessage(statusBar, SB_SETPARTS, (WPARAM)3, (LPARAM)Rightend);
	return 1;
}


int winIni::createToolBar(HWND & hwnd, HWND & toolbar){
	INITCOMMONCONTROLSEX InitCtrlEx;
	InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
	InitCtrlEx.dwICC = ICC_BAR_CLASSES;
	InitCommonControlsEx(&InitCtrlEx);

	TBBUTTON tbrButtons[4];
	tbrButtons[0].iBitmap = 0;//按钮在图片资源中的索引，以0开始
	tbrButtons[0].idCommand = ID_BUTTON201;//按钮对应命令ID，一般和菜单命令对应
	tbrButtons[0].fsState = TBSTATE_ENABLED;//按钮类型
	tbrButtons[0].fsStyle = TBSTYLE_BUTTON;//按钮样式
	tbrButtons[0].dwData = 0L;//自定义数据
	tbrButtons[0].iString = 0;//按钮字符串索引

	tbrButtons[1].iBitmap = 1;
	tbrButtons[1].idCommand = ID_BUTTON202;
	tbrButtons[1].fsState = TBSTATE_ENABLED;
	tbrButtons[1].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[1].dwData = 0L;
	tbrButtons[1].iString = 0;

	tbrButtons[2].iBitmap = 0;
	tbrButtons[2].idCommand = 0;
	tbrButtons[2].fsState = TBSTATE_ENABLED;
	tbrButtons[2].fsStyle = TBSTYLE_SEP;//这个是空隙
	tbrButtons[2].dwData = 0L;
	tbrButtons[2].iString = 0;

	tbrButtons[3].iBitmap = 1;
	tbrButtons[3].idCommand = ID_BUTTON203;
	tbrButtons[3].fsState = TBSTATE_ENABLED;
	tbrButtons[3].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[3].dwData = 0L;
	tbrButtons[3].iString = 0;

	toolbar = CreateToolbarEx(
		hwnd, WS_VISIBLE | WS_CHILD | WS_BORDER,//样式
		IDR_TOOLBAR1,//工具栏ID
		4,//按钮个数
		GetModuleHandle(NULL),
		IDR_TOOLBAR1,//自定义图片的资源ID
		tbrButtons,//按钮结构数组地址
		4, 0, 0, 16, 16, sizeof(TBBUTTON)//图片大小，按钮结构size
		);

	return 1;
}

void winIni::initResuorce()
{
	mapObject.Init(TEXT("bg1_0.bmp"), 520, 851, 1, 0, 0,1.0f,1.0f);
	SetTimer(m_hWnd, 1, 60, &TimerProc);
}

void winIni::destroy()
{
	KillTimer(m_hWnd, 1);
}

void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime)
{
	mapObject.Update();
	mapObject.Draw(hdc);
}

/*
	GET AND SET
*/

HINSTANCE winIni::getHInst(){
	return m_hInst;
}
HWND winIni::getHWnd(){
	return m_hWnd;
}
int winIni::getNWidth(){
	return m_nWidth;
}
int winIni::getNHeight(){
	return m_nHeight;
}
HWND winIni::getHStatusBar(){
	return m_hStatusBar;
}
HWND winIni::getHToolBar(){
	return m_hToolbar;
}


void winIni::setHInst(HINSTANCE hInstance){
	this->m_hInst = hInstance;
}
void winIni::setHWnd(HWND hwnd){
	this->m_hWnd = hwnd;
}
void winIni::setNWidth(int width){
	this->m_nWidth = width;
}
void winIni::setNHeight(int height){
	this->m_nHeight = height;
}
void winIni::setHStatusBar(HWND statusBar){
	this->m_hStatusBar = statusBar;
}
void winIni::setHToolBar(HWND toolBar){
	this->m_hToolbar = toolBar;
}
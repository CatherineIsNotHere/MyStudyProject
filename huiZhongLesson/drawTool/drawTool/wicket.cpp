#include "wicket.h"
#include <iostream>
#include <string>
using namespace std;
wicket::wicket(HINSTANCE inst)
	:m_hInst(inst)
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = wndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInst;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = TEXT("winApp");
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		RegisterClassEx(&wc);
}
wicket::~wicket(){
	UnregisterClass(TEXT("winApp"), m_hInst);
}
HINSTANCE wicket::getHInst(){
	return m_hInst;
}
HWND wicket::getHWnd(){
	return m_hWnd;
}
int wicket::getNWidth(){
	return m_nWidth;
}
int wicket::getNHeight(){
	return m_nHeight;
}
void wicket::setHInst(HINSTANCE hInstance){
	this->m_hInst = hInstance;
}
void wicket::setHWnd(HWND hwnd){
	this->m_hWnd = hwnd;
}
void wicket::setNWidth(int width){
	this->m_nWidth = width;
}
void wicket::setNHeight(int height){
	this->m_nHeight = height;
}

LRESULT CALLBACK wicket::wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	wicket* pthis = (wicket *)GetWindowLong(hwnd, GWLP_USERDATA);
	if (pthis){
		return pthis->onEvent(hwnd, msg, wParam, lParam);
	}
	if (WM_CREATE == msg){
		CREATESTRUCT * pCreate = (CREATESTRUCT*)lParam;
		SetWindowLong(hwnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
		HWND hStatus;
		hStatus = createStatusBar(hwnd);
		setStatusBar(hwnd, hStatus);
	}
	return  DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT wicket::onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	HDC hdc;
	PAINTSTRUCT ps;
	HFONT hOldFont;
	HWND hStatus;
	int mx;//鼠标坐标
	int my;//鼠标坐标
	TCHAR charxy[16] = { 0 };
	switch (msg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		setStatusBar(hwnd,hStatus);
		break;
	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = LOWORD(lParam);
		wsprintf(charxy,TEXT("x:%d,y:%d"),mx,my);
		setStatusText(hStatus, 2, charxy);
		break;
	case WM_KEYUP:
		break;
	case WM_KEYDOWN:
		break;
	case WM_SETFOCUS:
		SetWindowText(hwnd, TEXT("winApp"));
		break;
	case WM_KILLFOCUS:
		SetWindowText(hwnd, TEXT("winApp (未响应)"));
		break;
	case WM_CLOSE:
		break;
	case WM_SIZE:
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int wicket::Run(int w, int h){
	m_nWidth = w;
	m_nHeight = h;
	m_hWnd = CreateWindowEx(
		NULL, TEXT("winApp"), TEXT("winApp"),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		w, h,
		NULL,
		NULL,
		m_hInst,
		this
		);
	if (m_hWnd == 0){
		return -1;
	}
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
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
	int i = 1;
	return 0;
}

HWND wicket::createStatusBar(HWND hwnd){
	HWND hStatus = CreateWindow(STATUSCLASSNAME, __TEXT(""), WS_CHILD | WS_VISIBLE,
		0, 0, 0, 0,
		hwnd, NULL,
		GetModuleHandle(NULL), NULL);//bar
	return hStatus;
}

HWND wicket::setStatusBar(HWND hwnd, HWND hStatus){
	int Rightend[3];
	RECT WinRect;
	GetClientRect(hwnd, &WinRect);
	Rightend[0] = WinRect.right / 3;
	Rightend[1] = WinRect.right * 2 / 3;
	Rightend[2] = WinRect.right;
	SendMessage(hStatus, SB_SETPARTS, (WPARAM)3, (LPARAM)Rightend);
	return hStatus;
}

int wicket::setStatusText(HWND hStatus, int i, TCHAR* txt){
	SendMessage(hStatus, SB_SETTEXT, (WPARAM)i, (LPARAM)txt);
	return 1;
}
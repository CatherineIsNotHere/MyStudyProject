#include <windows.h>
#include <stdio.h>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "resource.h"

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
static TCHAR szAppName[] = TEXT("MyWindow");
HWND hToolbar;
HWND hStatusBar;
UINT_PTR ID_TIMER;

HWND MakeToolbar(HWND hwnd){
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

	tbrButtons[3].iBitmap = 2;
	tbrButtons[3].idCommand = ID_A_40012;//这里使用弹出菜单的id，看运行结果
	tbrButtons[3].fsState = TBSTATE_ENABLED;
	tbrButtons[3].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[3].dwData = 0L;
	tbrButtons[3].iString = 0;

	hToolbar = CreateToolbarEx(
		hwnd, WS_VISIBLE | WS_CHILD | WS_BORDER,//样式
		IDR_TOOLBAR1,//工具栏ID
		4,//按钮个数
		GetModuleHandle(NULL),
		IDR_TOOLBAR1,//自定义图片的资源ID
		tbrButtons,//按钮结构数组地址
		4, 0, 0, 15, 15, sizeof(TBBUTTON)//图片大小，按钮结构size
		);

	return hwnd;
}
/*
	名称：MakeStatusBar
	功能：创建状态栏
	参数：HWND
*/
HWND MakeStatusBar(HWND hwnd){
	HWND hStatus;
	hStatus = CreateWindow(STATUSCLASSNAME, __TEXT(""), WS_CHILD | WS_VISIBLE,
		0, 0, 0, 0,
		hwnd, NULL,
		GetModuleHandle(NULL),NULL);
	return hStatus;
}

/*
	名称：setStatus
	功能：将状态栏划分成多格
	参数：hwnd主窗口句柄，hstatus状态栏句柄
*/
int setStatus(HWND hwnd,HWND hStatus){
	int Rightend[3];
	RECT WinRect;
	GetClientRect(hwnd,&WinRect);
	Rightend[0] = WinRect.right / 3;
	Rightend[1] = WinRect.right * 2 / 3;
	Rightend[2] = WinRect.right;
	SendMessage(hStatus,SB_SETPARTS,(WPARAM)3,(LPARAM)Rightend);
	return 1;
}

/*
	名称：setStatusText
	功能：设置状态栏某一格的标题
	参数：hStatus状态栏句柄，i第i格，txt标题
*/
int setStatusText(HWND hStatus,int i,char *txt){
	SendMessage(hStatus, SB_SETTEXT, (WPARAM)i, (LPARAM)txt);
	return 1;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevsInstance, PSTR szCmdLine, int iCmdShow){
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(WNDCLASSEX);//结构体大小
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = wndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	//wndclass.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));//两种写法
	wndclass.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 16, 16, 0);
	wndclass.hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wndclass.lpszMenuName = NULL;
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	wndclass.lpszClassName = szAppName;

	if (!RegisterClassEx(&wndclass)){
		MessageBox(NULL, TEXT("失败"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,//扩展的窗口风格
		szAppName,//窗口类名
		__TEXT("upupoo"),//窗口标题
		WS_OVERLAPPEDWINDOW,//窗口的样式参数
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,//xywh
		NULL, NULL, hInstance, NULL);//窗口的父窗口句柄，窗口菜单句柄，实例句柄，窗口创建的附加参数
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	POINT pt;
	HMENU m;
	char s[128] = {};
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, TEXT("大家好，这是我的第一个窗口程序"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(hwnd,ID_TIMER);
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_40001:
			MessageBox(hwnd, TEXT("点击了一个菜单1.1.1"), szAppName, MB_OK);
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_RBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		sprintf_s(s, "%d,%d\n", pt.x, pt.y);
		OutputDebugString((wchar_t *)s);
		m = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU2));
		m = GetSubMenu(m,0);
		ClientToScreen(hwnd,&pt);
		TrackPopupMenu(m,TPM_LEFTALIGN|TPM_RIGHTBUTTON,pt.x,pt.y,0,hwnd,NULL);
		break;
	case WM_CREATE:
		//InitCommonControls();
		MakeToolbar(hwnd);
		hStatusBar = MakeStatusBar(hwnd);
		setStatus(hwnd, hStatusBar);
		SetTimer(hwnd, ID_TIMER, 1000, NULL);
		break;
	case WM_SIZE:
		SendMessage(hToolbar, message, wParam, lParam);
		SendMessage(hStatusBar, message, wParam, lParam);
		setStatus(hwnd,hStatusBar);
		break;
	case WM_TIMER:
	{SYSTEMTIME st;
	GetLocalTime(&st);
	char str[512] = { 0 };
	sprintf_s(str, sizeof(str),"%2d:%2d:%2d", st.wHour, st.wMinute, st.wSecond);
	setStatusText(hStatusBar, 1, str);
	}
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;

}
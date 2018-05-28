#include <windows.h>
#include "resource.h"

LRESULT CALLBACK wndProc(HWND,UINT,WPARAM,LPARAM);
static TCHAR szAppName[] = TEXT("MyWindow");
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevsInstance,PSTR szCmdLine,int iCmdShow){
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(WNDCLASSEX);//结构体大小
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = wndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(IDI_ICON1));
	//wndclass.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));//两种写法
	wndclass.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 16, 16, 0);
	wndclass.hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	//wndclass.lpszMenuName = NULL;
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	wndclass.lpszClassName = szAppName;

	if (!RegisterClassEx(&wndclass)){
		MessageBox(NULL, TEXT("失败"),szAppName,MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,//扩展的窗口风格
		szAppName,//窗口类名
		__TEXT("upupoo"),//窗口标题
		WS_OVERLAPPEDWINDOW,//窗口的样式参数
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,//xywh
		NULL, NULL, hInstance, NULL);//窗口的父窗口句柄，窗口菜单句柄，实例句柄，窗口创建的附加参数
		ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg,NULL,0,0))
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
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		GetClientRect(hwnd,&rect);
		DrawText(hdc,TEXT("大家好，这是我的第一个窗口程序"),-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		EndPaint(hwnd,&ps);
		break;
	case WM_DESTROY:
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
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
	
}
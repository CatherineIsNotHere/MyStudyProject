#include <windows.h>
#include <stdio.h>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "resource.h"

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
static TCHAR szAppName[] = TEXT("MyWindow");
HWND hToolbar;

HWND MakeToolbar(HWND hwnd){
	INITCOMMONCONTROLSEX InitCtrlEx;
	InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
	InitCtrlEx.dwICC = ICC_BAR_CLASSES;
	InitCommonControlsEx(&InitCtrlEx);
	
	TBBUTTON tbrButtons[4];
	tbrButtons[0].iBitmap = 0;//��ť��ͼƬ��Դ�е���������0��ʼ
	tbrButtons[0].idCommand = ID_BUTTON201;//��ť��Ӧ����ID��һ��Ͳ˵������Ӧ
	tbrButtons[0].fsState = TBSTATE_ENABLED;//��ť����
	tbrButtons[0].fsStyle = TBSTYLE_BUTTON;//��ť��ʽ
	tbrButtons[0].dwData = 0L;//�Զ�������
	tbrButtons[0].iString = 0;//��ť�ַ�������

	tbrButtons[1].iBitmap = 1;
	tbrButtons[1].idCommand = ID_BUTTON202;
	tbrButtons[1].fsState = TBSTATE_ENABLED;
	tbrButtons[1].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[1].dwData = 0L;
	tbrButtons[1].iString = 0;

	tbrButtons[2].iBitmap = 0;
	tbrButtons[2].idCommand = 0;
	tbrButtons[2].fsState = TBSTATE_ENABLED;
	tbrButtons[2].fsStyle = TBSTYLE_SEP;//����ǿ�϶
	tbrButtons[2].dwData = 0L;
	tbrButtons[2].iString = 0;

	tbrButtons[3].iBitmap = 2;
	tbrButtons[3].idCommand = ID_A_40012;//����ʹ�õ����˵���id�������н��
	tbrButtons[3].fsState = TBSTATE_ENABLED;
	tbrButtons[3].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[3].dwData = 0L;
	tbrButtons[3].iString = 0;

	hToolbar = CreateToolbarEx(
		hwnd, WS_VISIBLE | WS_CHILD | WS_BORDER,//��ʽ
		IDR_TOOLBAR1,//������ID
		4,//��ť����
		GetModuleHandle(NULL),
		IDR_TOOLBAR1,//�Զ���ͼƬ����ԴID
		tbrButtons,//��ť�ṹ�����ַ
		4, 0, 0, 15, 15, sizeof(TBBUTTON)//ͼƬ��С����ť�ṹsize
		);

	return hwnd;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevsInstance, PSTR szCmdLine, int iCmdShow){
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(WNDCLASSEX);//�ṹ���С
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = wndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	//wndclass.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));//����д��
	wndclass.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 16, 16, 0);
	wndclass.hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wndclass.lpszMenuName = NULL;
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	wndclass.lpszClassName = szAppName;

	if (!RegisterClassEx(&wndclass)){
		MessageBox(NULL, TEXT("ʧ��"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,//��չ�Ĵ��ڷ��
		szAppName,//��������
		__TEXT("upupoo"),//���ڱ���
		WS_OVERLAPPEDWINDOW,//���ڵ���ʽ����
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,//xywh
		NULL, NULL, hInstance, NULL);//���ڵĸ����ھ�������ڲ˵������ʵ����������ڴ����ĸ��Ӳ���
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
		DrawText(hdc, TEXT("��Һã������ҵĵ�һ�����ڳ���"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_40001:
			MessageBox(hwnd, TEXT("�����һ���˵�1.1.1"), szAppName, MB_OK);
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
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;

}
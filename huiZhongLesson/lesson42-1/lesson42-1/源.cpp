#include <windows.h>
#include <commctrl.h>
#pragma comment(lib,"comctl32")
static TCHAR szAppName[] = TEXT("MyWindow");
HANDLE hThread;
DWORD ip;
DWORD WINAPI PBThreadProc(LPVOID lpParameter);
LRESULT CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	static HWND hwndPB;
	static RECT rc;
	switch (msg)
	{
	case WM_CREATE:
		InitCommonControls();
		hwndPB=CreateWindowEx(
			0, PROGRESS_CLASS,
			NULL, WS_CHILD | WS_VISIBLE,
			0, 0, 0, 0,
			hwnd, HMENU(0), GetModuleHandle(NULL), NULL
			);
		hThread=CreateThread(//创建线程
			NULL,//安全属性，默认为null
			0,//线程堆栈大小，默认为0
			PBThreadProc,//线程回调函数
			hwndPB,//回调函数的参数
			0,//启动方式，0是立即执行线程
			&ip//被填充的线程id
			);
		break;
	case WM_SIZE:
		GetClientRect(hwnd, &rc);
		MoveWindow(
			hwndPB, rc.left,
			(rc.bottom - rc.top) / 4,
			rc.right - rc.left,
			(rc.bottom - rc.top) / 10,
			TRUE
			);
		//SendMessage(hwndPB, PBM_SETBKCOLOR, 0, (LPARAM)color);//设置进度条背景颜色
		//SendMessage(hwndPB,PBM_SETRANGE,0,MAKELPARAM(0,150));//设置范围
		//SendMessage(hwndPB,PBM_GETRANGE,TRUE,(LPARAM)&range);//获取范围
		//SendMessage(hwndPB,PBM_DELTAPOS,WPARAM((range.iHigh-range.iLow)/20),0);//设置当前值

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int iCmdShow){
	WNDCLASSEX wc;
	MSG msg;
	HWND hwnd;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = DlgProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//光标
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//小图标
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("失败"), szAppName, MB_ICONERROR);
		return 0;
	}
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		szAppName,
		TEXT("UPUPOO"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL
		);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	WaitForSingleObject(hThread,INFINITE);
	CloseHandle(hThread);
	return 0;
}

DWORD WINAPI PBThreadProc(LPVOID lpParameter){
	COLORREF color = RGB(1, 255, 1);
	static PBRANGE range;
	HWND hwnd = (HWND)lpParameter;
	SendMessage(hwnd, PBM_SETBKCOLOR, 0, (LPARAM)color);//设置进度条背景颜色
	SendMessage(hwnd, PBM_SETRANGE, 0, MAKELPARAM(0, 150));//设置范围
	SendMessage(hwnd, PBM_GETRANGE, TRUE, (LPARAM)&range);//获取范围
	while (true)
	{
		Sleep(100);
		SendMessage(hwnd, PBM_DELTAPOS, WPARAM((range.iHigh - range.iLow) / 20), 0);//设置当前值
		if (SendMessage(hwnd,PBM_GETPOS,0,0)==150){
			ExitThread(0);
			break;
			SendMessage(hwnd,PBM_SETPOS,0,0);
		}
	}
	return 0;
}
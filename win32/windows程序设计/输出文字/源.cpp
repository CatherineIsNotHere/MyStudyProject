#include <windows.h>

static WCHAR szAppName[] = TEXT("这是一个APP");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpszClassName = szAppName;
	wc.lpszMenuName = NULL;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0; 
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hIconSm = NULL;
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL,TEXT("注册失败"),TEXT("FAIL"),NULL);
	}
	hwnd = CreateWindowEx(
		NULL,szAppName,
		TEXT("hello window"),
		WS_OVERLAPPEDWINDOW,
		0,0,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,NULL,
		hInstance,NULL
		);
	if (hwnd==0){
		return -1;
	}
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.lParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam){
	HDC hdc;
	PAINTSTRUCT ps;
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		//hdc = BeginPaint(hwnd, &ps);//使用GDI函数
		//EndPaint(hwnd,&ps);

		hdc = GetDC(hwnd);//使用GDI函数
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return DefWindowProc(hwnd,message,wparam,lparam);
}
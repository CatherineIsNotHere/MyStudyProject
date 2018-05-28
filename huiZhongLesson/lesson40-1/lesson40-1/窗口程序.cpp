#include <windows.h>
//#include <tchar.h>
const wchar_t g_szClassName[] = __TEXT("mywindowsclass");
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,msg,wparam,lparam);
	}
	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdshow)
{
	MessageBox(NULL, __TEXT("HELLO WIN32"), __TEXT("windows program"), MB_OK);
	//1注册窗口类
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);//结构体大小
	wc.style = 0;//类的风格，通常为0即可
	wc.lpfnWndProc = WndProc;//消息处理回调函数
	wc.cbWndExtra = 0;//内存中为这个窗口额外分配的数量大小，通常为0
	wc.cbClsExtra = 0;//内存中为这个类分配的额外的数据量大小，通常外0
	wc.hInstance = hInstance;//实例句柄
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);//图标
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);//光标
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//背景色
	wc.lpszMenuName = NULL;//菜单
	wc.lpszClassName = g_szClassName;//类名
	wc.hIconSm = LoadIcon(NULL,IDI_APPLICATION);//小图标
	if (!RegisterClassEx(&wc)){//出则窗口类
		MessageBox(NULL,__TEXT("窗口注册失败！"),__TEXT("error"),MB_OK);
		return 0;
	}
	//2创建窗口
	HWND hwnd=CreateWindowEx(
			WS_EX_CLIENTEDGE,//扩展的窗口风格
			g_szClassName,//窗口类名
			__TEXT("this is title"),//窗口标题
			WS_OVERLAPPEDWINDOW,//窗口的样式参数
			CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,//xywh
			NULL, NULL, hInstance, NULL);//窗口的父窗口句柄，窗口菜单句柄，实例句柄，窗口创建的附加参数
	if (hwnd==NULL){
		MessageBox(NULL,__TEXT("窗口创建失败"),__TEXT("error"),MB_OK);
		return 0;
	}
	//3显示更新
	ShowWindow(hwnd,nCmdshow);
	UpdateWindow(hwnd);
	//4消息循环
	MSG msg;
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//UnregisterClass();

	return 0;
}

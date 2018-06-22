#pragma once//执行一次
#include <windows.h>
#pragma  comment(lib,"msimg32.lib")//加载库文件
class CWinAPP
{
public:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	int m_nWidth;
	int m_nHeight;
	CWinAPP(HINSTANCE inst)
		:m_hInst(inst)
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(wc);//结构体
		wc.style = 0;//类的风格，通常为0即可
		wc.lpfnWndProc = wndProc;// 消息处理回调函数
		wc.cbClsExtra = 0;//内存中为这个类分配的额外的数据量大小，通常为0
		wc.cbWndExtra = 0;//内存中为这个窗口额外分配的数据量大小，通常为0
		wc.hInstance = m_hInst;//实例句柄
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//鼠标
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);//光标
		wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//背景色
		wc.lpszMenuName = NULL;//菜单
		wc.lpszClassName = TEXT("WinApp"); //第3行的命名 类名
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		RegisterClassEx(&wc);
	}
	virtual ~CWinAPP()
	{
		UnregisterClass(TEXT("WinApp"), m_hInst);
	}


	static  LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam)
	{
		CWinAPP* pthis = (CWinAPP *)GetWindowLong(hwnd, GWL_USERDATA);//类名
		if (pthis)
		{
			return pthis->onEvent(hwnd, msg, wParam, lparam);
		}
		if (WM_CREATE == msg)
		{

			CREATESTRUCT* pCreate = (CREATESTRUCT*)lparam;
			SetWindowLong(hwnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
		}
		return DefWindowProc(hwnd, msg, wParam, lparam);
	}


	virtual  LRESULT  onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam)
	{
		HDC hdc;           //DC 设备上下文 
		PAINTSTRUCT ps;
		switch (msg)
		{
		case WM_KEYDOWN://按键
			switch (wParam)
			{
			case VK_SPACE:
				break;
			case VK_ESCAPE:
				PostQuitMessage(0);//关闭
				break;
			}
			break;
		case WM_KEYUP:
			break;
		case WM_SETFOCUS: //变为后台内存节省 
			SetWindowText(hwnd, TEXT("获取焦点"));
			break;
		case WM_KILLFOCUS:
			SetWindowText(hwnd, TEXT("失去焦点"));
			break;
		case WM_CLOSE:
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		case WM_MOUSEMOVE:
			break;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			drawBitmap(hwnd,hdc);
			EndPaint(hwnd, &ps);

			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lparam);
		}
		return S_OK;
	}

	int run(int w, int h)
	{
		m_nHeight = h;
		m_nWidth = w;
		m_hWnd = CreateWindowEx(NULL,
			TEXT("WinApp"),
			TEXT("WinApp"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			w,
			h,
			NULL,
			NULL,
			m_hInst,
			this
			);
		if (m_hWnd == 0)
		{
			return -1;
		}
		//显示更新
		ShowWindow(m_hWnd, SW_SHOW);

		MSG msg = { 0 };
		while (msg.message != WM_QUIT)//退出 
		{
			if (msg.message == WM_DESTROY || msg.message == WM_CLOSE)
			{
				break;
			}
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Sleep(1);
			}
		}

		return 0;
	}
	
	int drawBitmap(HWND hwnd,HDC hdc){
		TCHAR fname[MAX_PATH] = {};
		HBITMAP hbitmap;
		HBITMAP holdmp;
		BITMAP bitmapInfo;
		GetCurrentDirectory(MAX_PATH, fname);
		wcscat_s(fname, MAX_PATH, TEXT("\\bmp\\nichousha.bmp"));
		hbitmap = (HBITMAP)LoadImageW(NULL, fname, IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hbitmap, sizeof(BITMAP), &bitmapInfo);//获取位图信息
		int w = bitmapInfo.bmWidth;
		int h = bitmapInfo.bmHeight;
		HDC hmemdc = CreateCompatibleDC(hdc);//创建兼容DC
		holdmp=(HBITMAP)SelectObject(hmemdc, hbitmap);//将位图放到兼容dc里
		//BitBlt(hdc,0,0,w,h,hmemdc,0,0,SRCCOPY);//太老了
		TransparentBlt(hdc,0,0,w,h,hmemdc,0,0,w,h,RGB(255,255,255));//去白色背景
		SelectObject(hmemdc, holdmp);//反操作
		DeleteObject(hbitmap);
		DeleteDC(hmemdc);
		return 1;
	}

protected:
private:

};
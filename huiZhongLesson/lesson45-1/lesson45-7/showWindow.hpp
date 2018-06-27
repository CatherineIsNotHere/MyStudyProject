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
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			DrawPath(hdc);
			EndPaint(hwnd, &ps);
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
		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);
		MSG msg = { 0 };
		while (msg.message != WM_QUIT)//退出 
		{

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

	void DrawPath(HDC dc){
		SetBkMode(dc, TRANSPARENT);
		RECT rc = {100,100,800,300};
		HFONT hfont= CreateFont(200, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, TEXT("微软雅黑"));
		HFONT holdFont = (HFONT)SelectObject(dc, hfont);
		HPEN penl = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		auto pOldPen = SelectObject(dc, penl);
		HBRUSH brush1 = CreateSolidBrush(RGB(255,0,0));
		auto poldBrush = SelectObject(dc, brush1);
		BeginPath(dc);
		TCHAR s[] = TEXT("来玩啊...");
		DrawText(dc,s,wcslen(s),&rc,DT_CENTER|DT_VCENTER);
		EndPath(dc);
		//StrokePath(dc);//描边
		//FillPath(dc);//填充
		//StrokeAndFillPath(dc);
		{
			auto newbrush = CreateHatchBrush(HS_DIAGCROSS,0xff00ff);
			auto rgn = PathToRegion(dc);
			//FillRgn(dc,rgn,newbrush);
			FrameRgn(dc,rgn,newbrush,2,2);
			DeleteObject(newbrush);
		}
		SelectObject(dc,holdFont);
		SelectObject(dc, pOldPen);
		SelectObject(dc, poldBrush);
		DeleteObject(hfont);
		DeleteObject(penl);
		DeleteObject(brush1);
	}
protected:
private:

};




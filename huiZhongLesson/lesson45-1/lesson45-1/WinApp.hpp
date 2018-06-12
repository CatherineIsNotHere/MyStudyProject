#pragma once
#include <windows.h>
#include <tchar.h>
#include<math.h> 

class CWinApp
{
public:
	CWinApp(HINSTANCE inst)
		:m_hInst(inst)
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = wndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInst;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//图标
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);//光标
		wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = TEXT("winApp");
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//小图标
		RegisterClassEx(&wc);
	};
	virtual ~CWinApp(){
		UnregisterClass(TEXT("winApp"), m_hInst);
	}
	HINSTANCE getHInst(){
		return m_hInst;
	}
	HWND getHWnd(){
		return m_hWnd;
	}
	int getNWidth(){
		return m_nWidth;
	}
	int getNHeight(){
		return m_nHeight;
	}
	void setHInst(HINSTANCE hInstance){
		this->m_hInst = hInstance;
	}
	void setHWnd(HWND hwnd){
		this->m_hWnd = hwnd;
	}
	void setNWidth(int width){
		this->m_nWidth = width;
	}
	void setNHeight(int height){
		this->m_nHeight = height;
	}
	static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
		CWinApp* pthis = (CWinApp *)GetWindowLong(hwnd, GWLP_USERDATA);
		if (pthis){
			return pthis->onEvent(hwnd, msg, wParam, lParam);
		}
		if (WM_CREATE == msg){
			CREATESTRUCT * pCreate = (CREATESTRUCT*)lParam;
			SetWindowLong(hwnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
		}
		return  DefWindowProc(hwnd, msg, wParam, lParam);
	}
	virtual LRESULT onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
		HDC hdc;
		PAINTSTRUCT ps;
		TCHAR szText[64] = TEXT("这是测试汉字this is test!");
		RECT rc;//矩形
		HFONT hfont;
		HFONT hOldFont;
		double y = 0;
		double r = 100;
		switch (msg)
		{
		case WM_CLOSE:
			break;
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		case WM_MOUSEMOVE:
			break;
		case WM_KEYUP:
			switch (wParam)
			{
			case VK_SPACE:
				break;
			case VK_ESCAPE:
				PostQuitMessage(0);
				break;
			default:
				break;
			}
			break;
		case WM_KEYDOWN:
			break;
		case WM_SETFOCUS:
			SetWindowText(hwnd,TEXT("winApp"));
			break;
		case WM_KILLFOCUS:
			SetWindowText(hwnd, TEXT("winApp (未响应)"));
			break;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);//开始绘图
			SetBkMode(hdc, TRANSPARENT);//去掉背景框
			SetTextColor(hdc, RGB(255, 0, 255));//文字颜色
			//TextOut(hdc, 100, 200, szText, _tcslen(szText));//输出文字，可以精准定位xy,不能换行
			GetClientRect(hwnd, &rc);//获取客户区尺寸
			//DrawText(hdc,szText,-1,&rc,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			hfont = CreateFont(
				50,//字符高度
				0,//字符宽度
				0,//文字倾斜角度
				0,//字体倾斜角度
				FW_BOLD,//笔画的粗细
				0,//是否是斜体
				0,//是否加下划线
				0,//是否在字体中加水平线
				ANSI_CHARSET,//字符集
				0,//字体输出方式
				0,//裁剪字体的方式
				0,//字体质量
				0,//字体系列和字体宽度设定
				TEXT("楷体")//字样名
				);
			hOldFont = (HFONT)SelectObject(hdc, hfont);//选择新的字体，返回老的字体
			SetTextColor(hdc, RGB(0X00, 0Xff, 0Xff));
			TextOut(hdc, 0, 300, szText, _tcslen(szText));
			SelectObject(hdc, hOldFont);
			DeleteObject(hfont);

			//画一条线
			/*for (int m = 0; m < 100;m++)
			{
			SetPixel(hdc,m,100,RGB(0,255,0));
			}*/
			//画一个圆
			for (double x = 100; x > 0; x--)
			{
				y = sqrt(r*r - x*x);
				SetPixel(hdc, x + 200, y + 200, RGB(0, 255, 0));
				SetPixel(hdc, y + 200, x + 200, RGB(0, 255, 0));
			}
			for (double x = 100; x > 0; x--)
			{
				y = sqrt(r*r - x*x);
				SetPixel(hdc, 200 - x, 200 + y, RGB(0, 255, 0));
				SetPixel(hdc, 200 + y, 200 - x, RGB(0, 255, 0));
			}
			for (double x = 100; x > 0; x--)
			{
				y = sqrt(r*r - x*x);
				SetPixel(hdc, 200 - x, 200 - y, RGB(0, 255, 0));
				SetPixel(hdc, 200 - y, 200 - x, RGB(0, 255, 0));
			}
			for (double x = 100; x > 0; x--)
			{
				y = sqrt(r*r - x*x);
				SetPixel(hdc, 200 + x, 200 - y, RGB(0, 255, 0));
				SetPixel(hdc, 200 - y, 200 + x, RGB(0, 255, 0));
			}

			EndPaint(hwnd, &ps);//释放内存
			break;
		default:
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	int Run(int w, int h){
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
				Sleep(1);
			}
		}
		int i = 1;
		return 0;
	}
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	int m_nWidth;
	int m_nHeight;
};

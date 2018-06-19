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
		TCHAR swindowText[32] = { 0 };
		RECT rc;//矩形
		HFONT hfont;
		HFONT hOldFont;
		double y = 0;
		double r = 100;
		static POINT apt[4];//构成曲线的四个点
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			/*hdc = GetDC(m_hWnd);
			FillCircle(hdc, LOWORD(lParam), HIWORD(lParam), 5, RGB(85,200, 100));
			ReleaseDC(hwnd, hdc);*/
		case WM_RBUTTONDOWN:
		case WM_MOUSEMOVE:
			if (wParam & MK_LBUTTON){
				apt[1].x = LOWORD(lParam);
				apt[1].y = HIWORD(lParam);
			}
			if (wParam & MK_RBUTTON){
				apt[2].x = LOWORD(lParam);
				apt[2].y = HIWORD(lParam);
			}
			InvalidateRect(hwnd, NULL, TRUE);//使窗口无效导致重画
			break;
		case WM_CLOSE:
			break;
		case WM_DESTROY:
			::PostQuitMessage(0);
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
			//DrawPolygon(m_hWnd);
			break;
		case WM_SETFOCUS:
			//SetWindowText(hwnd,TEXT("winApp"));
			break;
		case WM_KILLFOCUS:
			SetWindowText(hwnd, TEXT("winApp (未响应)"));
			break;
		case WM_PAINT:
			hdc = BeginPaint(m_hWnd, &ps);
			bezierCurves(hwnd, hdc, apt);
			EndPaint(hwnd,&ps);
			break;
		case WM_SIZE:
			setNWidth(LOWORD(lParam));
			setNHeight(HIWORD(lParam));
			wsprintf(swindowText,TEXT("x:%d,y:%d"),m_nWidth,m_nHeight);
			SetWindowText(hwnd, swindowText);//设置标题栏内容
			apt[0].x = m_nWidth / 4;
			apt[0].y = m_nHeight / 2;
			apt[1].x = m_nWidth / 2;
			apt[1].y = m_nHeight / 4;
			apt[2].x = m_nWidth / 2;
			apt[2].y = m_nHeight / 4 * 3;
			apt[3].x = m_nWidth / 4 * 3;
			apt[3].y = m_nHeight / 2;
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
				//Sleep(100);
			}
		}
		int i = 1;
		return 0;
	}
	static void DrawPolygon(HWND hwnd){//画多边形
		HDC hdc;
		hdc = GetDC(hwnd);
		HBRUSH hbrushNew = (HBRUSH)GetStockObject(WHITE_BRUSH);
		HBRUSH hbrushOld = (HBRUSH)SelectObject(hdc,hbrushNew);
		POINT p[] = {
			50,320,50,350,100,400,200,400,200,350,200,300,150,300,100,280
		};
		Polygon(hdc,p,8);
		SelectObject(hdc, hbrushOld);
		DeleteObject(hbrushNew);
		ReleaseDC(hwnd,hdc);
	}
	static void DrawRectangle(HWND hwnd){//画矩形
		RECT rc;
		GetClientRect(hwnd,&rc);
		HBRUSH hbrush=CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
		RECT r;
		auto w = rc.right - rc.left;
		auto h = rc.bottom - rc.top;
		SetRect(&r, rand()%w,rand()%h,rand()%w,rand()%h);
		HDC dc = GetDC(hwnd);
		FillRect(dc,&r,hbrush);
		ReleaseDC(hwnd,dc);
		DeleteObject(hbrush);

	}
	static void FillCircle(HDC hdc, int x, int y, int d, COLORREF col){//画圆
		HBRUSH brush = CreateSolidBrush(col);
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);
		HPEN pen = CreatePen(PS_SOLID, 0.1, 0X000000);
		HPEN oldpen = (HPEN)SelectObject(hdc, pen);
		Ellipse(hdc, x - d / 2,y - d / 2, x + d / 2, y + d / 2);
		SelectObject(hdc, oldpen);
		SelectObject(hdc, oldbrush);
		DeleteObject(pen);
		DeleteObject(brush);
	}

	static void bezierCurves(HWND hwnd,HDC hdc,POINT apt[]){//贝兹曲线

		PolyBezier(hdc,apt,4);
		MoveToEx(hdc,apt[0].x,apt[0].y,NULL);
		LineTo(hdc,apt[1].x,apt[1].y);
		MoveToEx(hdc, apt[2].x, apt[2].y, NULL);
		LineTo(hdc, apt[3].x, apt[3].y);
		FillCircle(hdc,apt[0].x ,apt[0].y , 10, RGB(85, 200, 100));
		FillCircle(hdc, apt[1].x, apt[1].y, 10, RGB(85, 200, 100));
		FillCircle(hdc, apt[2].x, apt[2].y, 10, RGB(85, 200, 100));
		FillCircle(hdc, apt[3].x, apt[3].y, 10, RGB(85, 200, 100));
	}
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	int m_nWidth;
	int m_nHeight;
};

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
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ͼ��
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);//���
		wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = TEXT("winApp");
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//Сͼ��
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
		TCHAR szText[64] = TEXT("���ǲ��Ժ���this is test!");
		RECT rc;//����
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
				//DrawRectangle(m_hWnd);
				hdc = GetDC(m_hWnd);
				FillCircle(hdc, rand() % m_nWidth, rand() % m_nHeight, rand() % 300, RGB(rand() % 256, rand() % 256, rand() % 256));
				ReleaseDC(hwnd, hdc);
				break;
			case VK_ESCAPE:
				PostQuitMessage(0);
				break;
			default:
				break;
			}
			break;
		case WM_KEYDOWN:
			DrawPolygon(m_hWnd);
			break;
		case WM_SETFOCUS:
			SetWindowText(hwnd,TEXT("winApp"));
			break;
		case WM_KILLFOCUS:
			SetWindowText(hwnd, TEXT("winApp (δ��Ӧ)"));
			break;
		case WM_PAINT:
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
	static void DrawPolygon(HWND hwnd){
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
	static void DrawRectangle(HWND hwnd){
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
	static void FillCircle(HDC hdc, int x, int y, int d, COLORREF col){
		HBRUSH brush = CreateSolidBrush(col);
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);
		HPEN pen = CreatePen(PS_SOLID, 2, 0X000000);
		HPEN oldpen = (HPEN)SelectObject(hdc, pen);
		Ellipse(hdc, x - d / 2,y - d / 2, x + d / 2, y + d / 2);
		SelectObject(hdc, oldpen);
		SelectObject(hdc, oldbrush);
		DeleteObject(pen);
		DeleteObject(brush);

	}
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	int m_nWidth;
	int m_nHeight;
};

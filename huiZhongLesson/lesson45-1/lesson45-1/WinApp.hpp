#pragma once
#include <windows.h>

class CWinApp
{
public:
	CWinApp(HINSTANCE inst)
		:m_hInst(inst)
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW|CS_VREDRAW|CS_OWNDC;
		wc.lpfnWndProc = onEvent;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInst;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//图标
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);//光标
		wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = TEXT("WINAPP");
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//小图标
		RegisterClassEx(&wc);
		DWORD DW=GetLastError();
	};
	virtual ~CWinApp(){
		UnregisterClass(TEXT("WINAPP"),m_hInst);
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
		this->m_hInst=hInstance;
	}
	void setHWnd(HWND hwnd){
		this-> m_hWnd=hwnd;
	}
	void setNWidth(int width){
		this-> m_nWidth=width;
	}
	void setNHeight(int height){
		this-> m_nHeight=height;
	}
	static LRESULT CALLBACK onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
		switch (msg)
		{
		case WM_CLOSE:
			break;
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		case WM_CREATE:
			break;
		default:
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	int Run(int w,int h){
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
			NULL
			);
		if (m_hWnd==0){
			return -1;
		}
		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);
		MSG msg = {0};
		while (msg.message != WM_QUIT)
		{
			if (msg.message==WM_DESTROY||msg.message==WM_CLOSE){
				break;
			}
			if (PeekMessage(&msg,m_hWnd,0,0,PM_REMOVE)){
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else{
				Sleep(1);
			}
		}
		return 1;
	}
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	int m_nWidth;
	int m_nHeight;
};

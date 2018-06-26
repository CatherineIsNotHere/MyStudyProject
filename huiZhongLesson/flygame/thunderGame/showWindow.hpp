#pragma once//执行一次
#include <windows.h>
#include "mybitmap.hpp"
#include "mysprite.hpp"
#include "myrect.hpp"
#include "MyObject.hpp"
#include "myMaps.hpp"
#include "myEnermy.hpp"
#pragma  comment(lib,"msimg32.lib")//加载库文件

HWND hwnd;
HDC hdc;
CMyObject obj; 
CMymaps map;
CMyEnermy *enms;
CMyEnermy boss;
int enmsNum = 20;
void Init();
void Repaint();
void Destroy();
void newEnermy();
int x = 0;

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
			//drawBitmap(hwnd, hdc);
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
			NULL,
			50,
			50,
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
		UpdateWindow(m_hWnd);
		//CMyBitmap bmp(TEXT("D://nichousha.bmp"));
		hwnd = m_hWnd;
		hdc = GetDC(m_hWnd);
		Init();
		//bmp.Draw(hdc, 0, 0, RGB(255, 0, 255));
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
		ReleaseDC(m_hWnd, hdc);
		return 0;
	}


protected:
private:

};

void Init(){
	obj.Init(TEXT(".\\player1.bmp"), 128, 128, 2, 196, 723,0.25f,0.5f);
	map.Init(TEXT("bg1_0.bmp"),520,851,1,0,0,1.0f,1.0f);
	boss.Init(TEXT(".\\enermy1.bmp"), 128, 128, 2, 196, 0, 0.25f, 0.5f);
	SetTimer(hwnd, 1, 50, (TIMERPROC)Repaint);
	//SetTimer(hwnd, 2, 400, (TIMERPROC)newEnermy);
}

void Repaint(){
	
	map.Update();
	map.Draw(hdc);
	obj.Update();
	obj.Draw(hdc);
	boss.Update();
	boss.Draw(hdc);
	/*for (int i = 0; i < enmsNum;i++){
		if (enms!=NULL){
		enms->Update();
		enms->Draw(hdc);
		enms++;
		}
	}*/
}
void newEnermy(){
	enms = new CMyEnermy[enmsNum];
	enms->Init(TEXT(".\\player1.bmp"), 128, 128, 2, 0, 0, 0.25f, 0.5f);
	
}

void Destroy(){
	KillTimer(hwnd, 1);
	//KillTimer(hwnd, 2);
}

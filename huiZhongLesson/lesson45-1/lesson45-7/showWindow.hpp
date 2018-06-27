#pragma once//ִ��һ��
#include <windows.h>
#pragma  comment(lib,"msimg32.lib")//���ؿ��ļ�


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
		wc.cbSize = sizeof(wc);//�ṹ��
		wc.style = 0;//��ķ��ͨ��Ϊ0����
		wc.lpfnWndProc = wndProc;// ��Ϣ����ص�����
		wc.cbClsExtra = 0;//�ڴ���Ϊ��������Ķ������������С��ͨ��Ϊ0
		wc.cbWndExtra = 0;//�ڴ���Ϊ������ڶ���������������С��ͨ��Ϊ0
		wc.hInstance = m_hInst;//ʵ�����
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//���
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);//���
		wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//����ɫ
		wc.lpszMenuName = NULL;//�˵�
		wc.lpszClassName = TEXT("WinApp"); //��3�е����� ����
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		RegisterClassEx(&wc);
	}
	virtual ~CWinAPP()
	{
		UnregisterClass(TEXT("WinApp"), m_hInst);
	}


	static  LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam)
	{
		CWinAPP* pthis = (CWinAPP *)GetWindowLong(hwnd, GWL_USERDATA);//����
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
		HDC hdc;           //DC �豸������ 
		PAINTSTRUCT ps;
		switch (msg)
		{
		case WM_KEYDOWN://����
			switch (wParam)
			{
			case VK_SPACE:
				break;
			case VK_ESCAPE:
				PostQuitMessage(0);//�ر�
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
		case WM_SETFOCUS: //��Ϊ��̨�ڴ��ʡ 
			SetWindowText(hwnd, TEXT("��ȡ����"));
			break;
		case WM_KILLFOCUS:
			SetWindowText(hwnd, TEXT("ʧȥ����"));
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
		while (msg.message != WM_QUIT)//�˳� 
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
		HFONT hfont= CreateFont(200, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, TEXT("΢���ź�"));
		HFONT holdFont = (HFONT)SelectObject(dc, hfont);
		HPEN penl = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		auto pOldPen = SelectObject(dc, penl);
		HBRUSH brush1 = CreateSolidBrush(RGB(255,0,0));
		auto poldBrush = SelectObject(dc, brush1);
		BeginPath(dc);
		TCHAR s[] = TEXT("���氡...");
		DrawText(dc,s,wcslen(s),&rc,DT_CENTER|DT_VCENTER);
		EndPath(dc);
		//StrokePath(dc);//���
		//FillPath(dc);//���
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




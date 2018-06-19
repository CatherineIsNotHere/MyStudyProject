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
		//��ʾ����
		ShowWindow(m_hWnd, SW_SHOW);

		MSG msg = { 0 };
		while (msg.message != WM_QUIT)//�˳� 
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
		GetObject(hbitmap, sizeof(BITMAP), &bitmapInfo);//��ȡλͼ��Ϣ
		int w = bitmapInfo.bmWidth;
		int h = bitmapInfo.bmHeight;
		HDC hmemdc = CreateCompatibleDC(hdc);//��������DC
		holdmp=(HBITMAP)SelectObject(hmemdc, hbitmap);//��λͼ�ŵ�����dc��
		//BitBlt(hdc,0,0,w,h,hmemdc,0,0,SRCCOPY);//̫����
		TransparentBlt(hdc,0,0,w,h,hmemdc,0,0,w,h,RGB(255,255,255));//ȥ��ɫ����
		SelectObject(hmemdc, holdmp);//������
		DeleteObject(hbitmap);
		DeleteDC(hmemdc);
		return 1;
	}

protected:
private:

};
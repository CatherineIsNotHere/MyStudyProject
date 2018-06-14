#pragma once//ִ��һ��
#include <windows.h>
#include <tchar.h>
#include <math.h>
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
			hdc = BeginPaint(hwnd, &ps);//��ʼ��ͼ
			//	  wchar_t szText[64] = TEXT("���ǲ��Ժ��� this is test!");
			//	 SetTextColor(hdc, RGB(255, 0, 255)); //������ɫ
			//	 //������� ��׼��λ�����ܻ���
			//	 SetBkMode(hdc, TRANSPARENT); //ȥ��������
			//	 TextOut(hdc, 100, 200, szText, _tcslen(szText)); //_tcslen ���� �ļ�ͷ tchar.h

			//	 RECT rc;//����
			//	 GetClientRect(hwnd, &rc); //��ȡ�ͻ����ߴ�
			//	 SetTextColor(hdc, RGB(255, 255, 0));
			//	 DrawText(hdc, szText, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);//����  �о��� ��ֱ����
			//	 
			//HFONT hfont= CreateFont(
			//		 50,          //�ָ߶�
			//		 0,            //�ַ����
			//		 0,            //������б�Ƕ�
			//		 0,           //������б�Ƕ�
			//		 FW_BOLD,      //�ʻ��Ĵ�ϸ
			//		 0,            //�Ƿ���б��
			//		 0,            //�Ƿ���»���
			//		 0,            //�Ƿ��������м�ˮƽ��
			//		 ANSI_CHARSET, //�ַ���
			//		 0,            //���������ʽ
			//		 0,             //�ü�����ķ�ʽ
			//		 0,             //��������
			//		 0,              //����ϵ�к��������趨
			//		 TEXT("����")); //������
			//	 HFONT hOldFont = (HFONT)SelectObject(hdc, hfont);//������ŵ��豸��

			//	 SetTextColor(hdc, RGB(0, 255, 0));
			//	 TextOut(hdc, 0, 400, szText, _tcslen(szText));
			//	
			//	 SelectObject(hdc, hOldFont);//���ϵķŻ�ȥ
			//	 DeleteObject(hfont); //ɾ������������
			//
			//	 for (int m = 0; m < 100; ++m)
			//	 {
			//		 SetPixel(hdc, m, 100, RGB(0, 255, 0)); //�������� һ����

			//	 }
			//����
			DrawLine(hdc, 0, 0, 200, 300, PS_DASHDOT, 0.1, RGB(255, 255, 0)); //1310����
			Arc(hdc, 100, 300, 400, 500, 400, 300, 100, 400);
			////����������һ����Բ����

			//BOOL Arc(

			// HDC ��HDC��,	//�����豸������
			// INT ��nLeftRect��,	//�߽�������Ͻǵ�x����
			// INT ��nTopRect��,	//�߽�������Ͻǵ�y����
			// INT ��nRightRect��,	//�߽�������½ǵ�x����
			// INT ��nBottomRect��,	//�߽�������½ǵ�y����
			// INT ��nXStartArc��,	//��һ�����������
			// INT ��nYStartArc��,	//��һ�����������
			// INT ��nXEndArc��,	//�ڶ������յ�
			// INT ��nYEndArc��	//�ڶ������յ�
			// );
			Chord(hdc, 10, 60, 40, 80, 40, 60, 10, 70);
			Pie(hdc, 10, 90, 40, 110, 40, 90, 10, 100);
			//����
			Rectangle(hdc, 10, 10, 100, 150);
			//��Բ ��Բ
			Ellipse(hdc, 200, 200, 400, 400);

			POINT Pt[7];
			Pt[0].x = 80; Pt[0].y = 250;
			Pt[1].x = 180; Pt[1].y = 250;
			Pt[2].x = 180; Pt[2].y = 220;
			Pt[3].x = 230; Pt[3].y = 270;
			Pt[4].x = 180; Pt[4].y = 320;
			Pt[5].x = 180; Pt[5].y = 290;
			Pt[6].x = 80; Pt[6].y = 290;


			Polyline(hdc, Pt, 7);//�����
			EndPaint(hwnd, &ps);//�ͷ��ڴ�
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
	//����
	static void DrawLine(HDC dc, int x0, int y0, int x1, int y1, int style, int width, COLORREF col)
	{
		HPEN pen = CreatePen(style, width, col);
		HPEN old = (HPEN)SelectObject(dc, pen);

		MoveToEx(dc, x0, y0, NULL);//�����
		LineTo(dc, x1, y1);//���յ�


		SelectObject(dc, old);
		DeleteObject(pen);
	}
protected:
private:

};
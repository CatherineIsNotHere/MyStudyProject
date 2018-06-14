#pragma once//执行一次
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
			hdc = BeginPaint(hwnd, &ps);//开始绘图
			//	  wchar_t szText[64] = TEXT("这是测试汉子 this is test!");
			//	 SetTextColor(hdc, RGB(255, 0, 255)); //文字颜色
			//	 //文字输出 精准定位但不能换行
			//	 SetBkMode(hdc, TRANSPARENT); //去掉背景框
			//	 TextOut(hdc, 100, 200, szText, _tcslen(szText)); //_tcslen 长度 文件头 tchar.h

			//	 RECT rc;//矩形
			//	 GetClientRect(hwnd, &rc); //获取客户区尺寸
			//	 SetTextColor(hdc, RGB(255, 255, 0));
			//	 DrawText(hdc, szText, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);//单行  行居中 垂直居中
			//	 
			//HFONT hfont= CreateFont(
			//		 50,          //字高度
			//		 0,            //字符宽度
			//		 0,            //文字倾斜角度
			//		 0,           //字体倾斜角度
			//		 FW_BOLD,      //笔画的粗细
			//		 0,            //是否是斜体
			//		 0,            //是否加下划线
			//		 0,            //是否在字体中加水平线
			//		 ANSI_CHARSET, //字符集
			//		 0,            //字体输出方式
			//		 0,             //裁剪字体的方式
			//		 0,             //字体质量
			//		 0,              //字体系列和字体宽度设定
			//		 TEXT("仿宋")); //字样名
			//	 HFONT hOldFont = (HFONT)SelectObject(hdc, hfont);//将字体放到设备里

			//	 SetTextColor(hdc, RGB(0, 255, 0));
			//	 TextOut(hdc, 0, 400, szText, _tcslen(szText));
			//	
			//	 SelectObject(hdc, hOldFont);//把老的放回去
			//	 DeleteObject(hfont); //删除创建的字体
			//
			//	 for (int m = 0; m < 100; ++m)
			//	 {
			//		 SetPixel(hdc, m, 100, RGB(0, 255, 0)); //像素设置 一条线

			//	 }
			//画笔
			DrawLine(hdc, 0, 0, 200, 300, PS_DASHDOT, 0.1, RGB(255, 255, 0)); //1310满屏
			Arc(hdc, 100, 300, 400, 500, 400, 300, 100, 400);
			////弧函数绘制一个椭圆弧。

			//BOOL Arc(

			// HDC 【HDC】,	//处理设备上下文
			// INT 【nLeftRect】,	//边界矩形左上角的x坐标
			// INT 【nTopRect】,	//边界矩形左上角的y坐标
			// INT 【nRightRect】,	//边界矩形右下角的x坐标
			// INT 【nBottomRect】,	//边界矩形右下角的y坐标
			// INT 【nXStartArc】,	//第一个径向结束点
			// INT 【nYStartArc】,	//第一个径向结束点
			// INT 【nXEndArc】,	//第二径向终点
			// INT 【nYEndArc】	//第二径向终点
			// );
			Chord(hdc, 10, 60, 40, 80, 40, 60, 10, 70);
			Pie(hdc, 10, 90, 40, 110, 40, 90, 10, 100);
			//矩形
			Rectangle(hdc, 10, 10, 100, 150);
			//椭圆 正圆
			Ellipse(hdc, 200, 200, 400, 400);

			POINT Pt[7];
			Pt[0].x = 80; Pt[0].y = 250;
			Pt[1].x = 180; Pt[1].y = 250;
			Pt[2].x = 180; Pt[2].y = 220;
			Pt[3].x = 230; Pt[3].y = 270;
			Pt[4].x = 180; Pt[4].y = 320;
			Pt[5].x = 180; Pt[5].y = 290;
			Pt[6].x = 80; Pt[6].y = 290;


			Polyline(hdc, Pt, 7);//多段线
			EndPaint(hwnd, &ps);//释放内存
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
	//画笔
	static void DrawLine(HDC dc, int x0, int y0, int x1, int y1, int style, int width, COLORREF col)
	{
		HPEN pen = CreatePen(style, width, col);
		HPEN old = (HPEN)SelectObject(dc, pen);

		MoveToEx(dc, x0, y0, NULL);//笔起点
		LineTo(dc, x1, y1);//笔终点


		SelectObject(dc, old);
		DeleteObject(pen);
	}
protected:
private:

};
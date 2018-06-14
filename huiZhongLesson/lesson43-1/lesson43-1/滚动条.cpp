#include <windows.h>
//#include <commctrl.h>
//#pragma comment(lib,"comctl32")
static TCHAR szAppName[] = TEXT("MyWindow");
LRESULT CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	static int npage = 5;
	static int nmin = 0;
	static int nmax = 19;
	static HWND hscroll; 
	int CurPos=0;
	int n = 0;
	TCHAR s[20];
	switch (msg)
	{
	case WM_CREATE:
		hscroll=CreateWindow(TEXT("SCROLLBAR"),
			NULL,
			WS_CHILD|WS_VISIBLE|SBS_VERT|WS_TABSTOP|SBS_RIGHTALIGN,
			100,100,20,110,
			hwnd, (HMENU)4000, GetModuleHandle(NULL),NULL
			);
		SCROLLINFO si;
		ZeroMemory(&si,sizeof(si));
		si.cbSize = sizeof(si);
		si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
		si.nMin = nmin;
		si.nMax = nmax;
		si.nPage = npage;
		si.nPos = 0;
		SetScrollInfo(hscroll,SB_CTL,&si,TRUE);
		break;
	case WM_VSCROLL:
		CurPos = GetScrollPos(hscroll, SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_TOP:
			CurPos = nmin;
			break;
		case SB_BOTTOM:
			CurPos = nmax;
			break;
		case SB_LINEDOWN:
			if (CurPos < nmax)
				CurPos++;
			break;
		case SB_LINEUP:
			if (CurPos>nmin)
				CurPos--;
			break;
		case SB_THUMBTRACK:
			CurPos = HIWORD(wParam);
			break;
		case SB_PAGEUP:
			CurPos -= npage;
			CurPos = CurPos < 0 ? 0 : CurPos;
			break;
		case SB_PAGEDOWN:
			CurPos += npage;
			CurPos>nmax ? nmax : CurPos;
			break;
		default:
			break;
		}
		SetScrollPos(hscroll,SB_CTL,CurPos,TRUE);
		n=GetScrollPos(hscroll, SB_CTL);
		wsprintf(s,TEXT("%d\n"),n);
		OutputDebugString(s);
		break;
	case WM_SIZE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int iCmdShow){
	WNDCLASSEX wc;
	MSG msg;
	HWND hwnd;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = DlgProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//光标
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//小图标
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("失败"), szAppName, MB_ICONERROR);
		return 0;
	}
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		szAppName,
		TEXT("UPUPOO"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL
		);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}


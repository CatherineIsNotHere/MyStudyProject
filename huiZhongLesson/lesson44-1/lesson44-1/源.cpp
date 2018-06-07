#include <windows.h>
#include <tchar.h>
#include "resource.h"
//#include <commctrl.h>
//#pragma comment(lib,"comctl32")
static TCHAR szAppName[] = TEXT("MyWindow");
void fileDialog(HWND);
void colorDialog(HWND);
void fontDialog(HWND);
LRESULT CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	HINSTANCE inst = GetModuleHandle(NULL);
	static HWND hWndEdit;
	HWND filebutton;
	HWND colorbutton;
	HWND fontbutton;
	int wmId = LOWORD(wParam);
	switch (msg)
	{
	case WM_CREATE:
		filebutton = CreateWindow(TEXT("BUTTON"), TEXT("file dialog"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			30, 100, 150, 50, hwnd, (HMENU)IDC_FILE_DIALOG, inst, NULL
			);
		colorbutton = CreateWindow(TEXT("BUTTON"), TEXT("color dialog"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			30, 160, 150, 50, hwnd, (HMENU)IDC_COLOR_DIALOG, inst, NULL
			);
		fontbutton = CreateWindow(TEXT("BUTTON"), TEXT("font dialog"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			30, 220, 150, 50, hwnd, (HMENU)IDC_FONT_DIALOG, inst, NULL
			);
		break;
	case WM_COMMAND:
		switch (wmId)
		{
		case IDC_FILE_DIALOG:
			fileDialog(hwnd);
			break;
		case IDC_COLOR_DIALOG:
			colorDialog(hwnd);
			break;
		case IDC_FONT_DIALOG:
			fontDialog(hwnd);
			break;
		default:
			break;
		}
	case WM_DROPFILES:

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
	DWORD dwStyleEx = WS_EX_ACCEPTFILES;
	hwnd = CreateWindowEx(
		//WS_EX_CLIENTEDGE,
		dwStyleEx,
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

void fileDialog(HWND hwnd){
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH] = TEXT("default");
	TCHAR szFilter[] = TEXT("文本文件(*.txt)\0*.txt\0")
		TEXT("数据文件(*.dat)\0*.dat\0")TEXT("All Files(*.*)\0*.*\0\0");
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = szFilter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;
	if (GetOpenFileName(&ofn)){//GetSaveFileName
		//GetLastError();
		//将选择的文件输出到窗口
		LPWSTR file = ofn.lpstrFile;
		HDC hDC = GetDC(hwnd);
		TextOut(hDC, 200, 50, ofn.lpstrFile, _tcslen(ofn.lpstrFile));
		ReleaseDC(hwnd, hDC);
	}
}
void colorDialog(HWND hwnd){
	CHOOSECOLOR cc;
	static COLORREF acrCustClr[16];
	ZeroMemory(&cc, sizeof(cc));
	cc.lStructSize = sizeof(cc);
	cc.hwndOwner = hwnd;
	cc.lpCustColors = (LPDWORD)acrCustClr;
	if (ChooseColor(&cc)){
		//用选择的颜色画一个实心矩形
		RECT rect = { 240, 160, 340, 210 };
		HDC hDC = GetDC(hwnd);
		HBRUSH hBrush = CreateSolidBrush(cc.rgbResult);
		SelectObject(hDC, hBrush);
		FillRect(hDC, &rect, hBrush);
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hDC);
	}
}
void fontDialog(HWND hwnd){
	CHOOSEFONT cf;
	LOGFONT lf;
	ZeroMemory(&cf,sizeof(cf));
	cf.lStructSize = sizeof(cf);
	cf.hwndOwner = hwnd;
	cf.lpLogFont = &lf;
	cf.Flags = CF_SCREENFONTS | CF_EFFECTS;
	if (ChooseFont(&cf))
	{
		TCHAR str[] = TEXT("FONT 测试");
		HFONT hFONT = CreateFontIndirect(cf.lpLogFont);
		DWORD rgbCurrent = cf.rgbColors;
		HDC hDC = GetDC(hwnd);
		SelectObject(hDC,hFONT);
		SetTextColor(hDC,cf.rgbColors);
		TextOut(hDC,200,170,str,_tcslen(str));
		DeleteObject(hFONT);
		ReleaseDC(hwnd,hDC);

	}
}
#include <windows.h>
//#include <commctrl.h>
//#pragma comment(lib,"comctl32")
static TCHAR szAppName[] = TEXT("MyWindow");
void HandleFiles(WPARAM wParam);
LRESULT CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	static HWND hWndEdit;
	switch (msg)
	{
	case WM_CREATE:
		hWndEdit = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD|WS_VISIBLE|WS_HSCROLL|WS_VSCROLL|ES_LEFT|ES_MULTILINE|ES_AUTOHSCROLL|ES_AUTOVSCROLL,
			0,0,0,0,
			hwnd,
			0,
			GetModuleHandle(NULL),
			NULL
			);
		break;
	case WM_DROPFILES:
		HandleFiles(wParam);
		break;
	case WM_SIZE:
		MoveWindow(hWndEdit, 0, 0, LOWORD(lParam), HIWORD(lParam), TRUE);
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

void HandleFiles(WPARAM wParam){
	TCHAR szName[MAX_PATH];
	HDROP hDrop = (HDROP)wParam;
	int count = DragQueryFile(hDrop,0xffffffff,szName,MAX_PATH);//拖拽了几个文件
	for (int i = 0; i < count; i++)
	{
		DragQueryFile(hDrop, i, szName, MAX_PATH);
		MessageBox(GetForegroundWindow(),szName,TEXT("Current file received"),MB_OK);
	}
	DragFinish(hDrop);
}
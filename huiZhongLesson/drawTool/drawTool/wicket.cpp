#include "wicket.h"

typedef enum LocationStatusBar
{
	LEFT_STATUSBAR=20
}LSB;

wicket::wicket(HINSTANCE inst)
	:m_hInst(inst)
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = wndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInst;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = TEXT("winApp");
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		RegisterClassEx(&wc);
}
wicket::~wicket(){
	UnregisterClass(TEXT("winApp"), m_hInst);
}

LRESULT CALLBACK wicket::wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	wicket* pthis = (wicket *)GetWindowLong(hwnd, GWLP_USERDATA);
	if (pthis){
		return pthis->onEvent(hwnd, msg, wParam, lParam);
	}
	if (WM_CREATE == msg){
		CREATESTRUCT * pCreate = (CREATESTRUCT*)lParam;
		SetWindowLong(hwnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
	}
	return  DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT wicket::onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	RECT rc;
	switch (msg)
	{
	case WM_PAINT:
		break;
	case WM_MOUSEMOVE:
		printStatusRightBar(m_hStatusBar,lParam);
		break;
	case WM_KEYUP:
		break;
	case WM_KEYDOWN:
		break;
	case WM_SETFOCUS:
		SetWindowText(hwnd, TEXT("winApp"));
		break;
	case WM_KILLFOCUS:
		SetWindowText(hwnd, TEXT("winApp (未响应)"));
		break;
	case WM_CLOSE:
		break;
	case WM_SIZE:
		GetClientRect(m_hWnd, &rc);
		setNWidth(rc.right);
		setNHeight(rc.left);
		setStatusBar(m_hWnd, m_hStatusBar);
		MoveWindow(m_hStatusBar, rc.left, rc.top, rc.right, rc.bottom, 1);
		MoveWindow(m_hToolbar, 0, rc.top, rc.right,0, 1);
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int wicket::Run(int w, int h){
	m_nWidth = w;
	m_nHeight = h;
	m_hWnd = CreateWindowEx(
		NULL, TEXT("winApp"), TEXT("winApp"),
		WS_OVERLAPPEDWINDOW,
		0,0,w, h,NULL,NULL,m_hInst,this);
	if (m_hWnd == 0){
		return -1;
	}
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
	initBars(m_hWnd,m_hStatusBar,m_hToolbar);
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

HWND wicket::initBars(HWND & hwnd,HWND & statusBar,HWND & toolBar){
	createStatusBar(hwnd, statusBar);
	setStatusBar(hwnd, statusBar);
	createToolBar(hwnd, toolBar);
	return hwnd;
}

int wicket::createStatusBar(HWND & hwnd,HWND & statusBar){
	statusBar = CreateWindowEx(0, STATUSCLASSNAME, __TEXT(""), WS_CHILD | WS_VISIBLE,
		0, 0, 0, 0,
		hwnd, NULL,
		GetModuleHandle(NULL), NULL);//bar
	return 1;
}

int wicket::setStatusBar(HWND hwnd, HWND statusBar){
	int Rightend[3];
	RECT WinRect;
	GetClientRect(hwnd, &WinRect);
	int right=WinRect.right;
	Rightend[0] = WinRect.right / 2;
	Rightend[1] = WinRect.right - LEFT_STATUSBAR*8;
	Rightend[2] = WinRect.right;
	SendMessage(statusBar, SB_SETPARTS, (WPARAM)3, (LPARAM)Rightend);
	return 1;
}

int wicket::printStatusRightBar(HWND statusBar, LPARAM lParam){
	TCHAR charxy[LEFT_STATUSBAR] = { 0 };
	wsprintf(charxy, TEXT("x:%d,y:%d"), LOWORD(lParam), HIWORD(lParam));
	SendMessage(statusBar, SB_SETTEXT, (WPARAM)2, (LPARAM)charxy);
	return 1;
}

int wicket::createToolBar(HWND & hwnd, HWND & toolbar){
	INITCOMMONCONTROLSEX InitCtrlEx;
	InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
	InitCtrlEx.dwICC = ICC_BAR_CLASSES;
	InitCommonControlsEx(&InitCtrlEx);

	TBBUTTON tbrButtons[4];
	tbrButtons[0].iBitmap = 0;//按钮在图片资源中的索引，以0开始
	tbrButtons[0].idCommand = ID_BUTTON201;//按钮对应命令ID，一般和菜单命令对应
	tbrButtons[0].fsState = TBSTATE_ENABLED;//按钮类型
	tbrButtons[0].fsStyle = TBSTYLE_BUTTON;//按钮样式
	tbrButtons[0].dwData = 0L;//自定义数据
	tbrButtons[0].iString = 0;//按钮字符串索引

	tbrButtons[1].iBitmap = 1;
	tbrButtons[1].idCommand = ID_BUTTON202;
	tbrButtons[1].fsState = TBSTATE_ENABLED;
	tbrButtons[1].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[1].dwData = 0L;
	tbrButtons[1].iString = 0;

	tbrButtons[2].iBitmap = 0;
	tbrButtons[2].idCommand = 0;
	tbrButtons[2].fsState = TBSTATE_ENABLED;
	tbrButtons[2].fsStyle = TBSTYLE_SEP;//这个是空隙
	tbrButtons[2].dwData = 0L;
	tbrButtons[2].iString = 0;

	tbrButtons[3].iBitmap = 1;
	tbrButtons[3].idCommand = ID_BUTTON203;
	tbrButtons[3].fsState = TBSTATE_ENABLED;
	tbrButtons[3].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[3].dwData = 0L;
	tbrButtons[3].iString = 0;

	toolbar = CreateToolbarEx(
		hwnd, WS_VISIBLE | WS_CHILD | WS_BORDER,//样式
		IDR_TOOLBAR1,//工具栏ID
		4,//按钮个数
		GetModuleHandle(NULL),
		IDR_TOOLBAR1,//自定义图片的资源ID
		tbrButtons,//按钮结构数组地址
		4, 0, 0, 16, 16, sizeof(TBBUTTON)//图片大小，按钮结构size
		);

	return 1;
}

/*
	GET AND SET
*/

HINSTANCE wicket::getHInst(){
	return m_hInst;
}
HWND wicket::getHWnd(){
	return m_hWnd;
}
int wicket::getNWidth(){
	return m_nWidth;
}
int wicket::getNHeight(){
	return m_nHeight;
}
HWND wicket::getHStatusBar(){
	return m_hStatusBar;
}
void wicket::setHInst(HINSTANCE hInstance){
	this->m_hInst = hInstance;
}
void wicket::setHWnd(HWND hwnd){
	this->m_hWnd = hwnd;
}
void wicket::setNWidth(int width){
	this->m_nWidth = width;
}
void wicket::setNHeight(int height){
	this->m_nHeight = height;
}
void wicket::setHStatusBar(HWND statusBar){
	this->m_hStatusBar = statusBar;
}
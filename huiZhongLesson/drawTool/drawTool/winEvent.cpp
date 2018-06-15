#include "winEvent.h"


winEvent::winEvent(HINSTANCE e_inst, WNDCLASSEX* wc)
:winIni(e_inst, wc)
{
			wc->lpfnWndProc = wndProc;
			RegisterClassEx(wc);
}

winEvent::~winEvent(){
}

LRESULT CALLBACK winEvent::wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	winEvent* pthis = (winEvent *)GetWindowLong(hwnd, GWLP_USERDATA);
	if (pthis){
		return pthis->onEvent(hwnd, msg, wParam, lParam);
	}
	if (WM_CREATE == msg){
		CREATESTRUCT * pCreate = (CREATESTRUCT*)lParam;
		SetWindowLong(hwnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
	}
	return  DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT winEvent::onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	//RECT rc;
	switch (msg)
	{
	case WM_PAINT:
		break;
	case WM_MOUSEMOVE:
		printStatusRightBar(getHStatusBar(), lParam);
		break;
	case WM_KEYUP:
		break;
	case WM_KEYDOWN:

		break;
	case WM_SETFOCUS:
		SetWindowText(hwnd, TEXT("winApp"));
		break;
	case WM_KILLFOCUS:
		SetWindowText(hwnd, TEXT("winApp (Œ¥œÏ”¶)"));
		break;
	case WM_CLOSE:
		break;
	case WM_SIZE:
		//GetClientRect(getHWnd(), &rc);
		/*setNWidth(rc.right);
		setNHeight(rc.left);*/
		setNWidth(LOWORD(lParam));
		setNHeight(HIWORD(lParam));
		printStatusBar(getHWnd(), getHStatusBar());
		MoveWindow(getHStatusBar(), NULL, NULL, NULL, NULL, 1);
		MoveWindow(getHToolBar(), NULL, NULL, NULL, NULL, 1);
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int winEvent::printStatusBar(HWND hwnd, HWND statusBar){
	int Rightend[3];
	RECT WinRect;
	GetClientRect(hwnd, &WinRect);
	int right = WinRect.right;
	Rightend[0] = WinRect.right / 2;
	Rightend[1] = WinRect.right - LEFT_STATUSBAR * 8;
	Rightend[2] = WinRect.right;
	SendMessage(statusBar, SB_SETPARTS, (WPARAM)3, (LPARAM)Rightend);
	return 1;
}

int winEvent::printStatusRightBar(HWND statusBar, LPARAM lParam){
	TCHAR charxy[LEFT_STATUSBAR] = { 0 };
	wsprintf(charxy, TEXT("x:%d,y:%d"), LOWORD(lParam), HIWORD(lParam)-29);
	SendMessage(statusBar, SB_SETTEXT, (WPARAM)2, (LPARAM)charxy);
	return 1;
}
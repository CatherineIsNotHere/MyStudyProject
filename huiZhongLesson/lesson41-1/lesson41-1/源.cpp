#include <windows.h>
#include "resource.h"

//LPCWSTR Caption = __TEXT("Application Programing Interface");
LRESULT CALLBACK DlgProc(HWND hWndDlg,UINT msg,WPARAM wParam,LPARAM lParam){
	return FALSE;
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	/*
	MessageBox(NULL, __TEXT("未连接到互联网\n请试试以下办法：\n检查网线、调制解调器和路由器\n重新连接到 Wi - Fi 网络\n运行 Windows 网络诊断\nDNS_PROBE_FINISHED_NO_INTERNET"), Caption, MB_YESNOCANCEL|MB_ICONQUESTION);
	*/
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, (DLGPROC)DlgProc);
	return 0;
}
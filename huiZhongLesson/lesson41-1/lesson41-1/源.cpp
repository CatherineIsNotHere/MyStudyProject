#include <windows.h>
#include "resource.h"

//LPCWSTR Caption = __TEXT("Application Programing Interface");
LRESULT CALLBACK DlgProc(HWND hWndDlg, UINT msg, WPARAM wParam, LPARAM lParam){
	HINSTANCE inst = GetModuleHandle(NULL);
	static HWND hstatic;
	static HWND hbutton;
	static HWND hedit;
	HWND h;
	HWND hh;
	HWND hhh;
	wchar_t s[512] = {};
	switch (msg)
	{
	case WM_INITDIALOG:
		//静态文本
		hstatic=CreateWindow(TEXT("static"), TEXT("hellow world"),
			WS_CHILD|WS_VISIBLE|WS_BORDER,
			30, 20, 150, 80, hWndDlg, (HMENU)500,inst,NULL
			);
		//按钮
		hbutton = CreateWindow(TEXT("button"), TEXT("hellow world"),
			WS_CHILD | WS_VISIBLE | WS_BORDER|BS_FLAT,
			30, 100, 150, 50, hWndDlg, (HMENU)100, inst, NULL
			);
		//文本单选框
		hedit = CreateWindow(TEXT("edit"), TEXT("这是文本框的内容"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			30, 150, 150, 50, hWndDlg, (HMENU)200, inst, NULL
			);
		CreateWindow(TEXT("button"), TEXT("男"),
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
			200, 20, 60, 20, hWndDlg, (HMENU)150, inst, NULL);
		CreateWindow(TEXT("button"), TEXT("女"),
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON ,
			200, 40, 60, 20, hWndDlg, (HMENU)160, inst, NULL);
		h=CreateWindow(TEXT("button"), TEXT("女装大佬"),
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON ,
			200, 60, 80, 20, hWndDlg, (HMENU)170, inst, NULL);
		SendMessage(h,BM_SETCHECK,BST_CHECKED,0);

		//文本多选框
		CreateWindow(TEXT("button"), TEXT("狗"),
			WS_CHILD | WS_VISIBLE | BS_LEFT|BS_AUTOCHECKBOX,
			200, 100, 60, 20, hWndDlg, (HMENU)210, inst, NULL);
		CreateWindow(TEXT("button"), TEXT("猫"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTOCHECKBOX,
			200, 120, 60, 20, hWndDlg, (HMENU)220, inst, NULL);
		hhh=CreateWindow(TEXT("button"), TEXT("鱼"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTOCHECKBOX,
			200, 140, 60, 20, hWndDlg, (HMENU)230, inst, NULL);
		hh=CreateWindow(TEXT("button"), TEXT("大象"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTOCHECKBOX,
			200, 160, 60, 20, hWndDlg, (HMENU)240, inst, NULL);
		SendMessage(hh,BM_SETCHECK,BST_CHECKED,0);
		SendMessage(hhh, BM_SETCHECK, BST_CHECKED, 0);

		//CreateWindow(TEXT("static"), TEXT("这是边框"),
		//	WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
		//	10, 200, 200, 300,
		//	hWndDlg, (HMENU)1000, inst, NULL
		//	);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
			if (IsDlgButtonChecked(hWndDlg, 150) == BST_CHECKED){
				MessageBox(0,TEXT("男人"),TEXT("你是"),0);
			}
			else if (IsDlgButtonChecked(hWndDlg, 160) == BST_CHECKED){
				MessageBox(0, TEXT("女人"), TEXT("你是"), 0);
			}
			else if (IsDlgButtonChecked(hWndDlg, 170) == BST_CHECKED){
				MessageBox(0, TEXT("女装大佬"), TEXT("你是"), 0);
			}
			if (IsDlgButtonChecked(hWndDlg, 210)==BST_CHECKED){
				OutputDebugString(TEXT("选中了狗"));
			}
			if (IsDlgButtonChecked(hWndDlg, 220) == BST_CHECKED){
				OutputDebugString(TEXT("选中了猫"));
			}
			if (IsDlgButtonChecked(hWndDlg, 230) == BST_CHECKED){
				OutputDebugString(TEXT("选中了鱼"));
			}
			if (IsDlgButtonChecked(hWndDlg, 240) == BST_CHECKED){
				OutputDebugString(TEXT("选中了大象"));
			}
			
			//EndDialog(hWndDlg, 0);
			break;
		case 100:
			GetDlgItemText(hWndDlg,500,s,512);
			SetDlgItemText(hWndDlg,200,s);
			break;
		case IDCANCEL:
			EndDialog(hWndDlg, 0);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return FALSE;
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	/*
	MessageBox(NULL, __TEXT("未连接到互联网\n请试试以下办法：\n检查网线、调制解调器和路由器\n重新连接到 Wi - Fi 网络\n运行 Windows 网络诊断\nDNS_PROBE_FINISHED_NO_INTERNET"), Caption, MB_YESNOCANCEL|MB_ICONQUESTION);
	*/
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, (DLGPROC)DlgProc);
	return 0;
}
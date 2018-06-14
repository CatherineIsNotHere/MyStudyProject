#include <windows.h>
#include <windowsx.h>
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
	HINSTANCE hinst = GetModuleHandle(NULL);
	static HWND hListBox;
	static HWND hCombo;
	int iSelectedIndex;
	TCHAR strSelectedItem[32];
	TCHAR szMessage[32];
	auto uCount=0;
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
		//下拉列表框
		CreateWindow(TEXT("BUTTON"), TEXT("FRAME"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 300, 5, 101, 115, hWndDlg, (HMENU)5000, hinst, NULL);
		hListBox = CreateWindow(TEXT("LISTBOX"),
			NULL,WS_CHILD|WS_VSCROLL|WS_TABSTOP|LBS_STANDARD,
			300,25,100,100,
			hWndDlg, (HMENU)4000,
			hinst,NULL
			);
		ShowWindow(hListBox,SW_SHOW);
		ListBox_AddString(hListBox,TEXT("father"));
		ListBox_AddString(hListBox, TEXT("mother"));
		//SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"Father");
		//SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"Mother");
		SendMessage(hListBox,LB_ADDSTRING,0,(LPARAM)(TEXT("Daughter")));
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)(TEXT("Son")));
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)(TEXT("Bother")));
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)(TEXT("Sister")));

		//组合框
		hCombo = CreateWindowEx(0, TEXT("COMBOBOX"), TEXT("Simple"),WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|WS_VSCROLL,
			30,200,150,80,
			hWndDlg,(HMENU)1001,hinst,NULL
			);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)(TEXT("1")));
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)(TEXT("3")));
		SendMessage(hCombo, CB_INSERTSTRING, 1, (LPARAM)(TEXT("2")));
		SendMessage(hCombo, CB_SETCURSEL, 2, 0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			//SendMessage(hCombo,CB_DELETESTRING,0,0);//删除第几个数据
			//SendMessage(hCombo,CB_RESETCONTENT,0,0);//清楚combobox所有数据
			//uCount = SendMessage(hCombo,CB_GETCOUNT,0,0);
			SendMessage(hCombo, CB_GETLBTEXT, 1, (LPARAM)szMessage);
			MessageBox(0, szMessage, TEXT("获取第二项的数据"), 0);
			/*if (IsDlgButtonChecked(hWndDlg, 150) == BST_CHECKED){
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
			}*/
			//EndDialog(hWndDlg, 0);
			break;
		case 4000:
			switch (HIWORD(wParam))
			{
			case LBN_DBLCLK:
				iSelectedIndex = ListBox_GetCurSel(hListBox);
				ListBox_GetText(hListBox, iSelectedIndex, (LPCTSTR)strSelectedItem);
				MessageBox(NULL, strSelectedItem, TEXT("Exercise"), 33);
				ListBox_DeleteString(hListBox, iSelectedIndex);
				break;
			default:
				break;
			}
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
#include <windows.h>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")

class wicket{
public:
	wicket(HINSTANCE inst);
	virtual ~wicket();
	HINSTANCE getHInst();
	HWND getHWnd();
	int getNWidth();
	int getNHeight();
	void setHInst(HINSTANCE hInstance);
	void setHWnd(HWND hwnd);
	void setNWidth(int width);
	void setNHeight(int height);
	static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	int Run(int w, int h);
	/*
	���ƣ�MakeStatusBar
	���ܣ�����״̬��
	������HWND
	*/
	static HWND createStatusBar(HWND hwnd);

	/*
	���ƣ�setStatus
	���ܣ���״̬�����ֳɶ��
	������hwnd�����ھ����hstatus״̬�����
	*/
	static HWND setStatusBar(HWND hwnd, HWND hstatus);

	/*
	���ƣ�setStatusText
	���ܣ�����״̬��ĳһ��ı���
	������hStatus״̬�������i��i��txt����
	*/
	int setStatusText(HWND hStatus, int i, TCHAR* txt);
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	int m_nWidth;
	int m_nHeight;
};
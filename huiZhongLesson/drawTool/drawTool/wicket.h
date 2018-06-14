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
	名称：MakeStatusBar
	功能：创建状态栏
	参数：HWND
	*/
	static HWND createStatusBar(HWND hwnd);

	/*
	名称：setStatus
	功能：将状态栏划分成多格
	参数：hwnd主窗口句柄，hstatus状态栏句柄
	*/
	static HWND setStatusBar(HWND hwnd, HWND hstatus);

	/*
	名称：setStatusText
	功能：设置状态栏某一格的标题
	参数：hStatus状态栏句柄，i第i格，txt标题
	*/
	int setStatusText(HWND hStatus, int i, TCHAR* txt);
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	int m_nWidth;
	int m_nHeight;
};
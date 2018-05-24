#include <windows.h>
//#include <tchar.h>
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdshow)
{
	MessageBox(NULL, __TEXT("HELLO WIN32"), __TEXT("windows program"), MB_OK);
	return 0;
}

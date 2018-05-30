#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow) {
	MessageBox(NULL,TEXT("HELLO WORLD!"), TEXT("HELLOMsg"),MB_APPLMODAL);
	return 0;
}
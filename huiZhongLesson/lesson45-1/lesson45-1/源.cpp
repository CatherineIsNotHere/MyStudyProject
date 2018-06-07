#include <windows.h>
#include "WinApp.hpp"

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
	CWinApp app(hInstance);
	app.Run(800, 600);
}
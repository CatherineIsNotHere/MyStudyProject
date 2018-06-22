#include <windows.h>
#include "WinApp3.hpp"

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
	CWinAPP app(hInstance);
	app.run(800, 600);
}
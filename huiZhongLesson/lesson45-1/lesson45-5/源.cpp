#include <windows.h>

#include "��ͷ.hpp"

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
	CWinAPP app(hInstance);
	app.run(800, 600);
}
#include "winEvent.h"

INT wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine,int nCmdShow){
	WNDCLASSEX wc;
	winIni * baseWin = new winEvent(hInstance, &wc);
	baseWin->Run(800, 600);
}
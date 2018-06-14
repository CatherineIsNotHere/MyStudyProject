#include "wicket.h"

INT wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine,int nCmdShow){
	wicket baseWicket(hInstance);
	baseWicket.Run(800,600);

}
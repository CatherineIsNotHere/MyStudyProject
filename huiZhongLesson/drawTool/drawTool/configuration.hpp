#pragma once;
#include <windows.h>

typedef enum LocationStatusBar
{
	LEFT_STATUSBAR = 20
}LSB;


static void wndCreateConfig(WNDCLASSEX* wc){
	wc->cbSize = sizeof(WNDCLASSEX);
	wc->style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc->cbClsExtra = 0;
	wc->cbWndExtra = 0;
	wc->hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc->hCursor = LoadCursor(NULL, IDC_ARROW);
	wc->hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc->lpszMenuName = NULL;
	wc->lpszClassName = TEXT("winApp");
	wc->hIconSm = LoadIcon(NULL, IDI_APPLICATION);
}
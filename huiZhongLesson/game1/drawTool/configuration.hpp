#pragma once;
#include <windows.h>
#include <string>
using namespace std;

#define E_ENERMY TEXT(".\\enermy1.bmp")
#define E_MAP1 TEXT("bg1_0.bmp")
#define E_PLAYER1 TEXT(".\\player1.bmp")

typedef enum LocationStatusBar
{
	LEFT_STATUSBAR = 20
}LSB;

typedef enum OBJSTATE{
	COMMON = 0
}OBJSTATE;

/*
	比例
*/
typedef struct  
{
	float w;
	float h;
}SCALE;

/*
	创建窗口类
*/
static void wndCreateConfig(WNDCLASSEX* wc){
	wc->cbSize = sizeof(WNDCLASSEX);
	wc->style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc->cbClsExtra = 0;
	wc->cbWndExtra = 0;
	wc->hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc->hCursor = LoadCursor(NULL, IDC_ARROW);
	wc->hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc->lpszMenuName = NULL;
	wc->lpszClassName = TEXT("窗口");
	wc->hIconSm = LoadIcon(NULL, IDI_APPLICATION);
}
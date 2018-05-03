#include "sysTools.h"


void HideCursor()//去掉光标闪烁
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


void gotoxy(unsigned char x, unsigned char y)//移动光标
{
	COORD cor;
	HANDLE hout;
	cor.X = x;
	cor.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, cor);
}
#include "sysTools.h"
#include "typeGameEnum.h"


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

void gotoxy(unsigned char x, unsigned char y, string str)//移动光标并打印
{
	gotoxy(x, y);
	cout << str;
}

void gotoxy(unsigned char x, unsigned char y, string str, int num){
	
	COORD cor;
	HANDLE hout;
	cor.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (num!=-1){
		for (int i = 0; i < num; i++)
		{
			cor.X = x+i;
			SetConsoleCursorPosition(hout, cor);
			cout << str;
			//gotoxy(x + i, y, str);
		}
	}
	else{
		cor.X = x;
		SetConsoleCursorPosition(hout, cor);
		cout << str;
		//gotoxy(x, y, str);
	}
}
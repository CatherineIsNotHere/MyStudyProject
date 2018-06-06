#pragma once;//编译一次
#include "allSysInclude.h"


void HideCursor();//去掉光标闪烁

void gotoxy(unsigned char x, unsigned char y);//移动光标
void gotoxy(unsigned char x, unsigned char y, string str);//移动光标并打印

void gotoxy(unsigned char x, unsigned char y, string str, int num);
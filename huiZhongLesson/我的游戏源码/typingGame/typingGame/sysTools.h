#pragma once;//����һ��
#include "allSysInclude.h"


void HideCursor();//ȥ�������˸

void gotoxy(unsigned char x, unsigned char y);//�ƶ����
void gotoxy(unsigned char x, unsigned char y, string str);//�ƶ���겢��ӡ

void gotoxy(unsigned char x, unsigned char y, string str, int num);
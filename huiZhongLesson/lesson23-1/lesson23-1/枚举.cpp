#include <stdio.h>

enum MYCOLOR
{
	MC_RED,
	MC_YELLOW,
	MC_BLUE,
	MC_GREEN,
};

void printColor(MYCOLOR col){
	switch (col)
	{
	case MC_RED:
		printf("��ɫ��\n");
		break;
	case MC_YELLOW:
		printf("��ɫ��\n");
		break;
	case MC_BLUE:
		printf("��ɫ��\n");
		break;
	case MC_GREEN:
		printf("��ɫ��\n");
		break;
	default:
		break;
	}
}

void main(){
	MYCOLOR col = MC_RED;
	printColor(col);
}
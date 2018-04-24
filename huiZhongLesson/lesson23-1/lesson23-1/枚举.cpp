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
		printf("红色的\n");
		break;
	case MC_YELLOW:
		printf("黄色的\n");
		break;
	case MC_BLUE:
		printf("蓝色的\n");
		break;
	case MC_GREEN:
		printf("绿色的\n");
		break;
	default:
		break;
	}
}

void main(){
	MYCOLOR col = MC_RED;
	printColor(col);
}
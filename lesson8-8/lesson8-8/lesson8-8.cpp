#include "stdio.h"

/*
	输入年饭判断是否为闰年
	*/
void main(){
	int year = 0;
	printf("请输入一年：");
	scanf_s("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("该年为闰年！");
	else
		printf("该年不是闰年！");
}
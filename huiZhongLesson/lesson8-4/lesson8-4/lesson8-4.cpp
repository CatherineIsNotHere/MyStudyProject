#include "stdio.h"

/*
	输入一个长方形的长和宽，球周长和面积
*/
void main(){
	float a = 0;
	float b = 0;
	float peremeter = 0;
	float acreage = 0;
	printf("请输入一个数的长：");
	scanf_s("%f", &a);
	printf("请输入一个数的宽：");
	scanf_s("%f", &b);
	peremeter = 2 * a + 2 * b;
	acreage = a*b;
	printf("该图形的周长为:%.3f\n", peremeter);
	printf("该图形的面积为:%.3f\n", acreage);
}
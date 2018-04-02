#include "stdio.h"

/*
	输入两个数，输出较小的值
*/
void main(){
	float a = 0;
	float b = 0;
	float t = 0;
	printf("请输入两个数a,b:");
	scanf_s("%f%f",&a,&b);
	if (a>b){
		t = a;
		a = b;
		b = t;
	}
	printf("较小的值为：%.3f",a);
}
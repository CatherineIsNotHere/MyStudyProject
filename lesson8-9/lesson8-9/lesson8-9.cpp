#include "stdio.h"

/*
判断输入的正整数是否既是5又是7的整倍数
*/

void main(){
	int a = 0;
	printf("请输入一个正整数:");
	scanf_s("%d", &a);
	if (a % 5 == 0 && a % 7 == 0)
		printf("是5和7的整倍数");
	else
		printf("不是5和7的整倍数");

}
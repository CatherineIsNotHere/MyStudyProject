#include "stdio.h";

void main(){
	int a = 0;
	int b = 0;
	printf("请输入两个数：  ");
	scanf_s("%d%d", &a, &b);
	//条件判断
	if (a < b)
		printf("第一个小\n");
	else if (a>b)
		printf("第二个小\n");
	else
		printf("俩一样大");
}
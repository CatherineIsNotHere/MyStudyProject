#include "stdio.h"

void main(){
	int a = 0;
	int sum = 0;
	do{
		printf("请输入求和数：");
		scanf_s("%d",&a);
		sum += a;
		printf("和为：%d\n",sum);
	} while (true);
}
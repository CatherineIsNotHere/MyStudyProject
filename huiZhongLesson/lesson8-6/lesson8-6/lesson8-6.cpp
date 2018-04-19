#include "stdio.h"

/*
	输入一个不多于5位的正整数，输出该正整数是几位
*/
void main(){
	int a = 0;
	int wei = 0;
	printf("请输入一个不多于5位的正整数：");
	scanf_s("%d",&a);
	for (int i = 10000; i >= 1; i/=10)
	{
		if (a/i>=1){
			wei++;
		}
	}
	printf("该正整数位数为：%d",wei);
}
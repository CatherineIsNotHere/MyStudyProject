#include "stdio.h"

/*
	输入一个实数，输出绝对值
*/
void main(){
	int a = 0;
	int absolute = 0;//绝对值
	printf("请输入一个实数：");
	scanf_s("%d",&a);
	if (a<0){
		absolute = a*-1;
	}
	else{
		absolute = a;
	}
	printf("该数的绝对值为：%d",absolute);
}
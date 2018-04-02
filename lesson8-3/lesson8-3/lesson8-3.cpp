#include "stdio.h"

/*
	输入一个大写字符，将他转为小写输出
*/
void main(){
	char a = 0;
	printf("请输入一个大写字符：");
	scanf_s("%c",&a,3);
	printf("小写为：%c",a+32);
}
#include "stdio.h"

/*
	输入一个字符，然后按照字符和整数两种形式输出
*/
void main(){
	char a = 0;
	printf("请输入一个字符：");
	scanf_s("%c",&a,3);
	printf("字符为:%c",a);
	printf("整数为:%d",a);
	getchar();
}
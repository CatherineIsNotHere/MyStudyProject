#include "stdio.h"
/*
%c 一个单一的字符
%d 一个十进制整数
%i 一个整数
%e, %f, %g 一个浮点数
%o 一个八进制数
%s 一个字符串
%x 一个十六进制数
%p 一个指针
%n 一个等于读取字符数量的整数
%u 一个无符号整数
%[] 一个字符集
%% 一个精度符号
*/
void main(){
	int a;
	int b;
	printf("请输入两个整数");
	scanf_s("%d %d",&a,&b);
	int c1 = a + b;
	int c2 = a - b;
	int c3 = a*b;
	int c4 = a / b;
	printf("a+b为%d\n", c1);
	printf("a-b为%d\n", c2);
	printf("a*b为%d\n", c3);
	printf("a/b为%d\n", c4);

	printf("请输入两个指针");
	scanf_s("%p %p", &a, &b);
	printf("指针a为%p\n", a);
	printf("指针b为%p\n", b);


}
#include "stdio.h"
#include "stdlib.h"


int ADD(int a, int b, char d){
	int c = 0;
	switch (d)
	{
	case '+':
		c = a + b;
		break;
	case '-':
		c = a - b;
		break;
	case '*':
		c = a * b;
		break;
	case '/':
		c = a / b;
		break;
	case '%':
		c = a % b;
		break;
	default:
		break;
	}

	return c;
}

void main(){
	int fi = 0;
	int se = 0;
	char dd = 0;
	printf("请输入两个数：");
	scanf_s("%d%d", &fi, &se);
	getchar();
	printf("请输入运算符：");
	scanf_s("%c", &dd,4);
	int c = ADD(fi, se, dd);
	printf("%d",c);

	system("pause");
}
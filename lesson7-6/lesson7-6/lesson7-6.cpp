#include "stdio.h"

void main(){
	int a = 0;
	int b = 0;
	char fh;
	int calc;
	printf("��������㹫ʽ��+-*/%%����");
	scanf_s("%d%c%d", &a, &fh, 32, &b);
	switch (fh)
	{
	case '+':
		calc = a + b;
		break;
	case '-':
		calc = a - b;
		break;
	case '*':
		calc = a * b;
		break;
	case '/':
		calc = a / b;
		break;
	case '%':
		calc = a % b;
		break;
	default:
		printf("�������");
		break;
	}
	printf("%d%c%d=%d\n",a,fh,b,calc);
}
#include "stdio.h"

void main(){
	//��ֵ����
	int a = 10;
	printf("%d",a);
	int b = 20;
	printf("%d", b);
	int c;
	c = b;
	printf("a��ֵΪ%d��b��ֵΪ%d\n", a,b);
	printf("����c��ֵΪ %d\n", c);
	//������ѧ����
	c = a - b;
	printf("c=a-bʱcΪ%d\n", c);
	c = a + b;
	printf("c=a+bʱcΪ%d\n", c);
	c = a * b;
	printf("c=a*bʱcΪ%d\n", c);
	c = a / b;
	printf("c=a/bʱcΪ%d\n", c);
	c = a % b;
	printf("c=a%%bʱcΪ%d\n", c);

}
#include "stdio.h"

void main(){
	//赋值操作
	int a = 10;
	printf("%d",a);
	int b = 20;
	printf("%d", b);
	int c;
	c = b;
	printf("a的值为%d，b的值为%d\n", a,b);
	printf("给予c赋值为 %d\n", c);
	//变量数学操作
	c = a - b;
	printf("c=a-b时c为%d\n", c);
	c = a + b;
	printf("c=a+b时c为%d\n", c);
	c = a * b;
	printf("c=a*b时c为%d\n", c);
	c = a / b;
	printf("c=a/b时c为%d\n", c);
	c = a % b;
	printf("c=a%%b时c为%d\n", c);

}
#include "stdio.h"

void main(){
	int a = 10;
	a += 20;//a=a+20;
	int b = a + 10;
	b += a;
	printf("b的值为%d\n", b);
	printf("a的值为%d\n", a);

	int c = 5;
	float d = float(a-c) / float(a+c);
	printf("%f", d);
	getchar();

	float e = 2;
	float f = 2;
	float g=e++;
	float h = ++f;
	printf("e的值为%f",e);
	printf("f的值为%f", f);
	printf("g的值为%f", g);
	printf("h的值为%f", h);

}
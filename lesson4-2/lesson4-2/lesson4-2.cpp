#include "stdio.h"

void main(){
	int a = 10;
	a += 20;//a=a+20;
	int b = a + 10;
	b += a;
	printf("b��ֵΪ%d\n", b);
	printf("a��ֵΪ%d\n", a);

	int c = 5;
	float d = float(a-c) / float(a+c);
	printf("%f", d);
	getchar();

	float e = 2;
	float f = 2;
	float g=e++;
	float h = ++f;
	printf("e��ֵΪ%f",e);
	printf("f��ֵΪ%f", f);
	printf("g��ֵΪ%f", g);
	printf("h��ֵΪ%f", h);

}
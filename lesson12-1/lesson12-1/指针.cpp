#include "stdio.h"
#include "stdlib.h"

void main(){
	int a = 9;
	int* pa = nullptr;
	pa = &a;
	int b = 3;
	pa = &b;
	*pa = 100;
	int c = sizeof(pa);
	int d = sizeof(int*);
	int e = sizeof(double*);
	int f = sizeof(float*);
	int g = sizeof(short*);
	int h = sizeof(_int64*);
	int i = sizeof(bool*);
	int j = sizeof(long*);
	system("pause");
}
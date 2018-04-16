#include "stdio.h"
#include "stdlib.h"

void swap(int* a,int* b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void swap(float* a, float* b){
	float c;
	c = *a;
	*a = *b;
	*b = c;
}


void main(){
	int a = 10;
	int b = 20;
	swap(&a,&b);
	int c = 11.11;
	int d = 22.22;
	swap(&c,&d);
	system("pause");
}
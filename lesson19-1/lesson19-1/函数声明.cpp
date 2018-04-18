#include "stdio.h"
#include "Í·ÎÄ¼þÁ·Ï°.h"
void f2();


extern int g;
int j = 20;
void f1(){
	printf("F1\n");
	f2();
}

void f2(){
	printf("F2\n");
}

void main(){
	f1();
	Myprint();
	printf("%d",g);
}
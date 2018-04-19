#include "stdio.h"

void swap(int* a,int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void MyPrint(char* p,int s=1){
	for (int m = 0; m < s; m++)
	{
		printf("%s",p);
	}
}

void main(){
	int a = 10;
	int b = 20;
	swap(&a, &b);
	printf("%d,%d",a,b);

	char* p = "helloworld";
	p = "³ö²î";
	MyPrint(p);
}

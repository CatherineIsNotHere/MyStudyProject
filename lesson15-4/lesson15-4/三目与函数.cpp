#include "stdio.h"

int sort(int a, int b, int c){
	return (a > b ? a : b)>c ? (a > b ? a : b):c;
}


void main(){
	int a=0, b=0, c=0;
	printf("输入三个数：");
	scanf_s("%d%d%d",&a,&b,&c);
	printf("%d", sort(a, b, c));
}
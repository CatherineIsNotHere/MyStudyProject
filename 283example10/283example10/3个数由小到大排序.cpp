#include "stdio.h"

//从小到大排序
void main(){
	int a, b, c, t;
	printf("please input a,b,c");
	scanf_s("%d%d%d",&a,&b,&c);
	if (a>b){
		t = a;
		a = b;
		b = t;
	}
	if (a>c){
		t = a;
		a = c;
		c = t;
	}
	if (b>c){
		t = b;
		b = c;
		c = t;
	}
	printf("the order of the number is :\n");
	printf("%d,%d,%d",a,b,c);
}
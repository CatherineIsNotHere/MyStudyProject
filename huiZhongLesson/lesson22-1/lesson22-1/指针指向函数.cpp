#include <stdio.h>
#include <stdlib.h>

int GetMax(int a,int b){
	return a > b ? a : b;
}

int GetMin(int a, int b){
	return a < b ? a : b;
}

int(*PFUN)(int, int) = &GetMax;

void main(){
	int a = PFUN(10,20);
	printf("%x\n", PFUN);
	PFUN = &GetMin;
	a = PFUN(10, 20);
	printf("%x\n",PFUN);
	system("pause");
}
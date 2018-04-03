#include "stdio.h"

void main(){
	int a[] = {123,2,3,321,322222};
	int c = sizeof(a) / sizeof(a[0]);
	printf("char %d\n",sizeof(char));
	printf("unsigned char %d\n", sizeof(unsigned char));
	printf("short %d\n", sizeof(short));
	printf("unsigned short %d\n", sizeof(unsigned short)); 
	printf("int %d\n", sizeof(int));
	printf("unsigned int %d\n", sizeof(unsigned int));
	printf("__int64 %d\n", sizeof(__int64));
	printf("unsigned __int64 %d\n", sizeof(unsigned __int64));
	printf("float %d\n", sizeof(float));
	printf("double %d\n", sizeof(double));
	printf("bool %d\n", sizeof(bool));
	printf("%d\n",c);
}
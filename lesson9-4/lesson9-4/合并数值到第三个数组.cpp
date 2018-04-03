#include "stdio.h"

//合并两个数组到第三个数组

void main(){
	int a[5] = {1,2,3,4,5};
	int a1[5] = { 5, 4, 3, 2, 1 };
	int b[sizeof(a)+sizeof(a1)];
	for (int i = 0; i < sizeof(a); i++)
	{
		b[i] = a[i];
	}
	for (int j = 0; j < sizeof(a1); j++)
	{	
		b[j + sizeof(a)] = a1[j];
	}
}
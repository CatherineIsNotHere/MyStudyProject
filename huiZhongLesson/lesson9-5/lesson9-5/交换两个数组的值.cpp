#include "stdio.h"

//交换两个数组的值

void main(){
	int a[5] = { 1, 2, 3, 4, 5 };
	int a1[5] = { 9, 8, 7, 6, 5};
	int b[5];
	for (int i = 0; i < 5; i++)
	{
		b[i] = a[i];
		a[i] = a1[i];
		a1[i] = b[i];
	}
}
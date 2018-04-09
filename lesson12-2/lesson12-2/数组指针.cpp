#include "stdio.h"
#include "stdlib.h"

void main(){
	int arr[5] = { 5, 4, 3, 2, 1 };
	int* pa = nullptr;
	pa = arr;
	pa[2] = 100;

	int arr2[] = {10,20,30};
	pa = arr2;
	pa[2] = 999;
	system("pause");
}
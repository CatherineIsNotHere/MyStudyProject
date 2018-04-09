#include "stdio.h"
#include "stdlib.h"

void main(){
	int arr[] = { 1, 2, 3, 4, 5 };
	int* pa = arr;
	printf("%d\n",*pa);
	pa += 1;
	printf("%d\n", *pa);//œÚ”“≈≤“ªŒª

	char arr2[] = {'a','b','c','d'};
	char* pa2 = arr2;
	printf("%d\n",*pa2);
	pa2 += 1;
	printf("%d\n",pa2);
	printf("%d\n", *pa2);
	pa2 += 3;
	printf("%d\n", pa2);
	printf("%d\n", *pa2);
	system("pause");

	int a[] = { 1, 2, 3, 4, 5, 6 };

	int* pc = a;
	int* pd = &a[5];
	int j = pd - pc;
	printf("%d\n",j);
	while (pc<pd)
	{
		printf("%d\n",*pc);
		pc += 1;
	}
}
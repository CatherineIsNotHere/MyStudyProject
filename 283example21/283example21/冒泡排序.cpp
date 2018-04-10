#include "stdio.h"

void main(){
	int a[10];
	int i,t;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d",&a[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9-i; j++)
		{	
			if (a[j]>a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\t",a[i]);
	}
}
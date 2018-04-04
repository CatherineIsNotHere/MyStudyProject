#include "stdio.h"

void main(){
	int a[6] = { -50, -80, 90, 100, 52, 46 };
	int t = 0;
	for (int i = sizeof(a) / sizeof(a[0]) - 1; i >0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j]>a[j+1]){
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	printf("排序后的数组为：\n");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d\t",a[i]);
	}
}
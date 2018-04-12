#include "stdio.h"

void main(){
	int i, j, t, a[11];					/*定义变量及数组为基本整型*/
	printf("请输入10个数:\n");
	for (i = 1; i < 11; i++)
		scanf_s("%d", &a[i]);				/*从键盘中输入要排序的10个数字*/
	for ( i = 1; i < 11; i++)
	{
		for (j= i+1; j < 11; j++)
		{
			if (a[i]>a[j]){
				a[0] = a[i];
				a[i] = a[j];
				a[j] = a[0];
			}
		}
	}
	printf("排序后的顺序是:\n");
	for (i = 1; i <= 10; i++)
		printf("%5d", a[i]);				/*将排好序的数组输出*/
	printf("\n");
}
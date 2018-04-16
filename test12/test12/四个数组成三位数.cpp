#include "stdio.h"
#include "stdlib.h"

int hundredNum(int arr[],int snum){
	int hundreds = 0;
	int decade = 0;
	int unit = 0;
	int num = 0;
	for (int i = 0; i < snum; i++)
	{
		hundreds = arr[i] * 100;
		for (int j = 0; j < snum; j++)
		{
			if (j == i)
				continue;
			decade = arr[j] * 10;
			for (int k = 0; k < snum; k++)
			{
				if (j==k||i==k)
					continue;
				unit = arr[k];
				num++;
				printf("%d\t", hundreds + decade + unit);
			}
		}
	}
	return num;
}


void main(){
	int a[] = { 1, 2, 3, 4 };
	int num=hundredNum(a,4);
	printf("\n¹²ÓĞ%d¸ö",num);
}
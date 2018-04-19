#include "stdio.h"
#include "stdlib.h"

void main(){
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	int c = 0;
	for (int i = 0; i <10; i++)
	{
		c += arr[i];
		printf("%d\t",arr[i]);
	}
	printf("\n总和：%d\n平均值：%f\n",c,(float)c/10);

	system("pause");

}
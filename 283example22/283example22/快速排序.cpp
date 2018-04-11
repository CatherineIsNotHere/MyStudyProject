#include "stdio.h"

void qusort(int s[],int start,int end){


}


void main(){
	int a[11], i;
	printf("请输入十个数：");
	for (i = 0; i < 11; i++)
	{
		scanf_s("%d",&a[i]);
	}
	for (i = 0; i < 11; i++)
	{
		printf("%d\t",a[i]);
	}
	qusort(a,1,10);
}
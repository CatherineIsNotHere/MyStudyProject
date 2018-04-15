#include "stdio.h"


void bubbleSort(int arr[],int sz){
	int t = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 1; j < sz - i;j++){
			if (arr[j-1]<arr[j]){
				t = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = t;
			}
			for (int k = 0; k < sz; k++)
			{
				printf("%d\t", arr[k]);
			}
			printf("\n");
		}
		
		
	}
	for (int k = 0; k < sz; k++)
	{
		printf("%d\t", arr[k]);
	}
}

void main(){
	int* arr=new int[5];
	printf("请输入五个数：");
	scanf_s("%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	bubbleSort(arr, 5);

}
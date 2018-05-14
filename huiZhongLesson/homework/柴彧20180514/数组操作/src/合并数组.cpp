#include <stdio.h>
#include <stdlib.h>

int* mergeArr1(int* arr1, int* arr2){//现将数组1放到数组3中，再将2中数组逐渐插入 没有用到指针
	int equalCount = 0;
	int arr3[11] = {};
	for (int i = 0; i < 5; i++)
		arr3[i] = arr1[i];
	for (int i = 0; i < 6; i++)
	for (int k = 0; k < i + 6 - equalCount; k++)
	{
		if (arr2[i] == arr3[k]){//如果相等则不操作结束循环，相等系数加1
			equalCount++;
			break;
		}
		else if (arr2[i]<arr3[k]){//如果插入数比数组中的数小则后移一位
			for (int j = i + 5; j > k; j--)
				arr3[j] = arr3[j - 1];
			arr3[k] = arr2[i];
			break;
		}
		if (arr3[k] < arr3[k - 1])//如果该数比前面的数更小，则证明该数为最后一个数，直接插入
			arr3[k] = arr2[i];
	}
	int* arr4 = new int[11 - equalCount];//合并后将目标数组缩减成正确个数（因有相同数）
	for (int i = 0; i < 11 - equalCount; i++)
		arr4[i] = arr3[i];
	printf("第一种合并排序后为：");
	for (int i = 0; i < 11 - equalCount; i++)//排序后打印
		printf("%d", arr4[i]);
	printf("\n");
	return arr4;
}

int* mergeArr2(int* arr1, int* arr2){//分别从数组1和数组2中依次取数，符合要求则插入。
	int* arr3 = new int[11]{};
	int* arrc = arr3;
	int equalCount = 0;
	int i = 0;//arr1的结束计数器
	int j = 0;//arr2的结束计数器
	while (true)
	{
		if (i < 5 && j<6){
			if (*arr1>*arr2){
				*arrc = *arr2;
				arr2++, j++;
				arrc++;
			}
			else if (*arr1 < *arr2){
				*arrc = *arr1;
				arr1++, i++;
				arrc++;
			}
			else if (*arr1 == *arr2){
				*arrc = *arr1;
				arr1++, i++;
				arr2++, j++;
				equalCount++;
				arrc++;
			}
		}
		else{
			if (i >= 5 && j < 6){
				*arrc = *arr2;
				arr2++, j++;
				arrc++;
			}
			else if (i < 5 && j >= 6){
				*arrc = *arr1;
				arr1++, i++;
				arrc++;
			}
			else{
				break;
			}
		}
	}
	int* arr4 = new int[11 - equalCount];//合并后将目标数组缩减成正确个数（因有相同数）
	for (int i = 0; i < 11 - equalCount; i++)
		arr4[i] = arr3[i];
	printf("第二种合并排序后为：");
	for (int i = 0; i < 11 - equalCount; i++)//排序后打印
		printf("%d", arr4[i]);
	printf("\n");
	return arr4;
}

void main(){
	int arr1[5] = { 1, 3, 5, 7, 9 };
	printf("数组1为：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d",arr1[i]);
	}
	printf("\n");
	int arr2[6] = { 2, 5, 6, 8, 9, 10 };
	printf("数组2为：");
	for (int i = 0; i < 6; i++)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
	int* arr3=mergeArr1(arr1, arr2);
	int* arr4=mergeArr2(arr1, arr2);
	




	system("pause");
}
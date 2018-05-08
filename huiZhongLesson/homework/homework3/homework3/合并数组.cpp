#include <stdio.h>

int* mergeArr1(int* arr1,int* arr2){//现将数组1放到数组3中，再将2中数组逐渐插入
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
			if (arr3[k]<arr3[k - 1])//如果该数比前面的数更小，则证明该数为最后一个数，直接插入
				arr3[k] = arr2[i];
		}
	int* arr4 = new int[11 - equalCount];//合并后将目标数组缩减成正确个数（因有相同数）
	for (int i = 0; i < 11 - equalCount; i++)
		arr4[i] = arr3[i];
	printf("合并排序后为：");
	for (int i = 0; i < 11 - equalCount; i++)//排序后打印
		printf("%d",arr4[i]);
	return arr4;
}

void mergeArr2(int* arr1, int* arr2){//分别从数组1和数组2中依次取数，符合要求则插入。
	int equalCount = 0;
	int arr3[11] = {};
	int k = 0;
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr2[j]>arr1[i]){
		}
	}
}

void main(){
	int arr1[5] = { 1, 3, 5, 7, 9 };
	int arr2[6] = { 2, 5, 6, 8, 9, 10 };
	//mergeArr1(arr1, arr2);

}
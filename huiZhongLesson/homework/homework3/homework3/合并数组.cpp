#include <stdio.h>

int* mergeArr1(int* arr1,int* arr2){//�ֽ�����1�ŵ�����3�У��ٽ�2�������𽥲���
	int equalCount = 0;
	int arr3[11] = {};
	for (int i = 0; i < 5; i++)
		arr3[i] = arr1[i];
	for (int i = 0; i < 6; i++)
		for (int k = 0; k < i + 6 - equalCount; k++)
		{
			if (arr2[i] == arr3[k]){//�������򲻲�������ѭ�������ϵ����1
				equalCount++;
				break;
			}
			else if (arr2[i]<arr3[k]){//����������������е���С�����һλ
				for (int j = i + 5; j > k; j--)
					arr3[j] = arr3[j - 1];
				arr3[k] = arr2[i];
				break;
			}
			if (arr3[k]<arr3[k - 1])//���������ǰ�������С����֤������Ϊ���һ������ֱ�Ӳ���
				arr3[k] = arr2[i];
		}
	int* arr4 = new int[11 - equalCount];//�ϲ���Ŀ��������������ȷ������������ͬ����
	for (int i = 0; i < 11 - equalCount; i++)
		arr4[i] = arr3[i];
	printf("�ϲ������Ϊ��");
	for (int i = 0; i < 11 - equalCount; i++)//������ӡ
		printf("%d",arr4[i]);
	return arr4;
}

void mergeArr2(int* arr1, int* arr2){//�ֱ������1������2������ȡ��������Ҫ������롣
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
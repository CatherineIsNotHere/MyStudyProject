#include <stdio.h>
#include <stdlib.h>

int* mergeArr1(int* arr1, int* arr2){//�ֽ�����1�ŵ�����3�У��ٽ�2�������𽥲��� û���õ�ָ��
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
		if (arr3[k] < arr3[k - 1])//���������ǰ�������С����֤������Ϊ���һ������ֱ�Ӳ���
			arr3[k] = arr2[i];
	}
	int* arr4 = new int[11 - equalCount];//�ϲ���Ŀ��������������ȷ������������ͬ����
	for (int i = 0; i < 11 - equalCount; i++)
		arr4[i] = arr3[i];
	printf("��һ�ֺϲ������Ϊ��");
	for (int i = 0; i < 11 - equalCount; i++)//������ӡ
		printf("%d", arr4[i]);
	printf("\n");
	return arr4;
}

int* mergeArr2(int* arr1, int* arr2){//�ֱ������1������2������ȡ��������Ҫ������롣
	int* arr3 = new int[11]{};
	int* arrc = arr3;
	int equalCount = 0;
	int i = 0;//arr1�Ľ���������
	int j = 0;//arr2�Ľ���������
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
	int* arr4 = new int[11 - equalCount];//�ϲ���Ŀ��������������ȷ������������ͬ����
	for (int i = 0; i < 11 - equalCount; i++)
		arr4[i] = arr3[i];
	printf("�ڶ��ֺϲ������Ϊ��");
	for (int i = 0; i < 11 - equalCount; i++)//������ӡ
		printf("%d", arr4[i]);
	printf("\n");
	return arr4;
}

void main(){
	int arr1[5] = { 1, 3, 5, 7, 9 };
	printf("����1Ϊ��");
	for (int i = 0; i < 5; i++)
	{
		printf("%d",arr1[i]);
	}
	printf("\n");
	int arr2[6] = { 2, 5, 6, 8, 9, 10 };
	printf("����2Ϊ��");
	for (int i = 0; i < 6; i++)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
	int* arr3=mergeArr1(arr1, arr2);
	int* arr4=mergeArr2(arr1, arr2);
	




	system("pause");
}
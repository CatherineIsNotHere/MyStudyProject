#include<stdio.h>
#include<stdlib.h>

/*
��������
*/


//��ӡ������
void Print(int args[], int end){
	int i;

	for (i = 0; i <= end; i++){
		printf("%d,", args[i]);
	}
	printf("\n");
}

//��������һ�λ����㷨
int Partition(int args[], int first, int end){

	int i, j;
	int temp;
	i = first;
	j = end;

	while (i < j){
		//�����Ҳ�ɨ��
		while (i < j&&args[i] < args[j])j--;
		if (i < j){
			temp = args[i];
			args[i] = args[j];
			args[j] = temp;
			i++;
		}
		//�������ɨ��
		while (i < j&&args[i] <= args[j]) i++;
		if (i < j){
			temp = args[i];
			args[i] = args[j];
			args[j] = temp;
			j--;
		}
	}

	return i;
}

//���������㷨���ݹ����
void QuickSort(int args[], int first, int end){
	int pivot;
	if (first < end){
		pivot = Partition(args, first, end);
		printf("�����У�");
		Print(args, end);

		QuickSort(args, first, pivot - 1);
		QuickSort(args, pivot + 1, end);
	}
}


int main(void){
	int args[] = { 23, 13, 35, 6, 19, 50, 28 };
	int first = 0;
	int end = 6;
	//��ӡ����ǰ������
	printf("ԭʼ����:");
	Print(args, end);
	QuickSort(args, first, end);
	printf("������ɺ������:");
	Print(args, end);
	system("pause");
	return 0;
}
#include "stdio.h"

void substrings(char* arr,char* arr2,int start,int last){
	int end = start + last-1;
	for (int i = 0; start <= end; start++,i++)
		arr2[i] = arr[start];
}

void main(){
	char arr[128] = {"abcdefgh"};
	char arr2[128] = {};
	int start = 0;
	int last = 0;
	printf("�������ַ�����\n");
	gets_s(arr);
	printf("�������ȡ�ַ�����ʼλ�ã�\n");
	scanf_s("%d",&start);
	printf("�������ȡ�ַ������ȣ�\n");
	scanf_s("%d", &last);
	substrings(arr,arr2,start,last);

	printf("��ȡ����ַ���Ϊ��%s",arr2);
}
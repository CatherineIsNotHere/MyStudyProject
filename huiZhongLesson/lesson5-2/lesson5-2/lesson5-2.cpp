#include "stdio.h";

void main(){
	int a = 0;
	int b = 0;
	printf("��������������  ");
	scanf_s("%d%d", &a, &b);
	//�����ж�
	if (a < b)
		printf("��һ��С\n");
	else if (a>b)
		printf("�ڶ���С\n");
	else
		printf("��һ����");
}
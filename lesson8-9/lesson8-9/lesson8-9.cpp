#include "stdio.h"

/*
�ж�������������Ƿ����5����7��������
*/

void main(){
	int a = 0;
	printf("������һ��������:");
	scanf_s("%d", &a);
	if (a % 5 == 0 && a % 7 == 0)
		printf("��5��7��������");
	else
		printf("����5��7��������");

}
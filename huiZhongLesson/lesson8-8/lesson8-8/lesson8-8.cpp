#include "stdio.h"

/*
	�����극�ж��Ƿ�Ϊ����
	*/
void main(){
	int year = 0;
	printf("������һ�꣺");
	scanf_s("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("����Ϊ���꣡");
	else
		printf("���겻�����꣡");
}
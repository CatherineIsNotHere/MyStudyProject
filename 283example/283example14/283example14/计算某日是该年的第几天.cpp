#include "stdio.h"

int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//ƽ��������
int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//����������

/*
	�ж������Ƿ�Ϊ����
*/
int leap(int year){
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/*
	��ȡ�������ڽ���ĵڼ���
*/
int date(int year, int month, int day){
	int sum = 0;
	int i = 0;
	if (leap(year) == 1){
		for (i = 0; i < month - 1; i++)
		{
			sum += b[i];
		}
	}
	else{
		for (i = 0; i < month - 1; i++)
		{
			sum += a[i];
		}
	}
	sum += day;
	return sum;
}

/*
	��ȡ���������ж�����
*/
int judgeDay(int year, int month){
	int y = leap(year);
	if (y == 1){
		return b[month - 1];
	}
	else{
		return a[month - 1];
	}
}

/*
	������
*/
void main(){
	int year = 0;
	int month = 0;
	int day = 0;
	int number = 0;
	do{
		printf("�������꣺\n");
		scanf_s("%d", &year);
		if (year > 0){
			break;
		}
		else{
			printf("��������ݷǷ���������\n");
		}
	} while (true);
	do{
		printf("�������£�\n");
		scanf_s("%d", &month);
		if (month > 0 && month <= 12){
			break;
		}
		else{
			printf("�������·ݷǷ���������\n");
		}
	} while (true);
	do{
		printf("�������գ�\n");
		scanf_s("%d", &day);
		if (day > 0 && day <= judgeDay(year,month)){
			break;
		}
		else{
			printf("�������շǷ���������\n");
		}
	} while (true);
	number = date(year, month, day);
	printf("��һ��Ϊ����ĵ�%d��", number);
}


#include "stdio.h"

/*
���1������2011��1��1�տ�ʼÿ3���һ���棬����ɹһ������
���ʵ�ֵ�����2011��1��1��֮�������1�죬�����������ڴ��滹����ɹ����
*/
int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int leap(int year){
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int days(int year, int month, int day){
	int num = 0;
	int i = 0;
	int numm = 0;
	int autoyear = 2011;

	for (autoyear; autoyear < year; autoyear++)
	{
		if (leap(year) == 1){
			num += 366;
		}
		else{
			num += 365;
		}
	}
	for (i; i < month; i++){
		if (leap(year) == 1){
			numm += b[i];
		}
		else{
			numm += a[i];
		}
	}
	num = num + numm + day;
	return num;
}

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
		if (year > 2011){
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
		if (day > 0 && day <= judgeDay(year, month)){
			break;
		}
		else{
			printf("�������շǷ���������\n");
		}
	} while (true);
	number = days(year, month, day);
	if (number % 5 > 0 && number % 5 < 4){
		printf("�ڴ���\n");
	}
	else{
		printf("��ɹ��\n");
	}
}
#include "stdio.h"
/*
	���1������2011��1��1�տ�ʼÿ3���һ���棬����ɹһ���������ʵ�ֵ�����2011��1��1��֮�������1�죬�����������ڴ��滹����ɹ����
	*/

int leap(int year){
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int days(int year, int month, int day){
	int sum = 0;
	int i = 0;//�·ݼ��������
	int summ = 0;//�·���ͼ�����
	int autoyear = 2011;
	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (autoyear; autoyear < year; autoyear++){
		if (leap(year) == 1)
			sum += 366;
		else sum += 365;
	}
	if (leap(year)==1){
		for (i; i < month; i++)
			summ += b[i];
	}
	else{
		for (i; i < month; i++)
			summ += a[i];
	}
	sum = sum + summ + day;
	return sum;
}

void main
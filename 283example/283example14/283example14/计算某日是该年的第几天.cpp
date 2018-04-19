#include "stdio.h"

int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//平年月数组
int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//闰年月数组

/*
	判定概念是否为闰年
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
	获取该日期在今年的第几天
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
	获取输入年月有多少日
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
	主方法
*/
void main(){
	int year = 0;
	int month = 0;
	int day = 0;
	int number = 0;
	do{
		printf("请输入年：\n");
		scanf_s("%d", &year);
		if (year > 0){
			break;
		}
		else{
			printf("请输入年份非法，请重输\n");
		}
	} while (true);
	do{
		printf("请输入月：\n");
		scanf_s("%d", &month);
		if (month > 0 && month <= 12){
			break;
		}
		else{
			printf("请输入月份非法，请重输\n");
		}
	} while (true);
	do{
		printf("请输入日：\n");
		scanf_s("%d", &day);
		if (day > 0 && day <= judgeDay(year,month)){
			break;
		}
		else{
			printf("请输入日非法，请重输\n");
		}
	} while (true);
	number = date(year, month, day);
	printf("这一天为该年的第%d天", number);
}


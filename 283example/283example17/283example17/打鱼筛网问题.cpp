#include "stdio.h"

/*
如果1个渔夫从2011年1月1日开始每3天打一次渔，两天晒一次网，
编程实现当输入2011年1月1日之后的任意1天，输出该渔夫是在打渔还是在晒网。
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
		if (year > 2011){
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
		if (day > 0 && day <= judgeDay(year, month)){
			break;
		}
		else{
			printf("请输入日非法，请重输\n");
		}
	} while (true);
	number = days(year, month, day);
	if (number % 5 > 0 && number % 5 < 4){
		printf("在打鱼\n");
	}
	else{
		printf("在晒网\n");
	}
}
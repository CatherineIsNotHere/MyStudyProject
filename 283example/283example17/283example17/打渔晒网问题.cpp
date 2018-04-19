#include "stdio.h"
/*
	如果1个渔夫从2011年1月1日开始每3天打一次渔，两天晒一次网，编程实现当输入2011年1月1日之后的任意1天，输出该渔夫是在打渔还是在晒网。
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
	int i = 0;//月份计算计数器
	int summ = 0;//月份求和计数器
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
#include "stdio.h"

/*
	�����������������С��ֵ
*/
void main(){
	float a = 0;
	float b = 0;
	float t = 0;
	printf("������������a,b:");
	scanf_s("%f%f",&a,&b);
	if (a>b){
		t = a;
		a = b;
		b = t;
	}
	printf("��С��ֵΪ��%.3f",a);
}
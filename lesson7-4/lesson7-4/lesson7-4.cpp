#include "stdio.h"

void main(){
	int a = 0;
	int sum = 0;
	do{
		printf("�������������");
		scanf_s("%d",&a);
		sum += a;
		printf("��Ϊ��%d\n",sum);
	} while (true);
}
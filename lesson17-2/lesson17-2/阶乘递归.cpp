#include "stdio.h"

int factorial(int a){
	int fact = 1;
	for (int i = 1; i <= a; i++)
	{
		fact = fact*i;
	}
	return fact;
}
int factorial2(int a){
	if (a==0||a==1)
	{
		return 1;
	}
	return factorial2(a - 1)*a;
}


void main(){
	int a = 0;
	printf("��������׳˵���(��0~19)��");
	scanf_s("%d",&a);
	printf("�������Ľ׳�Ϊ��%d",factorial2(a));
}
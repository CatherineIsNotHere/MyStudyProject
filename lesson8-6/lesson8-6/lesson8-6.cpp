#include "stdio.h"

/*
	����һ��������5λ����������������������Ǽ�λ
*/
void main(){
	int a = 0;
	int wei = 0;
	printf("������һ��������5λ����������");
	scanf_s("%d",&a);
	for (int i = 10000; i >= 1; i/=10)
	{
		if (a/i>=1){
			wei++;
		}
	}
	printf("��������λ��Ϊ��%d",wei);
}
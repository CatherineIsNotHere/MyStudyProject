#include "stdio.h"

/*
	����һ�������εĳ��Ϳ����ܳ������
*/
void main(){
	float a = 0;
	float b = 0;
	float peremeter = 0;
	float acreage = 0;
	printf("������һ�����ĳ���");
	scanf_s("%f", &a);
	printf("������һ�����Ŀ�");
	scanf_s("%f", &b);
	peremeter = 2 * a + 2 * b;
	acreage = a*b;
	printf("��ͼ�ε��ܳ�Ϊ:%.3f\n", peremeter);
	printf("��ͼ�ε����Ϊ:%.3f\n", acreage);
}
#include "stdio.h"

/*
	����һ���뾶ֵ���ֱ����Բ�ܳ���Բ����������
*/
void main(){
	const float pi = 3.14;
	float r = 0;
	float perimeter = 0;//�ܳ�
	float acreage = 0;//���
	float sphereAcreage = 0;//���
	float volume = 0;//���
	printf("������һ���뾶��");
	scanf_s("%f",&r);
	perimeter = 2 * pi*r;
	acreage = pi*r*r;
	sphereAcreage = 4 * pi*r*r;
	volume = 4 / 3 * pi*r*r*r;
	printf("Բ�ܳ�Ϊ%.3f\n",perimeter);
	printf("Բ���Ϊ%.3f\n", acreage);
	printf("�����Ϊ%.3f\n", sphereAcreage);
	printf("�����Ϊ%.3f\n", volume);
}
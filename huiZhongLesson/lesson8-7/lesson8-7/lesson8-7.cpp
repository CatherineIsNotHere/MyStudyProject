#include "stdio.h"

/*
	����һ��ʵ�����������ֵ
*/
void main(){
	int a = 0;
	int absolute = 0;//����ֵ
	printf("������һ��ʵ����");
	scanf_s("%d",&a);
	if (a<0){
		absolute = a*-1;
	}
	else{
		absolute = a;
	}
	printf("�����ľ���ֵΪ��%d",absolute);
}
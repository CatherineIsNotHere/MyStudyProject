#include "stdio.h"

/*
	����ĳĳ++�Ȱ�++������ŵ��������
*/
void main(){
	int x[] = {10,20,30};
	int* px = x;
	printf("++*pxΪ��%d\n",++*px);//11
	printf("*pxΪ��%d\n",*px);//11
	px = x;
	printf("(*px)++Ϊ��%d\n",(*px)++);//12�Ǵ��Ӧ����11
	printf("*pxΪ��%d\n",*px);//11�Ǵ��Ӧ����12
	px = x;
	printf("*px++Ϊ��%d\n",*px++);//12
	printf("*pxΪ��%d\n",*px);//12�Ǵ��Ӧ����20
	px = x;
	printf("*++pxΪ��%d\n",*++px);//20
	printf("*pxΪ��%d\n",*px);//20

}
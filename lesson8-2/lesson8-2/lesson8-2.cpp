#include "stdio.h"

/*
	����һ���ַ���Ȼ�����ַ�������������ʽ���
*/
void main(){
	char a = 0;
	printf("������һ���ַ���");
	scanf_s("%c",&a,3);
	printf("�ַ�Ϊ:%c",a);
	printf("����Ϊ:%d",a);
	getchar();
}
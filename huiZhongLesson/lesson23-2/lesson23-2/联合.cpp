#include <stdio.h>

struct MYCOLOR//�ֽ���
{
	char a;
	char b;
	char g;
	char r;
};

/*
	ʹ���������� �ڴ���ֻ���������������ֽڵĿռ䣬���ԣ��޸������е����ݣ����������е�����Ҳ��ı�
*/
union MyUnion{
	int ncol;
	MYCOLOR col;
};

void main(){
	MyUnion a;
	a.ncol = 20;
	a.col.r = 120;
	a.col.g = 0;
	a.col.b = 20;
	a.col.a = 122;
	printf("%d\t%d\t%d\t%d\n", a.col.r,a.col.g,a.col.b,a.col.a);
	printf("%x\n", a.ncol);
}
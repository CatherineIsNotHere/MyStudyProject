#include <stdio.h>

struct MYCOLOR//字节序
{
	char a;
	char b;
	char g;
	char r;
};

/*
	使用联合声明 内存中只会分配联合内最大字节的空间，所以，修改联合中的数据，其他联合中的数据也会改变
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
#include "stdio.h"
//欧几里得求两数的最大公约数
void main(){
	printf("hello test1");
	int m, n, r;
	printf("请输入两个正整数");
	scanf_s("%d%d",&m,&n);
	printf("\n%d和%d的最大公约数是：",m,n);
	r = m%n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m%n;
	}
	printf("%d\n",n);
}
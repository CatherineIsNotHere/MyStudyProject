#include "stdio.h"
//ŷ����������������Լ��
void main(){
	printf("hello test1");
	int m, n, r;
	printf("����������������");
	scanf_s("%d%d",&m,&n);
	printf("\n%d��%d�����Լ���ǣ�",m,n);
	r = m%n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m%n;
	}
	printf("%d\n",n);
}
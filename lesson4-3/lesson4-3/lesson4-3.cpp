#include "stdio.h"
/*
%c һ����һ���ַ�
%d һ��ʮ��������
%i һ������
%e, %f, %g һ��������
%o һ���˽�����
%s һ���ַ���
%x һ��ʮ��������
%p һ��ָ��
%n һ�����ڶ�ȡ�ַ�����������
%u һ���޷�������
%[] һ���ַ���
%% һ�����ȷ���
*/
void main(){
	int a;
	int b;
	printf("��������������");
	scanf_s("%d %d",&a,&b);
	int c1 = a + b;
	int c2 = a - b;
	int c3 = a*b;
	int c4 = a / b;
	printf("a+bΪ%d\n", c1);
	printf("a-bΪ%d\n", c2);
	printf("a*bΪ%d\n", c3);
	printf("a/bΪ%d\n", c4);

	printf("����������ָ��");
	scanf_s("%p %p", &a, &b);
	printf("ָ��aΪ%p\n", a);
	printf("ָ��bΪ%p\n", b);


}
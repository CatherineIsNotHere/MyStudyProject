#include "stdio.h"

void test1(int t){
	for (int i=1; i <= t; i++)
	{
		for (int j= 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
}


void test2(int t){//t=7
	//   *    //7/2=3 3�ո� 1��
	//	***	//7/2=3-1 2�ո� 3��
	// *****  //7/3=3-2 1�ո� 5��
	//******* //7/3=3-3 0�ո� 7��
	// *****  //7/3=3-2 1�ո� 5��
	//	***	//7/2=3-1 2�ո� 3��
	//   *    //7/2=3 3�ո� 1��
	int num = t / 2;
	for (num + 1; num >= 0; num--)
	{
		int j = t / 2;
		for (j; j > t / 2 - num; j--)
		{
			printf(" ");
		}
	}
	int num2 = t / 2;
	for (num2; num2 >= 0; num2--)
	{
		for (int j = 1; j <= t / 2 - num2; j++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}

void test3(int t){

}
void main(){
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;
	/*printf("����Ļ���������ͼ���������ǽ����ó��������������ֵ�����ƣ�");
	scanf_s("%d",&t1);
	getchar();
	test1(t1);*/

	printf("���������Σ����ǽ����ó��������������ֵ�����ƣ�");
	scanf_s("%d", &t2);
	getchar();
	test2(t2);

	//printf("��̴�ӡͼ�Σ����ǽ����ó��������������ֵ�����ƣ�");
	//scanf_s("%d", &t3);
	//getchar();
	//test3(t3);
}
#include "stdio.h"

void test1(int t){
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= i; j++)
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
	int up = t / 2 + 1;//�ϰ벿�ֵ��и���
	int k = t / 2;//�ո����
	for (up; up > 0; up--)
	{
		int j = k;
		for (j; j > 0; j--)
		{
			printf(" ");
		}
		int i = t - 2 * k;
		for (i; i > 0; i--)
		{
			printf("*");
		}
		printf("\n");
		k--;
	}

	int down = t % 2 == 0 ? t / 2 + 1 : t / 2;//�°벿�ֵ��и���
	k = t % 2 == 0 ? 0 : 1;//�ո����
	for (down; down > 0; down--)
	{
		int j = k;
		for (j; j > 0; j--)
		{
			printf(" ");
		}
		int i = t - 2 * k;
		for (i; i > 0; i--)
		{
			printf("*");
		}
		printf("\n");
		k++;
	}
}

void test3(int t){
	 //     1       ����6 �ո� 5
	 //    121
	 //   12321
	 //  1234321
	 // 123454321
	 //12345654321
	int k = t - 1;
	int h = t;
	for (h; h > 0; h--)
	{
		int i = k;
		for (i; i > 0; i--)
		{
			printf(" ");
		}
		int num = 2*t-1-2*k;//�ܿ�ȼ�2���ո���Ҳ����ÿһ���ж��ٸ���
		int mnum = num / 2 + 1;//�ó��м�������
		for (int j=1; j < mnum; j++)
		{
			printf("%d",j);
		}
		for (mnum; mnum > 0 ; mnum--)
		{
			printf("%d", mnum);
		}
		printf("\n");
		k--;
	}
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
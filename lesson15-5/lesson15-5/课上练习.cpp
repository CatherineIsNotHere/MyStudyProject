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
	//   *    //7/2=3 3空格 1星
	//	***	//7/2=3-1 2空格 3星
	// *****  //7/3=3-2 1空格 5星
	//******* //7/3=3-3 0空格 7星
	// *****  //7/3=3-2 1空格 5星
	//	***	//7/2=3-1 2空格 3星
	//   *    //7/2=3 3空格 1星
	int up = t / 2 + 1;//上半部分的行个数
	int k = t / 2;//空格个数
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

	int down = t % 2 == 0 ? t / 2 + 1 : t / 2;//下半部分的行个数
	k = t % 2 == 0 ? 0 : 1;//空格个数
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
	 //     1       行数6 空格 5
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
		int num = 2*t-1-2*k;//总宽度减2倍空格数也就是每一行有多少个数
		int mnum = num / 2 + 1;//得出中间最大的数
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
	/*printf("在屏幕上输出如下图案：（考虑将数得出的行数由输入的值来控制）");
	scanf_s("%d",&t1);
	getchar();
	test1(t1);*/

	printf("编程输出菱形（考虑将数得出的行数由输入的值来控制）");
	scanf_s("%d", &t2);
	getchar();
	test2(t2);

	//printf("编程打印图形（考虑将数得出的行数由输入的值来控制）");
	//scanf_s("%d", &t3);
	//getchar();
	//test3(t3);
}
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
	//   *    //7/2=3 3空格 1星
	//	***	//7/2=3-1 2空格 3星
	// *****  //7/3=3-2 1空格 5星
	//******* //7/3=3-3 0空格 7星
	// *****  //7/3=3-2 1空格 5星
	//	***	//7/2=3-1 2空格 3星
	//   *    //7/2=3 3空格 1星
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
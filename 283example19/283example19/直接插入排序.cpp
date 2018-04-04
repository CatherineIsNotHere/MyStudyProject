#include "stdio.h";


//插入排序算法
/*
	当把数组作为函数的参数时，
	你无法在程序运行时通过数组参数本身告诉函数该数组的大小，
	因为函数的数组参数相当于指向该数组第一个元素的指针。
	这意味着把数组传递给函数的效率非常高，
	也意味着程序员必须通过某种机制告诉函数数组参数的大小。
*/
void sort(int s[],int i){
	int k = 0;
	for (int j = 2; j < i; j++){
		s[0] = s[j];
		k = j;
		while (s[0]<s[k-1]){
			s[k] = s[k-1];
			k--;
		}
		s[k] = s[0];
	}
}

void main(){
	int a[11] = {0,1,60,70,80,-20,30,90,10,20,20};
	printf("请输入10个数字组成数组：");
	//for (int i = 1; i < 11; i++)
	//{
	//	scanf_s("%d", &a[i]);
	//}
	printf("\n原数组为：");
	for (int i = 0; i < 11; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	sort(a,sizeof(a)/sizeof(a[0]));
	printf("\n排序后的数组为：");
	for (int i = 0; i < 11; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
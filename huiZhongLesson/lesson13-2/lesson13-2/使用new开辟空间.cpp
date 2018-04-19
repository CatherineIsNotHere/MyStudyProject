#include "stdio.h"

/*
	使用普通方法不能创建一个随用户输入动态变化的数组
	这时候就通常需要用到new方法
	所有new出来的东西，全部放在堆中，栈用来存放程序的局部数据，
*/
void main(){
	int n = 0;
	scanf_s("%d",&n);
	int* pa = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		pa[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",pa[i]);
	}
	delete[] pa;//c语言new出的东西如果不用则不会自动在内存中删除，需要手动回收，如若不回收则会变成野指针
	pa = nullptr;//上一句是将开辟的空间回收，这一句则是将指向开辟空间的地址回收，如果是二级指针，是否也要将二级指针在内存中回收？

}
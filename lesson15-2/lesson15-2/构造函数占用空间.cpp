#include "stdio.h"
#include "stdlib.h"

void main(){
	struct data
	{
		int d1 : 10;
		int d2 : 8;
		int d3 : 12;
		int d4 : 2;//：后表示占多少位
	};

	struct test1
	{
	
		char name;
		int age;
		char gender;
		
	};

	test1 t;
	//手动对齐有很多方法
	//方法一右键项目-->代码生成-->结构成员对齐

#pragma pack(push,1)//方法二手动一字节对齐
	struct data2
	{
		int d1;
		int d2;
		int d3;
		int d4;
	};
#pragma pack(pop)

	data2 d2;

	_declspec(align(32))//方法三设置32字节对齐
	struct data3{
		int d1;
		int d2;
		int d3;
		int d4;
	};
	data3 d3;

	system("pause");
}
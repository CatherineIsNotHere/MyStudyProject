#include "stdio.h"
#include "stdlib.h"

void main(){
	struct data
	{
		int d1 : 10;
		int d2 : 8;
		int d3 : 12;
		int d4 : 2;//�����ʾռ����λ
	};

	struct test1
	{
	
		char name;
		int age;
		char gender;
		
	};

	test1 t;
	//�ֶ������кܶ෽��
	//����һ�Ҽ���Ŀ-->��������-->�ṹ��Ա����

#pragma pack(push,1)//�������ֶ�һ�ֽڶ���
	struct data2
	{
		int d1;
		int d2;
		int d3;
		int d4;
	};
#pragma pack(pop)

	data2 d2;

	_declspec(align(32))//����������32�ֽڶ���
	struct data3{
		int d1;
		int d2;
		int d3;
		int d4;
	};
	data3 d3;

	system("pause");
}
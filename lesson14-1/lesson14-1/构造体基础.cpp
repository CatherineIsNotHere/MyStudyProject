#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct people
{
	char name[32];
	int age;
}per;

void main(){

	struct PC{
		int code;
		char situation[33];
	};

	struct student
	{
		//p p;
		char name[32];
		int age;
		char gender[3];
		int tel;
	};

	struct teacher{
		per tper;
		int cls;
		PC* computer[2];
	};

	per p1;
	student s1;
	s1.age = 10;
	s1.name[0] = 'a';
	s1.name[1] = 'b';//这种方法赋值只能赋值成单个字符，比较麻烦
	strcpy_s(s1.name, "ddd");//可以使用字符串操作方法，不要超过char数组长度31
	student s2 = {"猜猜",123,"dd",1502};//可以使用初始化即定义的方法将对象赋值，但顺序必须一致
	student sarr[3] = {};//这种方法创建三个学生
	student s3 = {};//创建空对象可以将初始值默认全部为空，以便后续赋值
	student sarr2[3] = { {"s1",321}, {"s2",456}, {"s3",789} };//创建3个对象并赋值

////////////////////////////////////////////////////////////////////////////////////////////

	student* ptr_s = new student{"大泡大",34};//使用new的方法创建对象时不能直接赋予初始值，也就是说左面大括号内东西并没有用处
	ptr_s->age = 444;//指针使用->给予赋值
	strcpy_s(ptr_s->name,"大泡泡大");

	delete ptr_s;
	ptr_s = nullptr;

////////////////////////////////////////////////////////////////////////////////////////////

	teacher* ptr_ter1 = new teacher[2];//以下为两种定义形式
	teacher ptr_ter2;
	ptr_ter1->cls = 11;//设置班级为11
	strcpy_s(ptr_ter1->tper.name,"老师1");//设置名字为"老师"
	ptr_ter1->tper.age = 10;//设置年龄为10
	PC* com = new PC[2];
	com[0].code = 453123;
	strcpy_s(com[0].situation,"厕所");
	com[1].code = 987654;
	strcpy_s(com[1].situation, "教室");
	ptr_ter1->computer[0] = &com[0];
	ptr_ter1->computer[1] = &com[1];
	
	int* ptr_i = new int[2];
	ptr_i[0] = 1;

	system("pause");
	delete[] ptr_i;
	ptr_i = nullptr;
	delete com;
	delete[] ptr_ter1;
	ptr_ter1 = nullptr;
	system("pause");
}
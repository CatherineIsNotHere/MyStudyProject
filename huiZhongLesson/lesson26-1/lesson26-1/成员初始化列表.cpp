#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Student{
public:
	//Student(int a,float h,char* pname,int& c)
	Student(int a, float h, char* pname)
		:age(a)//成员初始化列表 使用这种方法创建对象比较快 但如果类中变量含有引用型成员变量则必须要写成员初始化列表
		, height(h)
		, name(nullptr)
		, data(0)//常量需要在这里赋值 类内的常量不可以在类外修改，只可以在初始化赋值
		//	, aaa(c)
	{
		name = new char[strlen(pname) + 1];
		strcpy_s(name, strlen(pname) + 1, pname);
		count++;
	}
	static int count;//类的静态变量存在于全局数据区，所以大小还是不包含静态变量的变量大小总和
	~Student(){
		delete[] name;
		name = nullptr;
	}
	static void Mycount(){//静态函数用来操作静态变量
		printf("aaaa");
	}
private:
	char* name;
	int age;
	float height;
	//int& aaa;//引用类型变量
	const int data;//常量
};
int Student::count = 0;//对类的内部静态成员变量进行初始化赋值
void main(){
	Student a1(10,29.0,"张三");
	Student a2(12, 31.0, "李四");
	Student a3(13, 30.0, "王五");
	printf("%d\t",Student::count);//以下输出结果均为3
	printf("%d\t", a1.count);
	printf("%d\t", a2.count);
	printf("%d\t\n", a3.count);
	Student::Mycount();

}
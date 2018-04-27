#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class cRectangle{

public:
	int width;
	int height;
	char* pname;

	cRectangle(){
		width = 10;
		height = 20;
	}

	cRectangle(int w, int h,char* name){
		width = w;
		height = h;
		int s=strlen(name);
		pname = new char[s];
		strcpy_s(pname,s+1,name);//第二个参数指定长度为字符串大小加1
		
	}
	/*
	析构函数 用于清理工作，把所有该类的可清理的东西全部清理掉

	析构函数的执行与对象的创建位置相关
	1，当对象被声明为全局变量，则当整个程序退出时，其析构函数才会被调用。
	2，当对象被声明为自动存储类型(局部变量)，当其生命周期结束，即其作用域执行完毕时，其析构函数会被调用。
	3，当对象被声明为指针变量(使用new创建对象)，当执行到delete方法时，其析构函数会被调用。
	4，临时对象，这种对象在临时对象完成任务时自动调用其析构函数。
	*/
	~cRectangle(){
		delete[] pname;
		pname = nullptr;
	}

	int getarea(){
		return width*height;
	}

	int perimeter(){
		return 2 * (width + height);
	}
};

void main(){
	cRectangle r(2,20,"abc");
	int a = r.getarea();


	system("pause");

}
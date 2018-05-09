#include <stdio.h>

class CMyClass{
public:
	virtual void fun(){}
	void fun(int){}
};

class ClassA{
public:
	virtual void fun(){
		printf("ClassA");
	}
	void fun2(int a){
		printf("ClassA fun2");
	}
};

class ClassB:public ClassA
{
public:
	void fun(){//override
		printf("ClassB");
	}
	void fun2(){//overwrite
		printf("ClassB fun2");
	}
};

void main(){
	ClassA* pa=new ClassB;
	pa->fun();

	ClassB b;
	b.fun2();
}
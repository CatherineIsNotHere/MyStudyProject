#include <stdio.h>

class Base{
public:
	void fun(){
		printf("base:fun");
	}
private:
	int _base;
};

class A:virtual public Base{

private:
	int _a;
};
class B:virtual public Base{//Ðé¼Ì³Ð
private:
	int _b;

};
class D:public A,B{

};


void main(){
	D d;
	d.fun();
}
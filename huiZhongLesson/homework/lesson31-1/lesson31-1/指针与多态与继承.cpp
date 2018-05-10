#include <stdio.h>
#include <stdlib.h>

class B{
public:
	void fun(){
		printf("B");
	}
};

class C{
public:
	void fun(){
		printf("C");
	}
};

class D:public B{

public:
	void fun(){
		printf("D");
	}
};

class E :public C{

public:
	void fun(){
		printf("E");
	}
};



void main(){
	B b, *pb;
	D d, *pd;
	//ָ����̳ж���ͨ��Ա�����ĵ��ã���ָ������;���
	pb = &b;
	pb->fun();

	pb = &d;
	pb->fun();

	pd = &d;
	pd->fun();

	pd = (D*)&b;
	pd->fun();


	C c, *pc;
	E e, *pe;
	//ָ�����̬����ͨ��Ա�����ĵ��ã��ɸ�ֵ����
	pc = &c;
	pc->fun();

	pc = &e;
	pc->fun();

	pe = &e;
	pe->fun();

	pe = (E*)&c;
	pe->fun();
	system("pause");
}
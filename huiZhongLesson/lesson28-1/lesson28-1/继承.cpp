#include<stdio.h>
#include<stdlib.h>

class person{
public:
	person()
		:length(180)
		, weight(170)
		, borndate(19910429)
	{
		printf("����person");
	}
	~person(){
		printf("����person");
	}
private:
	void print(){
		
	}
	int length;
	int weight;
	int borndate;
	char name[32];
};

class dad{
public:
	dad(){
	
	}
	dad(int len)
		:len(180)
		, wei(170)
		, bor(19910429)
	{
		printf("����dad");
	}
	~dad(){
		printf("����person");
	}
	int len;
	int wei;
	int bor;
};

class student:public person,dad{//�̳�
public:
	student(int len)
		:dad(len)
	{
		
		printf("����student");
	}
	~student(){
		printf("����student");
	}
	void print(){
		student s(20);
		s.print();
	}

};

void main(){
	person* s = new student(10);
	system("pause");
}
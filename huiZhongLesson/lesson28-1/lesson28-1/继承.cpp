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
	dad()
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

class student:private person,dad{//�̳�
public:
	student(){
		printf("����student");
	}
	~student(){
		printf("����student");
	}
	void print(){
		student s;
		s.print;
	}

};

void main(){
	student s;
	system("pause");
}
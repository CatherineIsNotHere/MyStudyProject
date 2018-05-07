#include<stdio.h>
#include<stdlib.h>

class person{
public:
	person()
		:length(180)
		, weight(170)
		, borndate(19910429)
	{
		printf("构造person");
	}
	~person(){
		printf("析构person");
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
		printf("构造dad");
	}
	~dad(){
		printf("析构person");
	}
	int len;
	int wei;
	int bor;
};

class student:private person,dad{//继承
public:
	student(){
		printf("构造student");
	}
	~student(){
		printf("析构student");
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
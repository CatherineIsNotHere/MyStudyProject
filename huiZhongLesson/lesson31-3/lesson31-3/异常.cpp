#include <stdio.h>
#include <exception>

class CErrorMsg{
public:
	CErrorMsg(){
		printf("�������쳣\n");
	}
	~CErrorMsg(){
		printf("�������쳣\n");
	}
	CErrorMsg(const CErrorMsg& r){
		printf("�������쳣\n");
	}
	void report(){
		printf("������쳣��Ϣ");
	}
};

class CGame{
private:
	char* name;
public:
	CGame(char* n){
		this->name = n;
		printf("������Ϸ\n");
	}
	~CGame(){
		printf("������Ϸ\n");
	}
	void myThrow(){
		throw CErrorMsg();
	}
};



int fun(int a, int b){
	if (b==0){
		throw "����";
	}
	return a / b;
}

void main(){
	
	CGame* p = new CGame("�궷��");

	try{
		p->myThrow();
	}
	catch (CErrorMsg& r){
		r.report();
	}
	catch (...){
		printf("������쳣");
	}

}
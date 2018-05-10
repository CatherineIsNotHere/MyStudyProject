#include <stdio.h>
#include <exception>

class CErrorMsg{
public:
	CErrorMsg(){
		printf("构造了异常\n");
	}
	~CErrorMsg(){
		printf("销毁了异常\n");
	}
	CErrorMsg(const CErrorMsg& r){
		printf("拷贝了异常\n");
	}
	void report(){
		printf("这个是异常信息");
	}
};

class CGame{
private:
	char* name;
public:
	CGame(char* n){
		this->name = n;
		printf("创建游戏\n");
	}
	~CGame(){
		printf("销毁游戏\n");
	}
	void myThrow(){
		throw CErrorMsg();
	}
};



int fun(int a, int b){
	if (b==0){
		throw "错误";
	}
	return a / b;
}

void main(){
	
	CGame* p = new CGame("魂斗罗");

	try{
		p->myThrow();
	}
	catch (CErrorMsg& r){
		r.report();
	}
	catch (...){
		printf("其余的异常");
	}

}
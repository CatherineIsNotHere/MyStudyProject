#include<stdio.h>

class CCharactor{
public:
	virtual void draw(){//虚函数
		printf("角色基类的绘制");
	}
	virtual ~CCharactor(){//虚析构
		printf("~CCaractor");
	}
};

class CHero :public CCharactor{
public:
	void draw(){
		printf("英雄基类的绘制");
	}
	~CHero(){
		printf("~CHero");
	}
};
class CNPC:public CCharactor{
public:
	void draw(){
		printf("NPC基类的绘制");
	}
	~CNPC(){
		printf("~CNPC");
	}
};
void main(){
	/*CCharactor* p1 = new CHero();
	CCharactor* p2 = new CNPC();*/
	CCharactor* p[2] = {new CHero(),new CNPC()};
	p[0]->draw();
	p[1]->draw();
	CCharactor* ph = new CHero();
	delete ph;
}
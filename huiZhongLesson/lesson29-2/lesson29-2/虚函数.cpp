#include<stdio.h>

class CCharactor{
public:
	virtual void draw(){//�麯��
		printf("��ɫ����Ļ���");
	}
	virtual ~CCharactor(){//������
		printf("~CCaractor");
	}
};

class CHero :public CCharactor{
public:
	void draw(){
		printf("Ӣ�ۻ���Ļ���");
	}
	~CHero(){
		printf("~CHero");
	}
};
class CNPC:public CCharactor{
public:
	void draw(){
		printf("NPC����Ļ���");
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
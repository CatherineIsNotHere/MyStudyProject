#include <stdio.h>

class CBase{
public :
	CBase(){};
	virtual ~CBase(){
		printf("CBase delete");
	};
	virtual void Update() = 0;//����ֻҪ��һ������Ϊ���麯��������಻�ܱ�ʵ������ֻ�ܱ��̳�
	virtual void Redraw() = 0;


};

class CSuperMario:public CBase{
public:
	CSuperMario(){
	}
	~CSuperMario(){
		printf("CSuperMario delete");
	}
	virtual void Update(){//�̳к����ʵ�ָú������ܱ�ʵ����
		printf("CSuperMario Update\n");
	}
	virtual void Redraw(){
		printf("CSuperMario Redraw\n");
	}
};

class CContra :public CBase{
public:
	CContra(){
	}
	~CContra(){
		printf("CContra delete");
	}
	virtual void Update(){//�̳к����ʵ�ָú������ܱ�ʵ����
		printf("CContra Update\n");
	}
	virtual void Redraw(){
		printf("CContra Redraw\n");
	}
};

void main(){
	CBase* cb = new CSuperMario();
	delete cb;
	CSuperMario cd;
}
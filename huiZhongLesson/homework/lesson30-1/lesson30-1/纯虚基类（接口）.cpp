#include <stdio.h>

class CBase{
public :
	CBase(){};
	virtual ~CBase(){
		printf("CBase delete");
	};
	virtual void Update() = 0;//类中只要有一个函数为纯虚函数，则该类不能被实例化，只能被继承
	virtual void Redraw() = 0;


};

class CSuperMario:public CBase{
public:
	CSuperMario(){
	}
	~CSuperMario(){
		printf("CSuperMario delete");
	}
	virtual void Update(){//继承后必须实现该函数才能被实例化
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
	virtual void Update(){//继承后必须实现该函数才能被实例化
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
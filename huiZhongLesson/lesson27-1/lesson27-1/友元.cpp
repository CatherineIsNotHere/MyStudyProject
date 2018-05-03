#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class CCar{//友元函数举例
public:
	CCar()
		:m_nspead(100)
	{
		strcpy_s(m_szName,20,"BLACK");
	}
	void show(){
		printf("%d,%s\n",m_nspead,m_szName);
	}
	//int getSpead(){
	//	return m_nspead;
	//}
	//char* getName(){
	//	return m_szName;
	//}
	friend void showCar(CCar* c);//友元函数
private:
	int m_nspead;
	char m_szName[20];
};

void showCar(CCar* car){//写指针只传4个字节，比较快
	printf("%d,%s",car->m_nspead,car->m_szName);

}

///////////////////////////////////////////////

class CCar2{//友元类举例 友元类是单向的 局部打破了数据封装
public:
	CCar2()
		:m_nspead(100)
	{
		strcpy_s(m_szName, 20, "BLACK");
	}
	void show(){
		printf("%d,%s\n", m_nspead, m_szName);
	}
	void showPrinter(CPrinter* p){
		printf("%d",p->m_inumber);
	}
	friend class CPrinter;
private:
	int m_nspead;
	char m_szName[20];
};

class CPrinter{
public:
	void showCCar(CCar2* car){
		printf("%d,%n", car->m_nspead, car->m_szName);
	}
	friend class CCar2;
private:
	int m_inumber;
};

void main(){
	CCar c;
	showCar(&c);

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class CCar{//��Ԫ��������
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
	friend void showCar(CCar* c);//��Ԫ����
private:
	int m_nspead;
	char m_szName[20];
};

void showCar(CCar* car){//дָ��ֻ��4���ֽڣ��ȽϿ�
	printf("%d,%s",car->m_nspead,car->m_szName);

}

///////////////////////////////////////////////

class CCar2{//��Ԫ����� ��Ԫ���ǵ���� �ֲ����������ݷ�װ
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
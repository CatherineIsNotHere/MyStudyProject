#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Student{
public:
	//Student(int a,float h,char* pname,int& c)
	Student(int a, float h, char* pname)
		:age(a)//��Ա��ʼ���б� ʹ�����ַ�����������ȽϿ� ��������б������������ͳ�Ա���������Ҫд��Ա��ʼ���б�
		, height(h)
		, name(nullptr)
		, data(0)//������Ҫ�����︳ֵ ���ڵĳ����������������޸ģ�ֻ�����ڳ�ʼ����ֵ
		//	, aaa(c)
	{
		name = new char[strlen(pname) + 1];
		strcpy_s(name, strlen(pname) + 1, pname);
		count++;
	}
	static int count;//��ľ�̬����������ȫ�������������Դ�С���ǲ�������̬�����ı�����С�ܺ�
	~Student(){
		delete[] name;
		name = nullptr;
	}
	static void Mycount(){//��̬��������������̬����
		printf("aaaa");
	}
private:
	char* name;
	int age;
	float height;
	//int& aaa;//�������ͱ���
	const int data;//����
};
int Student::count = 0;//������ڲ���̬��Ա�������г�ʼ����ֵ
void main(){
	Student a1(10,29.0,"����");
	Student a2(12, 31.0, "����");
	Student a3(13, 30.0, "����");
	printf("%d\t",Student::count);//������������Ϊ3
	printf("%d\t", a1.count);
	printf("%d\t", a2.count);
	printf("%d\t\n", a3.count);
	Student::Mycount();

}
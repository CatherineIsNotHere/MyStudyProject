#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct people
{
	char name[32];
	int age;
}per;

void main(){

	struct PC{
		int code;
		char situation[33];
	};

	struct student
	{
		//p p;
		char name[32];
		int age;
		char gender[3];
		int tel;
	};

	struct teacher{
		per tper;
		int cls;
		PC* computer[2];
	};

	per p1;
	student s1;
	s1.age = 10;
	s1.name[0] = 'a';
	s1.name[1] = 'b';//���ַ�����ֵֻ�ܸ�ֵ�ɵ����ַ����Ƚ��鷳
	strcpy_s(s1.name, "ddd");//����ʹ���ַ���������������Ҫ����char���鳤��31
	student s2 = {"�²�",123,"dd",1502};//����ʹ�ó�ʼ��������ķ���������ֵ����˳�����һ��
	student sarr[3] = {};//���ַ�����������ѧ��
	student s3 = {};//�����ն�����Խ���ʼֵĬ��ȫ��Ϊ�գ��Ա������ֵ
	student sarr2[3] = { {"s1",321}, {"s2",456}, {"s3",789} };//����3�����󲢸�ֵ

////////////////////////////////////////////////////////////////////////////////////////////

	student* ptr_s = new student{"���ݴ�",34};//ʹ��new�ķ�����������ʱ����ֱ�Ӹ����ʼֵ��Ҳ����˵����������ڶ�����û���ô�
	ptr_s->age = 444;//ָ��ʹ��->���踳ֵ
	strcpy_s(ptr_s->name,"�����ݴ�");

	delete ptr_s;
	ptr_s = nullptr;

////////////////////////////////////////////////////////////////////////////////////////////

	teacher* ptr_ter1 = new teacher[2];//����Ϊ���ֶ�����ʽ
	teacher ptr_ter2;
	ptr_ter1->cls = 11;//���ð༶Ϊ11
	strcpy_s(ptr_ter1->tper.name,"��ʦ1");//��������Ϊ"��ʦ"
	ptr_ter1->tper.age = 10;//��������Ϊ10
	PC* com = new PC[2];
	com[0].code = 453123;
	strcpy_s(com[0].situation,"����");
	com[1].code = 987654;
	strcpy_s(com[1].situation, "����");
	ptr_ter1->computer[0] = &com[0];
	ptr_ter1->computer[1] = &com[1];
	
	int* ptr_i = new int[2];
	ptr_i[0] = 1;

	system("pause");
	delete[] ptr_i;
	ptr_i = nullptr;
	delete com;
	delete[] ptr_ter1;
	ptr_ter1 = nullptr;
	system("pause");
}
#include "stdio.h"

void MyNew(char* pointer){
	pointer = new char[32];//��ʱ��Ȼpointer��������һ����ַ����ͨ��new�ķ��������¸���һ����ַ��pointer����new��pointer��=p,��ʱp����Ϊnullptr��
}

void MyNew2(char** pointer){
	*pointer = new char[32];//���ｫpָ��ĵ�ַ�����pointer��Ȼ��ͨ��new�ķ�������һ����ַ������õ�pointerҲ����p����ַ������ʱp����ֵ��
}

void main(){
	char* p = nullptr;
	//MyNew(p);//��ʱ�ڴ˴�����p��ȻΪnullptr����15�б���
	MyNew2(&p);//���ǽ�pָ��ĵ�ַ�����pointer
	p[0] = 'a';
	delete p;
	p = nullptr;
}
#include "stdio.h"

void main(){
	struct data{
		char name[9];//9�ֽ�
		int d1;//4�ֽ�
		int d2;//4�ֽ�
	};
	data d;
	printf("%d",sizeof(d));//20�ֽڣ�cpu��4�ֽ�4�ֽڵĶ�ȡ������4�ֽڻ��Զ�����
}
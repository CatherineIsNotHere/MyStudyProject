#include "stdio.h"
#include "stdlib.h"

void copyStr(char* p1, char** p2, int l){
	*p2 = new char[];
	char* ps=new char[l];
	for (int i = 0; i <l; i++)
	{
		ps[i] = p1[i];
	}
	*p2 = ps;
	printf("\n");
}

void main(){
	char ss[99] ;
	printf("����һ���ַ�����");
	gets_s(ss);
	char* s1 = ss;
	char* s2 = nullptr;
	int l = sizeof(ss) / sizeof(s1[0]);
	copyStr(s1, &s2, l);
	printf("s1Ϊ%s\n", s1);
	printf("s2Ϊ%s", s2);
	system("pause");
}
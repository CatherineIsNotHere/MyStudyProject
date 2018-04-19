#include "stdio.h"
#include "stdlib.h"

void copyStr(char* p1, char* p2, int l){
	//*p2 = new char[];
	//char* ps=new char[l];
	for (int i = 0; i <l; i++)
	{
		p2[i] = p1[i];
	}
	//*p2 = ps;
	printf("\n");
}

void main(){
	char s1[128] = {};
	char s2[128] = {};
	printf("输入一个字符串：");
	gets_s(s1);
	int l = sizeof(s1) / sizeof(s1[0]);
	copyStr(s1, s2, l);
	printf("s2为%s", s2);
	system("pause");
}
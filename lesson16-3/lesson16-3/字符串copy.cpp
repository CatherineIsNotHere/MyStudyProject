#include "stdio.h"
#include "stdlib.h"

void copyStr(char* p1, char** p2, int l){
	printf("%d\n", l);
	*p2 = new char[];
	char* ps=new char[l];
	for (int i = 0; i <l; i++)
	{
		ps[i] = p1[i];
	}
	printf("%s", ps);
	*p2 = ps;
	printf("\n");
}

void main(){
	char ss[] = { "hello" };
	char* s1 = ss;
	char* s2 = nullptr;
	int l = sizeof(ss) / sizeof(s1[0]);
	copyStr(s1, &s2, l);
	system("pause");
}
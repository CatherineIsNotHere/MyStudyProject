#include <stdio.h>

void myswap(char* a, char* b){
	char t = 0;
	t = *a;
	*a = *b;
	*b = t;
}

//���ã�ֻ�ܽ�������ֵ�����ñ���
void myswap(char&a,char& b){
	char t = 0;
	t = a;
	a = b;
	b = t;
}

void main(){
	char a = 'a';
	char b = 'b';
	//myswap(&a,&b);
	myswap(a,b);
	printf("%c\t%c",a,b);
}
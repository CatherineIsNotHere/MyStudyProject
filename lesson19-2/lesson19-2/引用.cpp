#include <stdio.h>

void myswap(char* a, char* b){
	char t = 0;
	t = *a;
	*a = *b;
	*b = t;
}

//引用，只能将变量赋值给引用变量
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
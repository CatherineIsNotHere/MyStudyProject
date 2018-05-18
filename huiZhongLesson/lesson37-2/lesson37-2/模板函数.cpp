#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
bool isEqual(T a,T b){
	return a == b;
}

template<>//全局模板函数的特化
bool isEqual(char* a, char* b){//特化
	return !strcmp(a,b);
}

void main(){
	bool r1 = isEqual(10, 10);
	bool r2 = isEqual(10.1f, 10.1f);
	bool r3 = isEqual("abc","abc");
	system("pause");
}
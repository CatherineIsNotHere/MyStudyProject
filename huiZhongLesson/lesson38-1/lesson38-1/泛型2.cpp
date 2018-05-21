#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
class MyClass
{
public:
	bool isEqual(T a,T b){
		return a == b;
	}
private:

};

template<>
class MyClass<char*>
{
public:
	bool isEqual(char * a, char * b){
		return strcmp(a,b)==0;
	}
private:

};

void main(){
	MyClass<int> c;
	bool b = c.isEqual(100, 200);
	MyClass<char*> c2;
	char s[128] = {};
	strcpy_s(s,5,"char");
	char s2[128] = {};
	strcpy_s(s2,5,"char");
	b = c2.isEqual(s,s2);
	system("pause");
}
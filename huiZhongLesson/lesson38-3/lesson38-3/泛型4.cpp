#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
void Test(T a){
	cout << a << endl;
}

int mymax(int a,int b){
	return a > b ? a : b;
}

void main(){


	Test(mymax(100, 200));
	system("pause");
}
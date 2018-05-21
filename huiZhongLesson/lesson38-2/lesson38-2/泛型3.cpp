#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T1,class T2>
void Test(T1 a,T2 b){

}

template<class T1>//Æ«ÌØ»¯
void Test(T1 a, const char b){
	
}

void main(){
	Test<int, int>(100,200);
	Test<char, int>('c',200);
	Test(100,200);
	system("pause");
}
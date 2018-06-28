#include <iostream>
using namespace std;
#include "mylib.h"
#pragma comment(lib,"lesson46-1")


void main(){
	int c = myadd(10,20);
	cout << c << endl;
	getchar();
	MyClass mc;
	cout <<mc.myadd(20, 30)<<endl;
}
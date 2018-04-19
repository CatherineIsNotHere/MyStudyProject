//#include <stdio.h>
#include <iostream>
using namespace std;

void main(){
	char c1 = '\a';
	char TAB = '\t';
	//阵铃一声
	cout << c1 << endl;										//printf("%c\n", c1);
	//使用水平制表符
	cout << 1 << TAB << 2 << TAB << 3 << TAB << 4 << endl; //printf("1%c2%c3%c4\n",TAB,TAB,TAB );
	//使用双引号
	cout << "He said \"Thank you\"." << endl;				//printf("He said \"ThankYou\".\n");
	//使用回车换行
	cout << "abc\n" << "def" << '\n';						//printf("abc\ndef\n");
}
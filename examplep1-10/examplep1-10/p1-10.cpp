//#include <stdio.h>
#include <iostream>
using namespace std;

void main(){
	char c1 = '\a';
	char TAB = '\t';
	//����һ��
	cout << c1 << endl;										//printf("%c\n", c1);
	//ʹ��ˮƽ�Ʊ��
	cout << 1 << TAB << 2 << TAB << 3 << TAB << 4 << endl; //printf("1%c2%c3%c4\n",TAB,TAB,TAB );
	//ʹ��˫����
	cout << "He said \"Thank you\"." << endl;				//printf("He said \"ThankYou\".\n");
	//ʹ�ûس�����
	cout << "abc\n" << "def" << '\n';						//printf("abc\ndef\n");
}
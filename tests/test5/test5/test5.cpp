#include "iostream"
using namespace std;
/*
	ö�ٳ���
	enum�����������������
	
*/
void main(){
	enum COLOR{RED=2,BLUE=7,GREEN,WHITE=5,BLACK=10};
	cout << "REDΪ:" << RED << "\n" 
		<< "BLUEΪ:" << BLUE << "\n" 
		<< "GREENΪ:" << GREEN << "\n" 
		<< "WHITEΪ:" << WHITE << "\n" 
		<< "BLACKΪ:" << BLACK << "\n";
	COLOR a = BLUE;
	//�����������Ȼ������͸���ö�ٱ���
	cout << a;
}
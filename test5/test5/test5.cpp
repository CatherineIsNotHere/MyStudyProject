#include "iostream"
using namespace std;
/*
	枚举常量
	enum后跟类型名、花括号
	
*/
void main(){
	enum COLOR{RED=2,BLUE=7,GREEN,WHITE=5,BLACK=10};
	cout << "RED为:" << RED << "\n" 
		<< "BLUE为:" << BLUE << "\n" 
		<< "GREEN为:" << GREEN << "\n" 
		<< "WHITE为:" << WHITE << "\n" 
		<< "BLACK为:" << BLACK << "\n";
	COLOR a = BLUE;
	//不能用整数等基本类型赋给枚举变量
	cout << a;
}
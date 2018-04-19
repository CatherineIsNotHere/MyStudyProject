#include "iostream"
using namespace std;
/*
	定义一个常量（关键字const）常量定义时必须初始化
	#define 另一种定义常量的方法
*/
#define PI 3.1415926;//此时就是

void main(){
	const float pi = 3.1415926;
	//常量赋值是一个常量表达式，但不能含有某个函数
	/*
		const int size=100*sizeof(int) //OK
		const int number = max(12,23)  //error
	*/
	cout << PI;
}
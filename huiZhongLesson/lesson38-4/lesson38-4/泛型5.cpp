#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T1,class T2>
void Test(T1 a,T2 * p){
	cout << (p->*a)(100, 200) << endl;
}
//template<class T1>
//void Test(T1 a){
//	cout << a(100, 200) << endl;
//}
template<typename T,int n>
class MyArray
{
public:
	T _date[n];
	int mymax(int a,int b){
		return a > b ? a : b;
	}
};

void main(){
	MyArray<int, 10> arr;
	//类成员函数作为函数参数，需要额外的实例才行
	Test(&MyArray<int, 10>::mymax,&arr);
	//Test(arr.mymax);//函数调用缺少参数列表；请使用“&MyArray<int,10>::mymax”创建指向成员的指针 所以报错

	system("pause");
}
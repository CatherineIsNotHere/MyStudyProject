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
	//���Ա������Ϊ������������Ҫ�����ʵ������
	Test(&MyArray<int, 10>::mymax,&arr);
	//Test(arr.mymax);//��������ȱ�ٲ����б���ʹ�á�&MyArray<int,10>::mymax������ָ���Ա��ָ�� ���Ա���

	system("pause");
}
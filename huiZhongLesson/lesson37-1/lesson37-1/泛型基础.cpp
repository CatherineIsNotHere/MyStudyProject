#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

//int _max(int a,int b){
//	return a > b ? a : b;
//}
//float _max(float a,float b){
//	return a > b ? a : b;
//}

template<class T>//这是一个最基础的泛型比较法
T _max(T a, T b){
	return a > b ? a : b;
}

template<typename F=int,int n=2>//类型参数,非类型参数
class  CMyArray//模板类
{
public:
	CMyArray(){};
	~CMyArray(){};
	void PushBack(F data){
	};
	size_t Size(){ return 0; }//size_t正整数的意思unsigned int
	F operator[](size_t index){
		//return F(0);//构造一个F类型的参数为0的对象
		return _data[index];
	}
private:
	//F* _data;
	F _data[n];
};

class Item
{
public:
	Item(){
		a = 10;
	};
	Item(int a){
		a = a;
	}
	~Item(){};
	int a;
	char s[16];

};


void main(){
	//cout << _max(10, 20) << endl;
	//cout << _max(10.52f,12.53f) << endl;
	//cout << _max(20.2, 20.3) << endl;
	//cout << _max<float>(10, 20.5f) << endl;


	//CMyArray<int> narr;
	//narr.PushBack(100);
	//int n1 = narr[99];
	//CMyArray<double> narr2;
	//narr2.PushBack(100.123);
	//double n2 = narr2[99];
	//CMyArray<Item> itemarr;
	//Item c;
	//itemarr.PushBack(c);
	//Item c2 = itemarr[99];
	CMyArray<int, 10> narr3;
	narr3.PushBack(1000);
	int n3 = narr3[0];
	CMyArray<double> narr4;
	narr4.PushBack(1000);
	int n4 = narr4[0];

	CMyArray<Item, 3> itemarr;
	Item c;
	itemarr.PushBack(c);
	Item c2 = itemarr[0];

	CMyArray<> arr;
	system("pause");
}



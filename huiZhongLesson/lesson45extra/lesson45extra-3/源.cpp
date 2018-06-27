#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

void main(){
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	
	{
	//无函数对象参数，【】无内容，输出1,2
		for_each(vec.begin(), vec.end(), [](int v){cout << v << endl; });
	}
	cout << "--------------" << endl;
	{
	//以值传递的方式将作用域内变量
		int a = 10;
		for_each(vec.begin(), vec.end(), [=](int v){cout << v + a << endl;  });
	}
	cout << "--------------" << endl;
	{
		//引用方式传递作用域内的局部变量
		int a = 10;
		for_each(vec.begin(), vec.end(), [&](int v){cout << v + a << endl; a++; });
		cout << a << endl;
	}
	cout << "--------------" << endl;
	{
		int a = 10;
		for_each(vec.begin(), vec.end(), [a](int v)mutable{cout << v + a << endl; a++; });
		cout << a << endl;
	}
	cout << "--------------" << endl;
	{
		//引用方式传递作用域内的局部变量
		int a = 10;
		for_each(vec.begin(), vec.end(), [&a](int v){cout << v + a << endl; a++; });
		cout << a << endl;
	}
	cout << "--------------" << endl;
	{
		//b是引用，其余是值传递
		int a = 10;
		int b = 20;
		for_each(vec.begin(), vec.end(), [=,&b](int v){cout << v + a << endl; b++; });
		cout << b << endl;
	}
	{
		[](){}();
		[]{}();//空lambda
	}
	getchar();
}

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
	//�޺���������������������ݣ����1,2
		for_each(vec.begin(), vec.end(), [](int v){cout << v << endl; });
	}
	cout << "--------------" << endl;
	{
	//��ֵ���ݵķ�ʽ���������ڱ���
		int a = 10;
		for_each(vec.begin(), vec.end(), [=](int v){cout << v + a << endl;  });
	}
	cout << "--------------" << endl;
	{
		//���÷�ʽ�����������ڵľֲ�����
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
		//���÷�ʽ�����������ڵľֲ�����
		int a = 10;
		for_each(vec.begin(), vec.end(), [&a](int v){cout << v + a << endl; a++; });
		cout << a << endl;
	}
	cout << "--------------" << endl;
	{
		//b�����ã�������ֵ����
		int a = 10;
		int b = 20;
		for_each(vec.begin(), vec.end(), [=,&b](int v){cout << v + a << endl; b++; });
		cout << b << endl;
	}
	{
		[](){}();
		[]{}();//��lambda
	}
	getchar();
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void P(string s){
	cout << s << endl;
}

class P2
{
public:
	void operator()(string s){
		cout << s << endl;
	}
};

class P3
{
public:
	P3(int n)
		:nn(n)
	{
	}

	int nn;
	void operator()(string s){
		for (int i = 0; i < nn; i++)
		{
			cout << s << endl;
		}
	}
};

void main(){
	vector<string> vec;
	vec.push_back("AAA");
	vec.push_back("BBB");
	vec.push_back("CCC");
	//for_each(vec.begin(),vec.end(),P);//函数指针的形式
	for_each(vec.begin(), vec.end(), P2());//P2::operator() 无参的构造，仿函数形式
	for_each(vec.begin(), vec.end(), P3(3));
}
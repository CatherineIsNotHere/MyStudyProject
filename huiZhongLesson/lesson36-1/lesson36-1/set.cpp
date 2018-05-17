#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <iostream>
using namespace std;

class Person{
public:
	Person(string n,int a)
		:name(n)
		, a(a)
	{
	
	}
	string name;
	int a;
};

class comparesPerson{//仿函数

public:
	bool operator()(const Person& p1,const Person& p2){
		if (p1.name==p2.name){
			return p1.a > p2.a;
		}
		return p1.name > p2.name;
	}
};

//class compareSet{
//public:
//	bool operator()(int v1, int v2){
//		return v1 > v2;
//	}
//
//};

void main(){

	//set<int,compareSet> s;
	//s.insert(5);
	//s.insert(1);
	//s.insert(6);
	//s.insert(3);
	//s.insert(5);
	//pair<set<int>::iterator, bool> r = s.insert(5);//插入算法通常都是返回一个迭代器和一个bool值
	//for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	Person p1("zhangsan",10);
	Person p2("lisi", 10);
	Person p3("wangwu", 10);
	set<Person, comparesPerson> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	system("pause");

}
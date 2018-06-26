#include <stdio.h>
#include <string.h>
#include <vector>
#include <windows.h>
int fun(){
	return 0;
}

template<typename T1,typename T2>
auto mutiply(T1 x,T2 y)->decltype(x*y){//泛型结合decltype推到auto类型
	return x*y;
}

void main(){
	auto a=mutiply(10, 20);
	Sleep(100);
	{
		int x = 0;
		decltype(fun()) sum = x;
		int i = 0;
		decltype(i) j = 3;
	}
	{
		const int i = 3;
		decltype(i) j = i;
	}
	{
		const int i = 3, &j = i;
		decltype(j) k = 5;
	}
	{
		int i = 3, &r = i;
		decltype(r + 100) t = 6;
	}
	{
		//对指针的解引用，返回的类型是引用类型
		int i = 3, j = 6, *p = &i;
		decltype(*p) c = j;
	}
	{
		//如果表达式不是引用，但我们需要引用类型，那么加一对小括号，就变成了引用
		int i = 3;
		decltype((i)) j = i;
	}
	{
		size_t c = sizeof(int);
		using mysize_t = decltype(sizeof(0));
		mysize_t c2 = sizeof(int);
	}
	{
		//与using和tyoedef联用，用于类型定义
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){

		}
		for (auto v : vec){

		}
		typedef decltype(vec.begin()) ittype;
		for (ittype i = vec.begin(); i != vec.end(); i++)
		{

		}
	}
	{
		struct{
			int a;
			double b;
		}aaa;
		decltype(aaa) bbb;
		//借助decltype,可以重新使用匿名结构与匿名类，创建变量
	}
}
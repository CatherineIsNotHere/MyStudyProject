#include<stdio.h>
#include<stdlib.h>
class Myclass{
public:
	Myclass()
		:m_nData(10)
		, m_fData(123)
	{

	}
	void Test() const{//表明函数中不可以修改任何变量值
		//m_fData = 456;
	}
	void Test1(const char pname){//表示函数中不可以修改变量值
		//pname = "aaa";
	}
	void Test1(int* const pname){//指针常量：值是指针，这个值因为是常量，所以不能被赋值。
		//pname = &m_fData;//地址不可以修改，值可以
		*pname = 2;
	}
	void Test2(const int* pname){//常量指针：本质是指针，常量修饰它，表示这个指针乃是一个指向常量的指针（变量）.
		pname = &m_fData;//地址可以修改，值不行
		//*pname = 2;
	}
	void Test3(const int* const pname){//表示函数中不可以修改变量值地址，也不可以修改变量值
		//pname = &m_fData;
		//*pname = 2;
	}

	~Myclass(){

	}

	const int m_nData;//修饰变量表示不能修改值
	int m_fData;

};

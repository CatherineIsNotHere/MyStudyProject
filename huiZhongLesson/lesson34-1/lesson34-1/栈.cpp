#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Student{
public:
	int age;
	string name;

};

void main(){
	stack<Student*> ss;
	Student* s1 = new Student;
	s1->age = 20;
	s1->name = "张三";
	Student* s2 = new Student;
	s2->age = 30;
	s2->name = "李四";
	Student* s3 = new Student;
	s3->age = 10;
	s3->name = "王五";
	ss.push(s1);
	ss.push(s2);
	ss.push(s3);
	while (!ss.empty()){//判断是否为空
		Student* p=ss.top();//获取栈顶元素
		cout << p->name << "," <<p->age << endl;
		ss.pop();
	}

}
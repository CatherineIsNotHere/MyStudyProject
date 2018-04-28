#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Student{
	public:
		int age;
		char* name;
		float height;
		Student(int a,float h,char* pname){
			age = a;
			height = h;
			name = new char[strlen(pname) + 1];
			strcpy_s(name, strlen(pname) + 1,pname);
		}
		Student(const Student& right){
			printf("¿½±´¹¹Ôì");
			this->age = right.age;
			this->height = right.height;
			this->name = new char[strlen(right.name) + 1];//Éî¿½±´
			strcpy_s(this->name, strlen(right.name) + 1, right.name);
		}
		~Student(){
			delete[] name;
			name = nullptr;
		}
};


void main(){
	Student a(19,30,"aaa");
	Student b(a);


	system("pause");

}
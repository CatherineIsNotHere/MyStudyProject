#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class student{
public:
	char name[32];
	int age;
	float height;
	void init(){//类的成员函数在编译的时候并不在类里，会放在全局函数编译，所以如果sizeof(s)则值为44
		this->age = 0;
		this->height = 0;
		strcpy_s(this->name, 33, "");
	}
	void setWidth(int width){
		this->width = width;
	}
private:
	int width;
};

void main(){
	student s;
	s.init();
	system("pause");
}
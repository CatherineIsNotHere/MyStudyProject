#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class student{
public:
	char name[32];
	int age;
	float height;
	void init(){//��ĳ�Ա�����ڱ����ʱ�򲢲�����������ȫ�ֺ������룬�������sizeof(s)��ֵΪ44
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
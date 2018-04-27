#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class cRectangle{

public:
	int width;
	int height;
	char* pname;

	cRectangle(){
		width = 10;
		height = 20;
	}

	cRectangle(int w, int h,char* name){
		width = w;
		height = h;
		int s=strlen(name);
		pname = new char[s];
		strcpy_s(pname,s+1,name);//�ڶ�������ָ������Ϊ�ַ�����С��1
		
	}
	/*
	�������� �����������������и���Ŀ�����Ķ���ȫ�������

	����������ִ�������Ĵ���λ�����
	1������������Ϊȫ�ֱ����������������˳�ʱ�������������Żᱻ���á�
	2������������Ϊ�Զ��洢����(�ֲ�����)�������������ڽ���������������ִ�����ʱ�������������ᱻ���á�
	3������������Ϊָ�����(ʹ��new��������)����ִ�е�delete����ʱ�������������ᱻ���á�
	4����ʱ�������ֶ�������ʱ�����������ʱ�Զ�����������������
	*/
	~cRectangle(){
		delete[] pname;
		pname = nullptr;
	}

	int getarea(){
		return width*height;
	}

	int perimeter(){
		return 2 * (width + height);
	}
};

void main(){
	cRectangle r(2,20,"abc");
	int a = r.getarea();


	system("pause");

}
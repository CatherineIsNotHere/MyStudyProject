#include "stdio.h"
#include "stdlib.h"

void main(){
	errno_t err = -1;
	FILE* file = nullptr;
	err = fopen_s(&file, "c:\\preview.jpg", "rb");

	if (file){
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		fseek(file, 0, SEEK_SET);
		char* pbuf = new char[size];
		//1.��ȡ�������ַ
		//2.��ȡ�������ʹ�СintΪ4charΪ1
		//3.��ȡ����ֻҪ�ڶ��������͵�����������˵����ļ���С����
		//4.��ȡĿ���ļ�
		fread(pbuf,1,size,file);

		delete[] pbuf;
		pbuf = nullptr;
		fclose(file);

		system("pause");
	}

}
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
		//1.读取的最初地址
		//2.读取数据类型大小int为4char为1
		//3.读取几个只要第二个参数和第三个参数相乘等于文件大小即可
		//4.读取目标文件
		fread(pbuf,1,size,file);

		delete[] pbuf;
		pbuf = nullptr;
		fclose(file);

		system("pause");
	}

}
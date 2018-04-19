#include "stdio.h"

void main(){
	struct data{
		char name[9];//9字节
		int d1;//4字节
		int d2;//4字节
	};
	data d;
	printf("%d",sizeof(d));//20字节，cpu会4字节4字节的读取，不够4字节会自动补齐
}